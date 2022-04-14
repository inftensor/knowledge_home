#include "Difference.h"

Status Equal(ElemType e1, ElemType e2) {
	return e1 == e2 ? TRUE : FALSE;
}

// ��(A-B)U(B-A)
void Difference(SLinkList space, int* S, int* a, int a_len, int* b, int b_len) {  // ֱ�Ӳ���
	InitSpace(space);
	*S = Malloc(space);

	int R;      // ��̬�������Ľڵ�
	int i;
	int index;  // ����ڵ�
	int p, k;      // ���ڲ���

	R = *S;

	for (i = 0; i < a_len; i++) {
		index = Malloc(space);
		space[index].data = a[i];
		space[R].cur = index;
		R = index;
	}
	// β���ָ�븳��
	space[R].cur = 0;
	for (i = 0; i < b_len; i++) {
		p = *S;
		k = space[*S].cur;    // ����A�е�һ��Ԫ��

		// û�оͺ���
		while (k != space[R].cur && space[k].data != b[i]) {
			p = k;
			k = space[k].cur;
		}

		// A���в�����b[i]
		if (k == space[R].cur) {
			index = Malloc(space);
			space[index].data = b[i];
			space[index].cur = space[R].cur;
			space[R].cur = index;
		}   else { // A�д���b[i]
			space[p].cur = space[k].cur;
			Free(space, k);
			if (R == k) { //  ��R��ָ�Ľڵ㱻ɾ���ˣ���Ҫָ��ǰһ��
				R = p;
			}
		}
	}
}  