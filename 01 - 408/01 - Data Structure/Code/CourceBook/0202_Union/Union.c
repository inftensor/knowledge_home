#include "Union.h"


// 线性表求并集
void Union(SqList* La, SqList Lb) {
	int La_len, Lb_len;
	int i;
	ElemType e;

	La_len = SqListLength(*La);
	Lb_len = SqListLength(Lb);

	for (i = 1; i <= Lb_len; i++) {
		GetSqElem(Lb, i, &e);
		if (!LocateSqElem(*La, e, equal)) {
			// 不相等时插入到La
			SqListInsert(La, ++La_len, e);
		}
	}
}

// 判断元素是否相等
Status equal(ElemType e1, ElemType e2) {
	return e1 == e2 ? TRUE : FALSE;
}


