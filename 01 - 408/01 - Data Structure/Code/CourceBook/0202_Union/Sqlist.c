#include "SqList.h"

// 初始化线性表
Status InitListSq(SqList* L) {
    L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->elem) {
        exit(OVERFLOW);
    }
    L->length = 0;                  //  空表长度为0
    L->listsize = LIST_INIT_SIZE;   //  初始存储容量
    return OK;
} // InitListSq

// 销毁线性表
Status DestroyListSq(SqList* L) {
    // 确保顺序表存在其
    if (L == NULL || L->elem == NULL) {
        return ERROR;
    }

    // 释放L的elem内存
    free(L->elem);
    // 释放后置为空指针
    L->elem = NULL;
    // 将顺序表长度和容量归零
    L->length = 0;
    L->listsize = 0;
    return OK;
}

// 线性表置空
Status ClearListSq(SqList* L) {
    if (L == NULL || L->elem == NULL) {
        return ERROR;
    }

    L->length = 0;
    return OK;
}

// 判断线性表是否为空
Status SqListEmpty(SqList L) {
    return L.length == 0 ? TRUE : FALSE;
}

// 线性表的有效元素数量
int SqListLength(SqList L) {
    return L.length;
}

// 获取第i个元素
Status GetSqElem(SqList L, int i, ElemType* e) {
    // 确保顺序表存在
    if (L.elem == NULL) {
        return ERROR;
    }

    // 确保i值合理
    if (i<1 || i>L.length) {
        return ERROR;
    }

    *e = L.elem[i - 1];
    return OK;
}

// 返回顺序表中首个与e满足compare关系的元素位置
int LocateSqElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType)) {
    // 确保顺序表存在
    if (L.elem == NULL) {
        return ERROR;
    }

    int i = 1;
    // ElemType* p=L.elem;

    // 不满足就一直后移
    while (i <= L.length && !Compare(L.elem[i - 1], e)) {
        i++;
    }

    if (i <= L.length) {
        return i;
    }
    else {
        // 未找到
        return 0;
    }
}

// 寻找cur_e元素的前驱,并返回给pre_e
Status PriorSqElem(SqList L, ElemType cur_e, ElemType* pre_e) {
    // 确保顺序表存在且元素个数大于1
    if (L.elem == NULL || L.length < 2) {
        return ERROR;
    }

    int i = 0;
    // 从第一个元素开始找
    while (i < L.length && L.elem[i] != cur_e) {
        i++;
    }

    // cur_e是首个元素，或者没找到元素cur_e
    if (i == 0 || i >= L.length) {
        return ERROR;
    }

    // 将前驱给pre_e
    *pre_e = L.elem[i - 1];

    return OK;
}

// 寻找cur_e元素的后继，并返回给next_e
Status NextSqElem(SqList L, ElemType cur_e, ElemType* next_e) {
    // 确保顺序表存在且元素个数大于1
    if (L.elem == NULL || L.length < 2) {
        return ERROR;
    }

    int i = 0;
    while (i < L.length - 1 && L.elem[i] != cur_e) {
        i++;
    }
    // cur_e是最后一个或没有找到
    if (i >= L.length - 1) {
        return ERROR;
    }
    *next_e = L.elem[i + 1];
    return OK;
}

// 在第i个位置插入元素
Status SqListInsert(SqList* L, int i, ElemType e) {
    ElemType* newbase;
    ElemType* p, * q;

    // 确保顺序表存在
    if (L == NULL || L->elem == NULL) {
        return ERROR;
    }

    // 检查i值是否越界
    if (i <1 || i> L->length + 1) {
        return ERROR;
    }

    // 如果分配空间已经满了，则增加分配
    if (L->length >= L->listsize) {
        newbase = (ElemType*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase) {
            // 存储空间分配失败
            exit(OVERFLOW);
        }
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }

    // 找到插入的位置
    q = &(L->elem[i - 1]);

    // 插入位置后的元素右移
    for (p = &(L->elem[L->length - 1]); p >= q; p--) {
        *(p + 1) = *(p);
    }

    // 插入e
    *q = e;

    // 表长度加1
    L->length++;

    return OK;
}

// 删除第i个位置的元素,并将删除元素赋给e
Status SqListDelete(SqList* L, int i, ElemType* e) {
    ElemType* p, * q;

    // 确保顺序表存在
    if (L == NULL || L->elem == NULL) {
        return ERROR;
    }

    // 确保i值合法
    if (i<1 || i>L->length) {
        return ERROR;
    }
    // 获取被删除元素并赋予e
    p = &(L->elem[i - 1]);
    *e = *p;
    // 表尾元素
    q = L->elem + L->length - 1;
    // 被删除元素后每个左移一位
    for (++p; p <= q; ++p) {
        *(p - 1) = *p;
    }

    // 表长度减1
    L->length--;
    return OK;
}

// 用visit 函数访问顺序表L
void SqListTraverse(SqList L, void(Visit)(ElemType)) {
    int i;

    for (i = 0; i < L.length; i++) {
        Visit(L.elem[i]);
    }
}