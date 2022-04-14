#ifndef DULINKLIST_H
#define DULINKLIST_H

#include "Status.h"

// ����Ԫ��
typedef int ElemType;

// ����ڵ�
typedef struct DuLNode {
	ElemType        data;   // �������
 	struct DuLNode* prior;  // ǰ��
	struct DuLNode* next;   // ��׺
} DuLNode, *DuLinkList;

// ��ʼ��
Status InitDuLinkList(DuLinkList* L);

// ����
Status DestroyDuLinkList(DuLinkList* L);

// �ÿ�
Status ClearDuLinkList(DuLinkList L);

// �п�
Status DuLinkListEmpty(DuLinkList L);

// ��ȡ����
int DuLinkListLength(DuLinkList L);

// ȡ��i��ֵ
Status GetDuLinkListElem(DuLinkList L, int i, ElemType* e);

// �����׸���e����Compare��λ��
int LocateDuLinkListElem(DuLinkList L, ElemType e, Status(Compare)(ElemType e1, ElemType e2));

// ǰ��
Status PriorDuLinkListElem(DuLinkList L, ElemType cur_e, ElemType* pre_e);

// ���
Status NextDuLinkListElem(DuLinkList L, ElemType cur_e, ElemType* next_e);

// ����
Status DuLinkListInsert(DuLinkList L, int i, ElemType e);

// ɾ��
Status DuLinkListDelete(DuLinkList L, int i, ElemType* e);

// ����
void DuLinkListTraverse(DuLinkList L, void(Visit)(ElemType e));

// ��ȡ��i��Ԫ�ص�����
static DuLinkList GetDuLinkListElemP(DuLinkList L, int i);

#endif // !DULINKLIST_H
