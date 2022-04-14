#include "LinkList.h"

// e1是否大于e2
Status CmpGreater(ElemType e1, ElemType e2) {
	return e1 > e2 ? TRUE : FALSE;
}

// 打印元素
void PrintElem(ElemType e) {
	printf("%d ", e);
}


int main(int argc, char** argv) {
	LinkList L;
	int i;
	ElemType e;

	// 初始化测试
	printf("初始化...\n");
	InitListLk(&L);

	// 判空测试
	printf("L是否为空?%d\n", LkListEmpty(L));

	// 插入测试
	for (i = 1; i < 13; i++) {
		LkListInsert(L, i, i * i);
	}
	printf("L = ");
	LkListTraverse(L, PrintElem);

	// 链表长度测试
	printf("\n链表长度:%d\n", LkListLength(L));

	// 获取元素测试
	GetLkElem(L, 3, &e);
	printf("第%d个元素是%d\n", 3, e);

	// compare测试
	printf("第一个比%d大的位置是%d\n", 99, LocateLkElem(L, 99, CmpGreater));

	// 前驱测试
	PriorLkElem(L, 100, &e);
	printf("%d的前驱是%d\n", 100, e);
	PriorLkElem(L, 1, &e);
	printf("%d的前驱是%d\n", 1, e);   // 第一个没有前驱
	PriorLkElem(L, 33, &e);
	printf("%d的前驱是%d\n", 33, e);  // 没有,e不发生改变

	// 后继测试
	NextLkElem(L, 100, &e);
	printf("%d的后继是%d\n", 100, e);
	NextLkElem(L, 144, &e);
	printf("%d的后继是%d\n", 144, e); // 最后一个没有后继
	NextLkElem(L, 33, &e);
	printf("%d的后继是%d\n", 33, e); // 不存在，e不发生改变

	// 删除测试
	LkListDelete(L, 3, &e);
	printf("删除了第%d个位置的%d\n", 3, e);
	printf("L = ");
	LkListTraverse(L, PrintElem);

	// 置空测试
	printf("\nL是否为空?%d\n", LkListEmpty(L));
	ClearListLk(L);
	printf("L是否为空?%d\n", LkListEmpty(L));

	// 头插法测试
	LinkList h;
	CreateLsitLk_Head(&h, 6, "head.txt");
	printf("h = ");
	LkListTraverse(h, PrintElem);

	// 尾插法测试
	LinkList t;
	CreateListLk_Tail(&t, 6, "tail.txt");
	printf("\nt = ");
	LkListTraverse(t, PrintElem);
	return 0;
}