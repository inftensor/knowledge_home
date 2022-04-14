#include "SLinkList.h"

// e1是否大于e2
Status CmpGreater(ElemType e1, ElemType e2) {
	return e1 > e2 ? TRUE : FALSE;
}

// 打印元素
void PrintElem(ElemType e) {
	printf("%d ", e);
}


int main(int argc, char** argv) {
	SLinkList space;
	int i;
	ElemType e;
	int S;
	// 初始化测试
	InitSLinkList(space, &S);
	// 插入测试
	for (i = 1; i < 14; i++) {
		SLinkListInsert(space, S, i, i*i);
	}
	printf("链表 = ");
	SLinkListTraverse(space, S, PrintElem);
	
	// 判空吃啥
	printf("\n链表是否为空%d\n", SLinkListEmpy(space, S));

	// 长度测试
	printf("链表长度%d\n", SLinkListLength(space, S));

	// 取数测试
	GetSLinkElem(space, S, 3, &e);
	printf("链表的第%d个元素是%d\n", 3, e);
	GetSLinkElem(space, S, -1, &e);
	printf("链表的第%d个元素是%d\n", -1, e);

	// Compare测试
	printf("第一个大于%d的数的位置为%d\n", 99, LocateSLElem(space, S, 99, CmpGreater));
	printf("第一个大于%d的数的位置为%d\n", 200, LocateSLElem(space, S, 200, CmpGreater));
	
	// 前驱测试
	PriorSLElem(space, S, 100, &e);
	printf("%d的前驱为%d\n", 100, e);
	PriorSLElem(space, S, 33, &e);
	printf("%d的前驱为%d\n", 33, e);

	// 后继测试
	NextSLElem(space, S, 100, &e);
	printf("%d的后继为%d\n", 100, e);
	NextSLElem(space, S, 99, &e);
	printf("%d的后继为%d\n", 99, e);

	// 删除测试
	SLinkListDelete(space, S, 3, &e);
	printf("删除第%d个数%d后\n", 3, e);
	printf("链表为:");
	SLinkListTraverse(space, S, PrintElem);

	// 销毁测试
	ClearSLinkList(space, S);
	printf("\n是否为空?%d\n", SLinkListEmpy(space, S));
}