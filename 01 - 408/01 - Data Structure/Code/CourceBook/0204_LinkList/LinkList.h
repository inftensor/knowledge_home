#ifndef LINKLIST_H
#define LINKLIST_H

//#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Status.h"

// �������Ԫ��
typedef int ElemType;

typedef struct LNode{
	ElemType        data;   // ���ݽڵ�
	struct LNode*   next;   // ��һ���ڵ��ָ��
}LNode, *LinkList;


//typedef LNode* LinkList;

// ��ʼ������
Status InitListLk(LinkList* L);

// ��������
Status DestroyListLk(LinkList* L);

// �ÿ�����
Status ClearListLk(LinkList L);

// �����п�
Status LkListEmpty(LinkList L);

// ������
int LkListLength(LinkList L);

// ��ȡ�����i��Ԫ��,���洢����e��
Status GetLkElem(LinkList L, int i, ElemType* e);

// �����������׸���e����compare��Ԫ��
int LocateLkElem(LinkList L, ElemType e, Status(Compare)(ElemType e1, ElemType e2));

// ����ǰ��
Status PriorLkElem(LinkList L, ElemType cur_e, ElemType* pre_e);

// ������
Status NextLkElem(LinkList L, ElemType cur_e, ElemType* next_e);

// �������
Status LkListInsert(LinkList L, int i, ElemType e);

// ����ɾ��
Status LkListDelete(LinkList L, int i, ElemType* e);

// �������
void LkListTraverse(LinkList L, void(Visit)(ElemType));

// ͷ�巨������������
Status CreateLsitLk_Head(LinkList* L, int n, char* path);

// β�巨
Status CreateListLk_Tail(LinkList* L, int n, char* path);

#endif // !LINKLIST_H
