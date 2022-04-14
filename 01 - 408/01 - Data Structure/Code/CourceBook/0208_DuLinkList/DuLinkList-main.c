#include "DuLinkList.h"

// e1是否大于e2
Status CmpGreater(ElemType e1, ElemType e2) {
	return e1 > e2 ? TRUE : FALSE;
}

// 打印元素
void PrintElem(ElemType e) {
	printf("%d ", e);
}


int main(int argc, char** argv) {
	DuLinkList L;
	int i;
	ElemType e;

	// 初始化测试
	printf("初始化...\n");
	InitDuLinkList(&L);

	// 判空测试
	printf("L是否为空?%d\n", DuLinkListEmpty(L));

	// 插入测试
	for (i = 1; i < 13; i++) {
		DuLinkListInsert(L, i, i * i);
	}
	printf("L = ");
	DuLinkListTraverse(L, PrintElem);

	// 链表长度测试
	printf("链表长度:%d\n", DuLinkListLength(L));

	// 获取元素测试
	GetDuLinkListElem(L, 3, &e);
	printf("第%d个元素是%d\n", 3, e);

	// compare测试
	printf("第一个比%d大的位置是%d\n", 99, LocateDuLinkListElem(L, 99, CmpGreater));

	// 前驱测试
	PriorDuLinkListElem(L, 100, &e);
	printf("%d的前驱是%d\n", 100, e);
	PriorDuLinkListElem(L, 1, &e);
	printf("%d的前驱是%d\n", 1, e);   // 第一个没有前驱
	PriorDuLinkListElem(L, 33, &e);
	printf("%d的前驱是%d\n", 33, e);  // 没有,e不发生改变

	// 后继测试
	NextDuLinkListElem(L, 100, &e);
	printf("%d的后继是%d\n", 100, e);
	NextDuLinkListElem(L, 144, &e);
	printf("%d的后继是%d\n", 144, e); // 最后一个没有后继
	NextDuLinkListElem(L, 33, &e);
	printf("%d的后继是%d\n", 33, e); // 不存在，e不发生改变

	// 删除测试
	DuLinkListDelete(L, 3, &e);
	printf("删除了第%d个位置的%d\n", 3, e);
	printf("L = ");
	DuLinkListTraverse(L, PrintElem);

	// 置空测试
	printf("\nL是否为空?%d\n", DuLinkListEmpty(L));
	ClearDuLinkList(L);
	printf("L是否为空?%d\n", DuLinkListEmpty(L));
}