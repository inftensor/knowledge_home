#ifndef SQLIST_H
#define SQLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"


//----------���Ա�Ķ�̬����˳��洢�ṹ--------
#define LIST_INIT_SIZE    100   // ���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT     10    // ���Ա�洢�ռ�ķ�������

// �����������
typedef int ElemType;

typedef struct {
    ElemType* elem;            // �洢�ռ��ַ 
    int      length;           // ��ǰ����
    int      listsize;         // ��ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ)
}SqList;

// ��ʼ�����Ա�
Status InitListSq(SqList* L);

// �������Ա�
Status DestroyListSq(SqList* L);

// ���Ա��ÿ�
Status ClearListSq(SqList* L);

// �ж����Ա��Ƿ�Ϊ��
Status SqListEmpty(SqList L);

// ���Ա����ЧԪ������
int SqListLength(SqList L);

// ��ȡ��i��Ԫ��
Status GetSqElem(SqList L, int i, ElemType* e);

// ����˳������׸���e����compare��ϵ��Ԫ��λ��
int LocateSqElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType));

// Ѱ��cur_eԪ�ص�ǰ��,�����ظ�pre_e
Status PriorSqElem(SqList L, ElemType cur_e, ElemType* pre_e);

// Ѱ��cur_eԪ�صĺ�̣������ظ�next_e
Status NextSqElem(SqList L, ElemType cur_e, ElemType* next_e);

// �ڵ�i��λ�ò���Ԫ��e
Status SqListInsert(SqList* L, int i, ElemType e);

// ɾ����i��λ�õ�Ԫ��,����ɾ��Ԫ�ظ���e
Status SqListDelete(SqList* L, int i, ElemType* e);

// ��visit��������˳���L
void SqListTraverse(SqList L, void(Visit)(ElemType));

#endif

