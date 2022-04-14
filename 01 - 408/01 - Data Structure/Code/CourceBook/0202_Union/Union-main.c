#include "Union.h"

void PrintElem(ElemType e) {
	printf("%d ", e);
}


int main(int arg, char** argv) {
	ElemType a[4] = { 3, 5 , 8, 11 };
	ElemType b[7] = { 2, 6, 8, 9, 11, 15, 20 };
	SqList La, Lb;
	int i;
	// ��ʼ��La
	InitListSq(&La);
	for (i = 0; i < 4; i++) {
		SqListInsert(&La, i + 1, a[i]);
	}

	// ��ʼ��La
	InitListSq(&Lb);
	for (i = 0; i < 7; i++) {
		SqListInsert(&Lb, i + 1, b[i]);
	}

	// ����La
	printf("La = ");
	SqListTraverse(La, PrintElem);
	// ����Lb
	printf("\nLb = ");
	SqListTraverse(Lb, PrintElem);
	// �����ϲ����La
	Union(&La, Lb);
	printf("\nnew La = ");
	SqListTraverse(La, PrintElem);
	return 0;
}