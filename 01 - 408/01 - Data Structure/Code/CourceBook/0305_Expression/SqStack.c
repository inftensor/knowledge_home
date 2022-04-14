#include "SqStack.h"


// 初始化
Status InitSqStack(SqStack* S) {
    // 确保存在
    if (!S) {
        return ERROR;
    }
    S->base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if (!S->base) {
        // 内存分配失败
        exit(OVERFLOW);
    }

    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

// 销毁
Status DestroySqStack(SqStack *S) {
    // 确保存在
    if (!S) {
        return ERROR;
    }

    free(S->base);
    S->base = S->top = NULL;
    S->stacksize = 0;
    return OK;
}

// 置空
Status ClearSqStack(SqStack* S) {
    // 确保存在
    if (!S || !S->base) {
        return ERROR;
    }

    S->top = S->base;
    return OK;
}


// 判空
Status SqStackEmpty(SqStack S) {
    // 确保存在
    if (!S.base) {
        return ERROR;
    }

    return S.top==S.base ? TRUE : FALSE;
}


// 长度
int SqStackLength(SqStack S) {
    // 确保存在
    if (!S.base) {
        return 0;
    }
    return (int)(S.top-S.base);
}

// 栈顶元素
Status GetSqStackTop(SqStack S, SElemType* e) {
    // 确保存在且不为空
    if (!S.base || S.top==S.base) {
        return ERROR;
    }
    *e = *(S.top-1);
    return OK;
}


// 入栈
Status SqStackPush(SqStack* S, SElemType e) {
    // 确保存在
    if (!S || !S->base) {
        return ERROR;
    }
    // 栈满时，扩容
    if (S->top-S->base >= S->stacksize) {
        S->base = (SElemType*)realloc(S->base, (S->stacksize+STACKINCREMENT)*sizeof(SElemType));
        if (!S->base) {
            exit(OVERFLOW);
        }

        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    // 入栈先赋值，栈顶指针再移动
    *(S->top++) = e;
    return OK;
}


// 出栈
Status SqStackPop(SqStack* S, SElemType* e) {
    // 确保不为空
    if (!S || !S->base || S->base==S->top) {
        return ERROR;
    }
    // 出栈先移动指针，在赋值
    *e = *(--S->top);
}

// 遍历
Status SqStackTraverse(SqStack S, void(Visit)(SElemType e)) {
    // 确保存在
    if (!S.base || S.base==S.top) {
        return ERROR;
    }

    SElemType* p = S.base;
    while (p < S.top) {
        Visit(*p++);
    }
    printf("\n");
}