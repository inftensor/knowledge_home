#ifndef ELINKLIST_H
#define ELINKLIST_H

#include "Status.h"
#include <stdlib.h>

// 基本元素
typedef int ElemType;

// 线性表数据结构
typedef struct ELNode {
	ElemType        data;
	struct ELNode* next;
}ELNode, * ELink, * EPosition;

// 维护线性表表头尾指针和长度
typedef struct {
	ELink head, tail;     // 头结点和尾结点
	int          len;     // 长度
}ELinkList;

/* ----------自定义内存操作---------- */
// 内存分配
Status MakeNode(ELink* p, ElemType e);

// 内存释放
void FreeNode(ELink* p);


/* ----------链表操作---------- */
// 初始化
Status InitELinkList(ELinkList* L);

// 销毁
Status DestroyELinkList(ELinkList* L);

// 置空
Status ClearELinkList(ELinkList* L);

// 判空
Status ELinkListEmpty(ELinkList L);

// 计数
int ELinkListLength(ELinkList L);

// 获取第一个和e满足Compare的位置
EPosition ELinkListLocate(ELinkList L, ElemType e, Status(Compare)(ElemType e1, ElemType e2));

// 指定序列插入
Status ELinkListInsert(ELinkList* L, int i, ElemType e);

// 指定序列删除
Status ELinkListDelete(ELinkList* L, int i, ElemType* e);

// 遍历
void ELinkListTraverse(ELinkList L, void(Vsit)(ElemType e));

/* ----------链表扩展操作---------- */
// 获取节点元素
ElemType GetELinkListCurElem(ELink p);

// 设置节点元素
Status SetELinkListCurElem(ELink p, ElemType e);

// 获取头结点
EPosition GetElinkListHead(ELinkList L);

// 获取尾结点
EPosition GetElinkListTail(ELinkList L);

// 获取前驱
EPosition ELinkListPriorPos(ELinkList L, ELink p);

// 获取后继
EPosition ELinkListNextPos(ELinkList L, ELink p);

// 查找序列元素，返回引用
Status ELinkListLocatePos(ELinkList L, int i, ELink* p);

// 将s插入h后
Status ELinkListInsertFirst(ELinkList* L, ELink h, ELink s);

// 删除h节点后的第一个节点
Status ELinkListDeleteFirst(ELinkList* L, ELink h, ELink* q);

// 插入指定节点前
Status ELinkListInsertBefore(ELinkList* L, ELink* p, ELink s);

// // 插入指定节点后 (这个上面已经实现通用的了)
// Status ELinkListInsertAfter(ELinkList* L, ELink* p, ELink s);

// 表尾增加一串
Status ELinkListAppend(ELinkList* L, ELink s);

// 表尾删除
Status ELinkListReMove(ELinkList* L, ELink* q);

#endif // !ELINKLIST_H
