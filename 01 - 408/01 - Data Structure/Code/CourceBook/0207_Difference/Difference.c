#include "Difference.h"

Status Equal(ElemType e1, ElemType e2) {
	return e1 == e2 ? TRUE : FALSE;
}

// 求(A-B)U(B-A)
void Difference(SLinkList space, int* S, int* a, int a_len, int* b, int b_len) {  // 直接测试
	InitSpace(space);
	*S = Malloc(space);

	int R;      // 静态链表最后的节点
	int i;
	int index;  // 分配节点
	int p, k;      // 用于查找

	R = *S;

	for (i = 0; i < a_len; i++) {
		index = Malloc(space);
		space[index].data = a[i];
		space[R].cur = index;
		R = index;
	}
	// 尾结点指针赋空
	space[R].cur = 0;
	for (i = 0; i < b_len; i++) {
		p = *S;
		k = space[*S].cur;    // 集合A中第一个元素

		// 没有就后移
		while (k != space[R].cur && space[k].data != b[i]) {
			p = k;
			k = space[k].cur;
		}

		// A表中不存在b[i]
		if (k == space[R].cur) {
			index = Malloc(space);
			space[index].data = b[i];
			space[index].cur = space[R].cur;
			space[R].cur = index;
		}   else { // A中存在b[i]
			space[p].cur = space[k].cur;
			Free(space, k);
			if (R == k) { //  若R所指的节点被删除了，需要指向前一个
				R = p;
			}
		}
	}
}  