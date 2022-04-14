#include "ELinkList.h"


// 内存分配
Status MakeNode(ELink* p, ElemType e) {
    // 确保存在
    if (!p) {
        return ERROR;
    }

    (*p) = (ELink)malloc(sizeof(ELNode));
    if (!(*p)) {
        // 内存分配失败
        return ERROR;
    }

    (*p)->data = e;
    (*p)->next = NULL;

    return OK;
}

// 内存释放
void FreeNode(ELink* p) {
    // 确保存在
    if (!p || !(*p)) {
        return;
    }

    free(*p);
    *p = NULL;
}


// 初始化
Status InitELinkList(ELinkList* L) {
    // 确保链表存在
    if (!L) {
        return ERROR;
    }
    // 创建头结点
    ELink p = (ELink)malloc(sizeof(ELNode));
    if (!p) {
        // 内存分配失败
        exit(OVERFLOW);
    }
    p->next = NULL;

    // 首位指向头结点
    L->head = L->tail = p;
    L->len = 0;

    return OK;
}


// 销毁
Status DestroyELinkList(ELinkList* L) {
    // 确保链表存在
    if (!L || !L->head) {
        return ERROR;
    }

    ClearELinkList(L);

    // 删除头结点
    free(L->head);
    L->head = L->tail = NULL;

    return OK;
}


