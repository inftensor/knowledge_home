#include "MergeLkList.h"


// 打印元素数据
void PrintElem(ElemType e) {
	printf("%d ", e);
}

int main(int argc, char** argv) {
	LinkList La, Lb, Lc;

	// 用尾插法构造链表
	CreateListLk_Tail(&La, 4, "La_Tail.txt");
	CreateListLk_Tail(&Lb, 7, "Lb_Tail.txt");


	printf("La = ");
	LkListTraverse(La, PrintElem);
	printf("\nLb = ");
	LkListTraverse(Lb, PrintElem);

	// 测试归并
	MergeLkList(&La, &Lb, &Lc);
	printf("\nLc = ");
	LkListTraverse(Lc, PrintElem);
}