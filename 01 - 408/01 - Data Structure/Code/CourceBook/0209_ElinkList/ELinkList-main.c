#include "ELinkList.h"

// e1是否大于e2
Status CmpGreater(ElemType e1, ElemType e2) {
	return e1 > e2 ? TRUE : FALSE;
}

// 打印元素
void PrintElem(ElemType e) {
	printf("%d ", e);
}


int main(int argc, char** argv) {
	ELink p;
	ELinkList L;
	int i;
	ElemType e;
	EPosition pos;

	// 初始化测试
	printf("初始化...\n");
	InitELinkList(&L);

	// 判空测试
	printf("L是否为空?%d\n", ELinkListEmpty(L));

	// 插入测试
	for (i = 1; i < 13; i++) {
		ELinkListInsert(&L, i, i * i);
	}
	printf("L = ");
	ELinkListTraverse(L, PrintElem);

	// 链表长度测试
	printf("链表长度:%d\n", ELinkListLength(L));

	// 获取元素测试
	ELinkListLocatePos(L, 3, &p);
	printf("第%d个元素是%d\n", 3, GetELinkListCurElem(p));

	// compare测试
	printf("第一个比%d大的元素是%d\n", 99, GetELinkListCurElem(ELinkListLocate(L, 99, CmpGreater)));

	// 前驱测试
	printf("%d的前驱是%d\n", GetELinkListCurElem(p), GetELinkListCurElem(ELinkListPriorPos(L, p)));


	//// 后继测试
	printf("%d的后继是%d\n", GetELinkListCurElem(p), GetELinkListCurElem(ELinkListNextPos(L, p)));

	// 删除测试
	ELinkListDelete(&L, 3, &e);
	printf("删除了第%d个位置的%d\n", 3, e);
	printf("L = ");
	ELinkListTraverse(L, PrintElem);

	// 尾结点测试
	pos = GetElinkListTail(L);
	printf("尾结点为%d\n", pos->data);

	// 前驱测试
	printf("%d的前驱是%d\n", pos->data, ELinkListPriorPos(L, pos)->data);

	pos = L.head->next;
	// 后继测试
	printf("%d的后继是%d\n", pos->data, ELinkListNextPos(L, pos)->data);
	// 置空测试
	printf("\nL是否为空?%d\n", ELinkListEmpty(L));
	ClearELinkList(&L);
	printf("L是否为空?%d\n", ELinkListEmpty(L));
}
