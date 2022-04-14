#include "ELinkList.h"


// �ڴ����
Status MakeNode(ELink* p, ElemType e) {
    // ȷ������
    if (!p) {
        return ERROR;
    }

    (*p) = (ELink)malloc(sizeof(ELNode));
    if (!(*p)) {
        // �ڴ����ʧ��
        return ERROR;
    }

    (*p)->data = e;
    (*p)->next = NULL;

    return OK;
}

// �ڴ��ͷ�
void FreeNode(ELink* p) {
    // ȷ������
    if (!p || !(*p)) {
        return;
    }

    free(*p);
    *p = NULL;
}


// ��ʼ��
Status InitELinkList(ELinkList* L) {
    // ȷ���������
    if (!L) {
        return ERROR;
    }
    // ����ͷ���
    ELink p = (ELink)malloc(sizeof(ELNode));
    if (!p) {
        // �ڴ����ʧ��
        exit(OVERFLOW);
    }
    p->next = NULL;

    // ��λָ��ͷ���
    L->head = L->tail = p;
    L->len = 0;

    return OK;
}


// ����
Status DestroyELinkList(ELinkList* L) {
    // ȷ���������
    if (!L || !L->head) {
        return ERROR;
    }

    ClearELinkList(L);

    // ɾ��ͷ���
    free(L->head);
    L->head = L->tail = NULL;

    return OK;
}


// �ÿ�
Status ClearELinkList(ELinkList* L) {
    // ȷ�������Ҳ�Ϊ��
    if (!L || !L->head) {
        return ERROR;
    }

    ELink p, q;

    p = L->head->next;  // ��һ��Ԫ��
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    L->head->next = NULL;
    L->tail = L->head;
    L->len = 0;

    return OK;
}

// �п�
Status ELinkListEmpty(ELinkList L) {
    return L.len <= 0 ? TRUE : FALSE;
}


// ����
int ELinkListLength(ELinkList L) {
    return L.len;
}


// ��ȡ��һ����e����Compare��λ��
EPosition ELinkListLocate(ELinkList L, ElemType e, Status(Compare)(ElemType e1, ElemType e2)) {
    // ȷ�������Ҳ�Ϊ��
    if (L.len <= 0) {
        return ERROR;
    }

    ELink p = L.head->next; // ��һ��Ԫ��

    while (p && !(Compare(p->data, e))) {
        p = p->next;
    }

    return p;
}


// ָ�����в���
Status ELinkListInsert(ELinkList* L, int i, ElemType e) {
    // ȷ���������
    if (!L || !(L->head)) {
        return ERROR;
    }

    // ȷ��iֵ����
    if (i<1 || i>L->len + 1) {
        return ERROR;
    }

    ELink p, q;
    // ���ҵ�i-1��Ԫ��(��Ϊ���ܲ��뵽len+1)
    if (!ELinkListLocatePos(*L, i - 1, &p)) {
        // ����ʧ��
        return ERROR;
    }

    // ����ڵ�
    if (!MakeNode(&q, e)) {
        return ERROR;   // �ڴ����ʧ��
    }

    // ��q����p��
    if (!ELinkListInsertFirst(L, p, q)) {
        return ERROR;
    }
    return OK;

}


// ָ������ɾ��
Status ELinkListDelete(ELinkList* L, int i, ElemType* e) {
    // ȷ�������Ҳ�Ϊ��
    if (!L || !L->head) {
        return ERROR;
    }

    // ȷ��iֵ�Ϸ�
    if (i<1 || i> L->len) {
        return ERROR;
    }

    ELink p, q;
    // ���ҵ�i-1��Ԫ��
    if (!ELinkListLocatePos(*L, i - 1, &p)) {
        return ERROR;  //����ʧ��
    }

    // ɾ��i-1��ĵ�һ���ڵ�
    if (!ELinkListDeleteFirst(L, p, &q)) {
        return ERROR;
    }

    *e = q->data;

    // �ͷű�ɾ���Ľڵ�
    FreeNode(&q);
    return OK;

}


// ����
void ELinkListTraverse(ELinkList L, void(Vsit)(ElemType e)) {
    // ȷ����Ϊ��
    if (L.len <= 0) {
        return;
    }

    ELink p = L.head->next;
    while (p) {
        Vsit(p->data);
        p = p->next;
    }
    printf("\n");
}


ElemType GetELinkListCurElem(ELink p) {
    return p ? p->data : INT_MIN;
}

