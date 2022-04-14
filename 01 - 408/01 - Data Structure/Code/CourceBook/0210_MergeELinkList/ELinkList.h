#ifndef ELINKLIST_H
#define ELINKLIST_H

#include "Status.h"
#include <stdlib.h>

// ����Ԫ��
typedef int ElemType;

// ���Ա����ݽṹ
typedef struct ELNode {
	ElemType        data;
	struct ELNode* next;
}ELNode, * ELink, * EPosition;

// ά�����Ա��ͷβָ��ͳ���
typedef struct {
	ELink head, tail;     // ͷ����β���
	int          len;     // ����
}ELinkList;

/* ----------�Զ����ڴ����---------- */
// �ڴ����
Status MakeNode(ELink* p, ElemType e);

// �ڴ��ͷ�
void FreeNode(ELink* p);


/* ----------�������---------- */
// ��ʼ��
Status InitELinkList(ELinkList* L);

// ����
Status DestroyELinkList(ELinkList* L);

// �ÿ�
Status ClearELinkList(ELinkList* L);

// �п�
Status ELinkListEmpty(ELinkList L);

// ����
int ELinkListLength(ELinkList L);

// ��ȡ��һ����e����Compare��λ��
EPosition ELinkListLocate(ELinkList L, ElemType e, Status(Compare)(ElemType e1, ElemType e2));

// ָ�����в���
Status ELinkListInsert(ELinkList* L, int i, ElemType e);

// ָ������ɾ��
Status ELinkListDelete(ELinkList* L, int i, ElemType* e);

// ����
void ELinkListTraverse(ELinkList L, void(Vsit)(ElemType e));

/* ----------������չ����---------- */
// ��ȡ�ڵ�Ԫ��
ElemType GetELinkListCurElem(ELink p);

// ���ýڵ�Ԫ��
Status SetELinkListCurElem(ELink p, ElemType e);

// ��ȡͷ���
EPosition GetElinkListHead(ELinkList L);

// ��ȡβ���
EPosition GetElinkListTail(ELinkList L);

// ��ȡǰ��
EPosition ELinkListPriorPos(ELinkList L, ELink p);

// ��ȡ���
EPosition ELinkListNextPos(ELinkList L, ELink p);

// ��������Ԫ�أ���������
Status ELinkListLocatePos(ELinkList L, int i, ELink* p);

// ��s����h��
Status ELinkListInsertFirst(ELinkList* L, ELink h, ELink s);

// ɾ��h�ڵ��ĵ�һ���ڵ�
Status ELinkListDeleteFirst(ELinkList* L, ELink h, ELink* q);

// ����ָ���ڵ�ǰ
Status ELinkListInsertBefore(ELinkList* L, ELink* p, ELink s);

// // ����ָ���ڵ�� (��������Ѿ�ʵ��ͨ�õ���)
// Status ELinkListInsertAfter(ELinkList* L, ELink* p, ELink s);

// ��β����һ��
Status ELinkListAppend(ELinkList* L, ELink s);

// ��βɾ��
Status ELinkListReMove(ELinkList* L, ELink* q);

#endif // !ELINKLIST_H