// 置空
Status ClearELinkList(ELinkList* L) {
    // 确保存在且不为空
    if (!L || !L->head) {
        return ERROR;
    }

    ELink p, q;

    p = L->head->next;  // 第一个元素
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

// 判空
Status ELinkListEmpty(ELinkList L) {
    return L.len <= 0 ? TRUE : FALSE;
}


// 计数
int ELinkListLength(ELinkList L) {
    return L.len;
}


// 获取第一个和e满足Compare的位置
EPosition ELinkListLocate(ELinkList L, ElemType e, Status(Compare)(ElemType e1, ElemType e2)) {
    // 确保存在且不为空
    if (L.len <= 0) {
        return ERROR;
    }

    ELink p = L.head->next; // 第一个元素

    while (p && !(Compare(p->data, e))) {
        p = p->next;
    }

    return p;
}


// 指定序列插入
Status ELinkListInsert(ELinkList* L, int i, ElemType e) {
    // 确保链表存在
    if (!L || !(L->head)) {
        return ERROR;
    }

    // 确保i值合理
    if (i<1 || i>L->len + 1) {
        return ERROR;
    }

    ELink p, q;
    // 查找第i-1个元素(因为可能插入到len+1)
    if (!ELinkListLocatePos(*L, i - 1, &p)) {
        // 查找失败
        return ERROR;
    }

    // 分配节点
    if (!MakeNode(&q, e)) {
        return ERROR;   // 内存分配失败
    }

    // 将q插入p后
    if (!ELinkListInsertFirst(L, p, q)) {
        return ERROR;
    }
    return OK;

}


// 指定序列删除
Status ELinkListDelete(ELinkList* L, int i, ElemType* e) {
    // 确保存在且不为空
    if (!L || !L->head) {
        return ERROR;
    }

    // 确保i值合法
    if (i<1 || i> L->len) {
        return ERROR;
    }

    ELink p, q;
    // 查找第i-1个元素
    if (!ELinkListLocatePos(*L, i - 1, &p)) {
        return ERROR;  //查找失败
    }

    // 删除i-1后的第一个节点
    if (!ELinkListDeleteFirst(L, p, &q)) {
        return ERROR;
    }

    *e = q->data;

    // 释放被删除的节点
    FreeNode(&q);
    return OK;

}


// 遍历
void ELinkListTraverse(ELinkList L, void(Vsit)(ElemType e)) {
    // 确保不为空
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

// 设置节点元素
Status SetELinkListCurElem(ELink p, ElemType e) {
    // 确保存在
    if (!p) {
        return ERROR;
    }

    p->data = e;
    return OK;
}

// 获取头结点
EPosition GetElinkListHead(ELinkList L) {
    return L.head;
}

// 获取尾结点
EPosition GetElinkListTail(ELinkList L) {
    return L.tail;
}

// 获取前驱
EPosition ELinkListPriorPos(ELinkList L, ELink p) {
    // 确保存在
    if (!L.head || !p) {
        return NULL;
    }

    // 头结点没有前驱
    if (L.head->next == p) {
        return NULL;
    }

    ELink pre = L.head->next;  // 第一个元素
    while (pre && pre->next != p) {
        pre = pre->next;
    }

    return pre;

}

// 获取后继
EPosition ELinkListNextPos(ELinkList L, ELink p) {
    // 确保存在
    if (!L.head || !p) {
        return NULL;
    }

    return p->next;
}

// 查找序列元素，返回引用
Status ELinkListLocatePos(ELinkList L, int i, ELink* p) {
    // 确保链表存在
    if (!L.head) {
        return ERROR;
    }

    // 确保i值合法
    if (i<0 || i>L.len) {
        return ERROR;
    }

    // i = 0 时，直接返回头结点
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

    // 查找失败(理论上不会，因为之前的i已经判别了)
    if (!q) {
        return ERROR;
    }

    *p = q;
    return OK;

}

// 将s插入h后
Status ELinkListInsertFirst(ELinkList* L, ELink h, ELink s) {
    // 确保存在
    if (!L || !L->head || !h || !s) {
        return ERROR;
    }

    s->next = h->next;
    h->next = s;

    // 如果h是尾结点，需要修改尾结点
    if (h == L->tail) {
        L->tail = s;
    }

    L->len++;
    return OK;
}

// 删除s节点后的第一个节点
Status ELinkListDeleteFirst(ELinkList* L, ELink h, ELink* q) {
    // 确保存在
    if (!L || !L->head || !h || !q) {
        return ERROR;
    }
    // 如果h没有后继，退出
    if (!h->next) {
        return ERROR;
    }

    *q = h->next;
    h->next = (*q)->next;

    // 把q变为孤立节点
    (*q)->next = NULL;

    // 如果h变成了尾结点，则需修改L
    if (!h->next) {
        L->tail = h;
    }

    L->len--;
    return OK;

}

// 插入指定节点前
Status ELinkListInsertBefore(ELinkList* L, ELink* p, ELink s) {
    // 确保存在
    if (!L || !L->head || !p || !s) {
        return ERROR;
    }

    // 寻找p的前驱(这里头结点是首节点的前驱)
    ELink pre = L->head;
    while (pre && pre->next != (*p)) {
        pre = pre->next;
    }

    if (!pre) {
        // 没找到
        return ERROR;
    }

    pre->next = s;
    s->next = *p;
    L->len++;
    return OK;
}


// // 插入指定节点后
// Status ELinkListInsertAfter(ELinkList* L, ELink* p, ELink s) {
//     // 确保存在
//     if (!L || !L->head || !p || !s) {
//         return ERROR;
//     }

//     //
// }

// 表尾增加一串
Status ELinkListAppend(ELinkList* L, ELink s) {
    // 确保存在
    if (!L || !L->head || !s) {
        return ERROR;
    }

    int count = 0;
    L->tail->next = s;
    // 更新尾结点
    while (s) {
        L->tail = s;
        s = s->next;
        count++;
    }

    L->len += count;
    return OK;
}

// 表尾删除
Status ELinkListReMove(ELinkList* L, ELink* q) {
    // 确保存在
    if (!L || !L->head || !q) {
        return ERROR;
    }

    // 空链表
    if (L->len <= 0) {
        *q = NULL;
        return ERROR;
    }

    *q = L->tail;

    // 更新尾结点
    ELink pre = L->head; // 首节点
    if (pre->next != L->tail) {
        pre = pre->next;
    }
    pre->next = NULL;
    L->tail = pre;
    L->len--;

    return OK;
}