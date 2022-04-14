#include "SqList.h"


// 有序列表合并
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
		// 如果ck取较小者
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

	// 如果La还有剩余
	while (i <= La_len) {
		GetSqElem(La, i++, &ai);
		SqListInsert(Lc, ++k, ai);
	}

	// 如果Lb还有剩余
	while (j <= Lb_len) {
		GetSqElem(Lb, j++, &bj);
		SqListInsert(Lc, ++k, bj);
	}
}


// 有序列表合并
void MergeSqList_2(SqList La, SqList Lb, SqList* Lc) {
	ElemType* pa, * pb, * pc;
	ElemType* pa_last, * pb_last;

	// 获取La和Lb的头元素
	pa = La.elem;
	pb = Lb.elem;

	// 直接分配，不调用InitListSq
	Lc->listsize = Lc->length = La.length + Lb.length;
	pc = Lc->elem = (ElemType*)malloc(Lc->listsize * sizeof(ElemType));
	if (!Lc->elem) {
		exit(OVERFLOW); // 内存分配失败
	}

	// 获取La和Lb的最后一个元素
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

	// La还有剩余
	while (pa <= pa_last) {
		*pc++ = *pa++;
	}

	// Lb还有剩余
	while (pb <= pb_last) {
		*pc++ = *pb++;
	}
}