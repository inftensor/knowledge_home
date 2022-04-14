#include "MergeLkList.h"


// ��ӡԪ������
void PrintElem(ElemType e) {
	printf("%d ", e);
}

int main(int argc, char** argv) {
	LinkList La, Lb, Lc;

	// ��β�巨��������
	CreateListLk_Tail(&La, 4, "La_Tail.txt");
	CreateListLk_Tail(&Lb, 7, "Lb_Tail.txt");


	printf("La = ");
	LkListTraverse(La, PrintElem);
	printf("\nLb = ");
	LkListTraverse(Lb, PrintElem);

	// ���Թ鲢
	MergeLkList(&La, &Lb, &Lc);
	printf("\nLc = ");
	LkListTraverse(Lc, PrintElem);
}