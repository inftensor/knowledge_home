#include "MergeELinkList.h"


// 打印元素
void PrintElem(ElemType e) {
	printf("%d ", e);
}

// 比较两数大小
int Cmp(ElemType e1, ElemType e2) {
	return e1 - e2;
}


int main(int argc, char** argv) {
	ELinkList La, Lb, Lc;
	int i;


	int a[4] = {3, 5, 8, 11};
	int b[7] = { 2, 6, 8, 9, 11, 15, 20 };
	
	// 初始化La
	InitELinkList(&La);
	for (i = 0; i < 4; i++) {
		ELinkListInsert(&La, i + 1, a[i]);
	}
	// 初始化Lb
	InitELinkList(&Lb);
	for (i = 0; i < 7; i++) {
		ELinkListInsert(&Lb, i + 1, b[i]);
	}

	printf("La = ");
	ELinkListTraverse(La, PrintElem);
	printf("Lb = ");
	ELinkListTraverse(Lb, PrintElem);

	// 归并
	MergeElinkList(&La, &Lb, &Lc, Cmp);
	printf("Lc = ");
	ELinkListTraverse(Lc, PrintElem);
	
	return 0;
}