#ifndef LKLINKLIST_H
#define LKLINKLIST_H

#include "Status.h"

#define MAXSIZE   1000 // ��̬�������󳤶�

typedef int ElemType;  // ����Ԫ������

typedef struct SLinkNode{
	ElemType   data;  
	int        cur;   // �α�,��ָ���ã���������һ���ڵ�
} SLinkList[MAXSIZE];

// ��ʼ�����ñ�
void InitSpace(SLinkList space);

// ����ռ�
int Malloc(SLinkList space);

// ���տռ�
void Free(SLinkList space, int k);

/*----------��̬�������----------*/

// ��̬�����ʼ��
Status InitSLinkList(SLinkList space, int* S);

// ���پ�̬����
Status DestroySLinkList(SLinkList space, int* S);

// �ͷŷ�ͷ���Ŀռ�
Status ClearSLinkList(SLinkList space, int S);

// �п�
Status SLinkListEmpy(SLinkList space, int S);

// ��̬������
int SLinkListLength(SLinkList space, int S);

// ��ȡ��i��Ԫ��,�洢��e
Status GetSLinkElem(SLinkList space, int S, int i, ElemType* e);

// ���ؾ�̬�������׸���e����Compare��ϵ��Ԫ��λ��
int LocateSLElem(SLinkList space, int S, ElemType e, Status(Compare)(ElemType e1, ElemType e2));

// ��̬����ǰ��
Status PriorSLElem(SLinkList space, int S, ElemType cur_e, ElemType* pre_e);

// ��̬������
Status NextSLElem(SLinkList space, int S, ElemType cur_e, ElemType* next_e);

// ��̬�������
Status SLinkListInsert(SLinkList space, int S, int i, ElemType e);

// ��̬����ɾ��
Status SLinkListDelete(SLinkList space, int S, int i, ElemType* e);

// ������̬����
Status SLinkListTraverse(SLinkList space, int S, void(Vist)(ElemType));


// ͼ�λ����
void PrintList(SLinkList space, int S);

#endif // !LKLINKLIST_H
