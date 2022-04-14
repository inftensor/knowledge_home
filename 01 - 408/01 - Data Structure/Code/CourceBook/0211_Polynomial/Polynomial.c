#include "Pololynomial.h"


// 创建多项式
void CreatePolyn(Polynomial* P, int m, int* expns, float* coefs) {
    EPosition h, q;
    ElemType e;
    int i;
    ELink s;

    InitELinkList(P);
    h = GetElinkListHead(*P); // 头指针
    e.coef = 0.0f;
    e.expn = -1;
    SetELinkListCurElem(h, e);

    for (i=1; i<=m; i++) {
        e.coef = coefs[i-1];
        e.expn = expns[i-1];

        //// 链表中不存在该指数项
        //if (!ELinkListLocate(*P, e, &q, Cmp)) {
        //      // 创建节点
        //    if (MakeNode(&s, e) ) {
        //        ELinkListInsertFirst(P, q, s);
        //    }
        //}
        MakeNode(&s, e);
        ELinkListInsertFirst(P, h, s);
        h = h->next;
    }
}


// 销毁多项式
void DestroyPolyn(Polynomial* P) {
    DestroyELinkList(P);
}

// 返回项数
int PolynLength(Polynomial P) {
    return ELinkListLength(P);
}

// 多项式相加
void AddPolyn(Polynomial* Pa, Polynomial* Pb) {
    EPosition ha, hb;
    EPosition qa, qb;
    ElemType a, b;
    float sum;

    ha = GetElinkListHead(*Pa);
    hb = GetElinkListHead(*Pb);

    qa = ELinkListNextPos(*Pa, ha);
    qb = ELinkListNextPos(*Pb, hb);

    while (qa && qb) {
        a = GetELinkListCurElem(qa);
        b = GetELinkListCurElem(qb);

        
        
        switch(Cmp(a, b)) {
            case -1: { // La的系数小
                ha = qa;
                qa = ELinkListNextPos(*Pa, ha);
            }
            break;
              
            case 0 :{
                sum = a.coef + b.coef;
                if (sum != 0.0) {
                    qa->data.coef = sum;
                    ha = qa;
                } else { // 相加系数为0
                    ELinkListDeleteFirst(Pa, ha, &qa);
                    FreeNode(&qa);
                }
                // 删除Lb用过的节点
                ELinkListDeleteFirst(Pb, hb, &qb);
                FreeNode(&qb);

                // qa和qb后移
                qa = ELinkListNextPos(*Pa, ha);
                qb = ELinkListNextPos(*Pb, hb);
             
             }
             break;

             case 1: { //Pa的指大于Pb
                // 从Pb摘下，放到Pa
                ELinkListDeleteFirst(Pb, hb, &qb);
                ELinkListInsertFirst(Pa, ha, qb);

                // 后移
                ha = ELinkListNextPos(*Pa, ha);
                qb = ELinkListNextPos(*Pb, hb);
             }
             break;

        }
    }
    // Pb还有剩余，直接接入
    if (qb) {
        ELinkListAppend(Pa, qb);
    }
    // 释放Pb
    FreeNode(&hb);
    Pb->head = Pb->tail = NULL;
    Pb->len = 0;
}

// 多项式相减
void SubtractPolyn(Polynomial* Pa, Polynomial* Pb) {
    // 这个先把Pb每个系数都取反，后面调用加法
    ELink p;    
    int i ;
    for (i=0; i<Pb->len; i++) {
        ELinkListLocatePos(*Pb, i+1, &p);
        p->data.coef = -1.0*p->data.coef;
    }
    AddPolyn(Pa, Pb);
}

// 多项式相乘
void MuliplyPolyn(Polynomial* Pa, Polynomial* Pb) {
    Polynomial Pc, Ptmp;
    int i, j, la, lb;
    EPosition ha, hb;
    EPosition qa, qb;
    ELink s;
    ElemType e;

    la = PolynLength(*Pa);
    lb = PolynLength(*Pb);

    ha = GetElinkListHead(*Pa);
    hb = GetElinkListHead(*Pb);

    // Pc初始化
    InitELinkList(&Pc);

    // 思路:从Pa中摘下a_i, 用a_i*Pb后存于tmp;然后每个tmp与Pc相加。
    for(i=1; i<=la; i++) {
        InitELinkList(&Ptmp);
        ELinkListDeleteFirst(Pa, ha, &qa);

        for (j=1, qb=ELinkListNextPos(*Pb, hb); j<=lb; j++, qb=ELinkListNextPos(*Pb, qb)) {
            e.coef = qa->data.coef*qb->data.coef;
            e.expn = qa->data.expn+qb->data.expn;

            // 创建新的节点
            MakeNode(&s, e);
            ELinkListAppend(&Ptmp, s);
        }
        AddPolyn(&Pc, &Ptmp);
    }
    AddPolyn(Pa, &Pc);
    DestroyELinkList(Pb);
}

// 打印多项式
void PrintPolyn(Polynomial P) {
    int i;
    ELink q = P.head->next;

    for (i=1; i<=P.len; i++) {
        // 系数为零不展示
        if (q->data.coef == 0.0f) {
            continue;
        }
        if (i==1) {
            printf("%g", q->data.coef);  // 第一个不需要显示符号
        } else {
            if (q->data.coef> 0) {
                printf("+");
                printf("%g", q->data.coef);
            } else {
                //printf("-");
                printf("%g", q->data.coef);
            }
        }

        if (q->data.expn) {
            printf("x");
            if (q->data.expn != 1) {
                printf("^%d", q->data.expn);
            }
        }
        q = q->next;
    }
    printf("\n");
}

// 比较指数大小
int Cmp(ElemType e1, ElemType e2) {
    int i = e1.expn - e2.expn;
    if (i > 0) {
        return 1;
    } else if (i==0) {
        return 0;
    } else {
        return -1;
    }
}
