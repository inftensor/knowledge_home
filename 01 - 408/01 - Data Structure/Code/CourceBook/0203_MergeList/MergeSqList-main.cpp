#include "MergeSqList.h"


// 遍历元素
void PrintElem(ElemType e) {
	printf("%d", e);
}

int main(int arg, char** argv) {
	int a[4] = { 3,5,8,11 };
	int b[7] = { 2,6,8,9,11,15,20 };
	SqList La, Lb, Lc1;
	int i;
	// 初始化La
	InitListSq(&La);
	//for (i = 0; i < 4; i++) {
	//	SqListInsert(&La, i + 1, a[i]);
	//}
	//// 初始化Lb
	//InitListSq(&Lb);
	//for (i = 0; i < 7; i++) {
	//	SqListInsert(&Lb, i + 1, b[i]);
	//}
	//// 合并
	//MergeSqList_1(La, Lb, &Lc1);
	//
	//// 检测
	//printf("La = ");
	//SqListTraverse(La, PrintElem);
	//printf("\nLb = ");
	//SqListTraverse(Lb, PrintElem);

	return 0;
}