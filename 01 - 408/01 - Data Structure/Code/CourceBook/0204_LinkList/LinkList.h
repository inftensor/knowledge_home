#ifndef LINKLIST_H
#define LINKLIST_H

//#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Status.h"

// 定义基本元素
typedef int ElemType;

typedef struct LNode{
	ElemType        data;   // 数据节点
	struct LNode*   next;   // 下一个节点的指针
}LNode, *LinkList;


//typedef LNode* LinkList;

// 初始化链表
Status InitListLk(LinkList* L);

// 销毁链表
Status DestroyListLk(LinkList* L);

// 置空链表
Status ClearListLk(LinkList L);

// 链表判空
Status LkListEmpty(LinkList L);

// 链表长度
int LkListLength(LinkList L);

// 获取链表第i个元素,并存储到到e中
Status GetLkElem(LinkList L, int i, ElemType* e);

// 返回链表中首个与e满足compare的元素
int LocateLkElem(LinkList L, ElemType e, Status(Compare)(ElemType e1, ElemType e2));

// 链表前驱
Status PriorLkElem(LinkList L, ElemType cur_e, ElemType* pre_e);

// 链表后继
Status NextLkElem(LinkList L, ElemType cur_e, ElemType* next_e);

// 链表插入
Status LkListInsert(LinkList L, int i, ElemType e);

// 链表删除
Status LkListDelete(LinkList L, int i, ElemType* e);

// 链表遍历
void LkListTraverse(LinkList L, void(Visit)(ElemType));

// 头插法，需逆序输入
Status CreateLsitLk_Head(LinkList* L, int n, char* path);

// 尾插法
Status CreateListLk_Tail(LinkList* L, int n, char* path);

#endif // !LINKLIST_H
