#include "MergeELinkList.h"


Status MergeElinkList(ELinkList* La, ELinkList* Lb, ELinkList* Lc, int(Compare)(ElemType e1, ElemType e2)) {
    ELink ha, hb, q;
    EPosition pa, pb;
    ElemType a, b;
    
    // 分配存储空间
    if (!InitELinkList(Lc)) {
        return ERROR;  // 分配失败
    }

    ha = GetElinkListHead(*La);
    hb = GetElinkListHead(*Lb);

    // 确保La和Lb为有效链表
    if (!ha || !hb) {
        return ERROR;
    }

    pa = ELinkListNextPos(*La, ha);
    pb = ELinkListNextPos(*Lb, hb);

    while (pa && pb) {
        a = GetELinkListCurElem(pa);
        b = GetELinkListCurElem(pb);

        if (Compare(a,b) <=0) {
            // 从La中摘下首个元素
            ELinkListDeleteFirst(La, ha, &q);
            // 插入到Lc
            ELinkListAppend(Lc, q);
            pa = ELinkListNextPos(*La, ha);
        } else {
            ELinkListDeleteFirst(Lb, hb, &q);
            ELinkListAppend(Lc, q);
            pb = ELinkListNextPos(*Lb, hb);
        }
    }
    // 把L_a,L_b剩下的插入
    pa ? ELinkListAppend(Lc, pa) : ELinkListAppend(Lc, pb);

    // 释放节点
    FreeNode(&(La->head));
    FreeNode(&(Lb->head));
    La->tail = NULL;
    Lb->tail = NULL;
    La->len = 0;
    Lb->len = 0;
    return OK;
}