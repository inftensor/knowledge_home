#include "SqList.h"

// ��ʼ�����Ա�
Status InitListSq(SqList* L) {
    L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->elem) {
        exit(OVERFLOW);
    }
    L->length = 0;                  //  �ձ���Ϊ0
    L->listsize = LIST_INIT_SIZE;   //  ��ʼ�洢����
    return OK;
} // InitListSq

// �������Ա�
Status DestroyListSq(SqList* L) {
    // ȷ��˳��������
    if (L == NULL || L->elem == NULL) {
        return ERROR;
    }

    // �ͷ�L��elem�ڴ�
    free(L->elem);
    // �ͷź���Ϊ��ָ��
    L->elem = NULL;
    // ��˳����Ⱥ���������
    L->length = 0;
    L->listsize = 0;
    return OK;
}

// ���Ա��ÿ�
Status ClearListSq(SqList* L) {
    if (L == NULL || L->elem == NULL) {
        return ERROR;
    }

    L->length = 0;
    return OK;
}

// �ж����Ա��Ƿ�Ϊ��
Status SqListEmpty(SqList L) {
    return L.length == 0 ? TRUE : FALSE;
}

// ���Ա����ЧԪ������
int SqListLength(SqList L) {
    return L.length;
}

// ��ȡ��i��Ԫ��
Status GetSqElem(SqList L, int i, ElemType* e) {
    // ȷ��˳������
    if (L.elem == NULL) {
        return ERROR;
    }

    // ȷ��iֵ����
    if (i<1 || i>L.length) {
        return ERROR;
    }

    *e = L.elem[i - 1];
    return OK;
}

// ����˳������׸���e����compare��ϵ��Ԫ��λ��
int LocateSqElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType)) {
    // ȷ��˳������
    if (L.elem == NULL) {
        return ERROR;
    }

    int i = 1;
    // ElemType* p=L.elem;

    // �������һֱ����
    while (i <= L.length && !Compare(L.elem[i - 1], e)) {
        i++;
    }

    if (i <= L.length) {
        return i;
    }
    else {
        // δ�ҵ�
        return 0;
    }
}

// Ѱ��cur_eԪ�ص�ǰ��,�����ظ�pre_e
Status PriorSqElem(SqList L, ElemType cur_e, ElemType* pre_e) {
    // ȷ��˳��������Ԫ�ظ�������1
    if (L.elem == NULL || L.length < 2) {
        return ERROR;
    }

    int i = 0;
    // �ӵ�һ��Ԫ�ؿ�ʼ��
    while (i < L.length && L.elem[i] != cur_e) {
        i++;
    }

    // cur_e���׸�Ԫ�أ�����û�ҵ�Ԫ��cur_e
    if (i == 0 || i >= L.length) {
        return ERROR;
    }

    // ��ǰ����pre_e
    *pre_e = L.elem[i - 1];

    return OK;
}

// Ѱ��cur_eԪ�صĺ�̣������ظ�next_e
Status NextSqElem(SqList L, ElemType cur_e, ElemType* next_e) {
    // ȷ��˳��������Ԫ�ظ�������1
    if (L.elem == NULL || L.length < 2) {
        return ERROR;
    }

    int i = 0;
    while (i < L.length - 1 && L.elem[i] != cur_e) {
        i++;
    }
    // cur_e�����һ����û���ҵ�
    if (i >= L.length - 1) {
        return ERROR;
    }
    *next_e = L.elem[i + 1];
    return OK;
}

// �ڵ�i��λ�ò���Ԫ��
Status SqListInsert(SqList* L, int i, ElemType e) {
    ElemType* newbase;
    ElemType* p, * q;

    // ȷ��˳������
    if (L == NULL || L->elem == NULL) {
        return ERROR;
    }

    // ���iֵ�Ƿ�Խ��
    if (i <1 || i> L->length + 1) {
        return ERROR;
    }

    // �������ռ��Ѿ����ˣ������ӷ���
    if (L->length >= L->listsize) {
        newbase = (ElemType*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase) {
            // �洢�ռ����ʧ��
            exit(OVERFLOW);
        }
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }

    // �ҵ������λ��
    q = &(L->elem[i - 1]);

    // ����λ�ú��Ԫ������
    for (p = &(L->elem[L->length - 1]); p >= q; p--) {
        *(p + 1) = *(p);
    }

    // ����e
    *q = e;

    // ���ȼ�1
    L->length++;

    return OK;
}

// ɾ����i��λ�õ�Ԫ��,����ɾ��Ԫ�ظ���e
Status SqListDelete(SqList* L, int i, ElemType* e) {
    ElemType* p, * q;

    // ȷ��˳������
    if (L == NULL || L->elem == NULL) {
        return ERROR;
    }

    // ȷ��iֵ�Ϸ�
    if (i<1 || i>L->length) {
        return ERROR;
    }
    // ��ȡ��ɾ��Ԫ�ز�����e
    p = &(L->elem[i - 1]);
    *e = *p;
    // ��βԪ��
    q = L->elem + L->length - 1;
    // ��ɾ��Ԫ�غ�ÿ������һλ
    for (++p; p <= q; ++p) {
        *(p - 1) = *p;
    }

    // ���ȼ�1
    L->length--;
    return OK;
}

// ��visit ��������˳���L
void SqListTraverse(SqList L, void(Visit)(ElemType)) {
    int i;

    for (i = 0; i < L.length; i++) {
        Visit(L.elem[i]);
    }
}