// ���ýڵ�Ԫ��
Status SetELinkListCurElem(ELink p, ElemType e) {
    // ȷ������
    if (!p) {
        return ERROR;
    }

    p->data = e;
    return OK;
}

// ��ȡͷ���
EPosition GetElinkListHead(ELinkList L) {
    return L.head;
}

// ��ȡβ���
EPosition GetElinkListTail(ELinkList L) {
    return L.tail;
}

// ��ȡǰ��
EPosition ELinkListPriorPos(ELinkList L, ELink p) {
    // ȷ������
    if (!L.head || !p) {
        return NULL;
    }

    // ͷ���û��ǰ��
    if (L.head->next == p) {
        return NULL;
    }

    ELink pre = L.head->next;  // ��һ��Ԫ��
    while (pre && pre->next != p) {
        pre = pre->next;
    }

    return pre;

}

// ��ȡ���
EPosition ELinkListNextPos(ELinkList L, ELink p) {
    // ȷ������
    if (!L.head || !p) {
        return NULL;
    }

    return p->next;
}

// ��������Ԫ�أ���������
Status ELinkListLocatePos(ELinkList L, int i, ELink* p) {
    // ȷ���������
    if (!L.head) {
        return ERROR;
    }

    // ȷ��iֵ�Ϸ�
    if (i<0 || i>L.len) {
        return ERROR;
    }

    // i = 0 ʱ��ֱ�ӷ���ͷ���
    if (i == 0) {
        *p = L.head;
        return OK;
    }

    int j = 0;
    ELink q = L.head;

    while (!q || j < i) {
        q = q->next;
        j++;
    }

    // ����ʧ��(�����ϲ��ᣬ��Ϊ֮ǰ��i�Ѿ��б���)
    if (!q) {
        return ERROR;
    }

    *p = q;
    return OK;

}

// ��s����h��
Status ELinkListInsertFirst(ELinkList* L, ELink h, ELink s) {
    // ȷ������
    if (!L || !L->head || !h || !s) {
        return ERROR;
    }

    s->next = h->next;
    h->next = s;

    // ���h��β��㣬��Ҫ�޸�β���
    if (h == L->tail) {
        L->tail = s;
    }

    L->len++;
    return OK;
}

// ɾ��s�ڵ��ĵ�һ���ڵ�
Status ELinkListDeleteFirst(ELinkList* L, ELink h, ELink* q) {
    // ȷ������
    if (!L || !L->head || !h || !q) {
        return ERROR;
    }
    // ���hû�к�̣��˳�
    if (!h->next) {
        return ERROR;
    }

    *q = h->next;
    h->next = (*q)->next;

    // ��q��Ϊ�����ڵ�
    (*q)->next = NULL;

    // ���h�����β��㣬�����޸�L
    if (!h->next) {
        L->tail = h;
    }

    L->len--;
    return OK;

}

// ����ָ���ڵ�ǰ
Status ELinkListInsertBefore(ELinkList* L, ELink* p, ELink s) {
    // ȷ������
    if (!L || !L->head || !p || !s) {
        return ERROR;
    }

    // Ѱ��p��ǰ��(����ͷ������׽ڵ��ǰ��)
    ELink pre = L->head;
    while (pre && pre->next != (*p)) {
        pre = pre->next;
    }

    if (!pre) {
        // û�ҵ�
        return ERROR;
    }

    pre->next = s;
    s->next = *p;
    L->len++;
    return OK;
}


// // ����ָ���ڵ��
// Status ELinkListInsertAfter(ELinkList* L, ELink* p, ELink s) {
//     // ȷ������
//     if (!L || !L->head || !p || !s) {
//         return ERROR;
//     }

//     //
// }

// ��β����һ��
Status ELinkListAppend(ELinkList* L, ELink s) {
    // ȷ������
    if (!L || !L->head || !s) {
        return ERROR;
    }

    int count = 0;
    L->tail->next = s;
    // ����β���
    while (s) {
        L->tail = s;
        s = s->next;
        count++;
    }

    L->len += count;
    return OK;
}

// ��βɾ��
Status ELinkListReMove(ELinkList* L, ELink* q) {
    // ȷ������
    if (!L || !L->head || !q) {
        return ERROR;
    }

    // ������
    if (L->len <= 0) {
        *q = NULL;
        return ERROR;
    }

    *q = L->tail;

    // ����β���
    ELink pre = L->head; // �׽ڵ�
    if (pre->next != L->tail) {
        pre = pre->next;
    }
    pre->next = NULL;
    L->tail = pre;
    L->len--;

    return OK;
}