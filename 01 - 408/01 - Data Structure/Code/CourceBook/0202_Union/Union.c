#include "Union.h"


// ���Ա��󲢼�
void Union(SqList* La, SqList Lb) {
	int La_len, Lb_len;
	int i;
	ElemType e;

	La_len = SqListLength(*La);
	Lb_len = SqListLength(Lb);

	for (i = 1; i <= Lb_len; i++) {
		GetSqElem(Lb, i, &e);
		if (!LocateSqElem(*La, e, equal)) {
			// �����ʱ���뵽La
			SqListInsert(La, ++La_len, e);
		}
	}
}

// �ж�Ԫ���Ƿ����
Status equal(ElemType e1, ElemType e2) {
	return e1 == e2 ? TRUE : FALSE;
}


