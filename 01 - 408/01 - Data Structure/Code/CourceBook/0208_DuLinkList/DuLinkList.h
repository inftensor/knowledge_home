#ifndef DULINKLIST_H
#define DULINKLIST_H

#include "Status.h"

// 基础元素
typedef int ElemType;

// 定义节点
typedef struct DuLNode {
	ElemType        data;   // 存放数据
 	struct DuLNode* prior;  // 前驱
	struct DuLNode* next;   // 后缀
} DuLNode, *DuLinkList;

// 初始化
Status InitDuLinkList(DuLinkList* L);

// 销毁
Status DestroyDuLinkList(DuLinkList* L);

// 置空
Status ClearDuLinkList(DuLinkList L);

// 判空
Status DuLinkListEmpty(DuLinkList L);

// 获取长度
int DuLinkListLength(DuLinkList L);

// 取第i个值
Status GetDuLinkListElem(DuLinkList L, int i, ElemType* e);

// 返回首个和e满足Compare的位置
int LocateDuLinkListElem(DuLinkList L, ElemType e, Status(Compare)(ElemType e1, ElemType e2));

// 前驱
Status PriorDuLinkListElem(DuLinkList L, ElemType cur_e, ElemType* pre_e);

// 后继
Status NextDuLinkListElem(DuLinkList L, ElemType cur_e, ElemType* next_e);

// 插入
Status DuLinkListInsert(DuLinkList L, int i, ElemType e);

// 删除
Status DuLinkListDelete(DuLinkList L, int i, ElemType* e);

// 遍历
void DuLinkListTraverse(DuLinkList L, void(Visit)(ElemType e));

// 获取第i个元素的引用
static DuLinkList GetDuLinkListElemP(DuLinkList L, int i);

#endif // !DULINKLIST_H
