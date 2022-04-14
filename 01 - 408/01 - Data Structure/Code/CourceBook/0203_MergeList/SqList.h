#ifndef SQLIST_H
#define SQLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"


//----------线性表的动态分配顺序存储结构--------
#define LIST_INIT_SIZE    100   // 线性表存储空间的初始分配量
#define LISTINCREMENT     10    // 线性表存储空间的分配增量

// 定义基本类型
typedef int ElemType;

typedef struct {
    ElemType* elem;            // 存储空间基址 
    int      length;           // 当前长度
    int      listsize;         // 当前分配的存储容量(以sizeof(ElemType)为单位)
}SqList;

// 初始化线性表
Status InitListSq(SqList* L);

// 销毁线性表
Status DestroyListSq(SqList* L);

// 线性表置空
Status ClearListSq(SqList* L);

// 判断线性表是否为空
Status SqListEmpty(SqList L);

// 线性表的有效元素数量
int SqListLength(SqList L);

// 获取第i个元素
Status GetSqElem(SqList L, int i, ElemType* e);

// 返回顺序表中首个与e满足compare关系的元素位置
int LocateSqElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType));

// 寻找cur_e元素的前驱,并返回给pre_e
Status PriorSqElem(SqList L, ElemType cur_e, ElemType* pre_e);

// 寻找cur_e元素的后继，并返回给next_e
Status NextSqElem(SqList L, ElemType cur_e, ElemType* next_e);

// 在第i个位置插入元素e
Status SqListInsert(SqList* L, int i, ElemType e);

// 删除第i个位置的元素,并将删除元素赋给e
Status SqListDelete(SqList* L, int i, ElemType* e);

// 用visit函数访问顺序表L
void SqListTraverse(SqList L, void(Visit)(ElemType));

#endif

