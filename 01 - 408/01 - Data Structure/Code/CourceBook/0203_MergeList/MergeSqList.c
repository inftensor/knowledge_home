#include "SqList.h"


// �����б�ϲ�
void MergeSqList_1(SqList La, SqList Lb, SqList* Lc) {
	int La_len, Lb_len;
	int i,j,k;
	ElemType ai, bj;

	InitListSq(Lc);
	i = j = 1;
	k = 0;

	La_len = SqListLength(La);
	Lb_len = SqListLength(Lb);
	
	while (i <= La_len && j <= Lb_len) {
		// ���ckȡ��С��
		GetSqElem(La, i, &ai);
		GetSqElem(Lb, j, &bj);

		if (ai > bj) {
			SqListInsert(Lc, ++k, bj);
			j++;
		} else {
			SqListInsert(Lc, ++k, ai);
			i++;
		}
	}

	// ���La����ʣ��
	while (i <= La_len) {
		GetSqElem(La, i++, &ai);
		SqListInsert(Lc, ++k, ai);
	}

	// ���Lb����ʣ��
	while (j <= Lb_len) {
		GetSqElem(Lb, j++, &bj);
		SqListInsert(Lc, ++k, bj);
	}
}


// �����б�ϲ�
void MergeSqList_2(SqList La, SqList Lb, SqList* Lc) {
	ElemType* pa, * pb, * pc;
	ElemType* pa_last, * pb_last;

	// ��ȡLa��Lb��ͷԪ��
	pa = La.elem;
	pb = Lb.elem;

	// ֱ�ӷ��䣬������InitListSq
	Lc->listsize = Lc->length = La.length + Lb.length;
	pc = Lc->elem = (ElemType*)malloc(Lc->listsize * sizeof(ElemType));
	if (!Lc->elem) {
		exit(OVERFLOW); // �ڴ����ʧ��
	}

	// ��ȡLa��Lb�����һ��Ԫ��
	pa_last = La.elem + La.length - 1;
	pb_last = Lb.elem + Lb.length - 1;

	while (pa <= pa_last && pb <= pb_last) {
		if (*pa <= *pb) {
			*pc++ = *pa++;
		}
		else {
			*pc++ = *pb++;
		}
	}

	// La����ʣ��
	while (pa <= pa_last) {
		*pc++ = *pa++;
	}

	// Lb����ʣ��
	while (pb <= pb_last) {
		*pc++ = *pb++;
	}
}