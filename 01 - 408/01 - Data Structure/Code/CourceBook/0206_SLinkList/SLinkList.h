#ifndef LKLINKLIST_H
#define LKLINKLIST_H

#include "Status.h"

#define MAXSIZE   1000 // 静态链表的最大长度

typedef int ElemType;  // 基础元素类型

typedef struct SLinkNode{
	ElemType   data;  
	int        cur;   // 游标,做指针用，来连接下一个节点
} SLinkList[MAXSIZE];

// 初始化备用表
void InitSpace(SLinkList space);

// 申请空间
int Malloc(SLinkList space);

// 回收空间
void Free(SLinkList space, int k);

/*----------静态链表操作----------*/

// 静态链表初始化
Status InitSLinkList(SLinkList space, int* S);

// 销毁静态链表
Status DestroySLinkList(SLinkList space, int* S);

// 释放非头结点的空间
Status ClearSLinkList(SLinkList space, int S);

// 判空
Status SLinkListEmpy(SLinkList space, int S);

// 静态链表长度
int SLinkListLength(SLinkList space, int S);

// 获取第i个元素,存储到e
Status GetSLinkElem(SLinkList space, int S, int i, ElemType* e);

// 返回静态链表中首个和e满足Compare关系的元素位置
int LocateSLElem(SLinkList space, int S, ElemType e, Status(Compare)(ElemType e1, ElemType e2));

// 静态链表前驱
Status PriorSLElem(SLinkList space, int S, ElemType cur_e, ElemType* pre_e);

// 静态链表后继
Status NextSLElem(SLinkList space, int S, ElemType cur_e, ElemType* next_e);

// 静态链表插入
Status SLinkListInsert(SLinkList space, int S, int i, ElemType e);

// 静态链表删除
Status SLinkListDelete(SLinkList space, int S, int i, ElemType* e);

// 遍历静态链表
Status SLinkListTraverse(SLinkList space, int S, void(Vist)(ElemType));


// 图形化输出
void PrintList(SLinkList space, int S);

#endif // !LKLINKLIST_H
