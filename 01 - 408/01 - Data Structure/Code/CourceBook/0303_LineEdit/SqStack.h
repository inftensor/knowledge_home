#ifndef SQSTACK_H
#define SQSTACK_H

#include "Status.h"
#include <stdlib.h>

#define STACK_INIT_SIZE  100  // 栈初始空间
#define STACKINCREMENT    10  // 增量

typedef int SElemType;

typedef struct {
    SElemType *base; // 栈底
    SElemType  *top; // 栈顶
    int   stacksize; // 已分配存储空间
} SqStack;

// 初始化
Status InitSqStack(SqStack* S);

// 销毁
Status DestroySqStack(SqStack *S);

// 置空
Status ClearSqStack(SqStack* S);

// 判空
Status SqStackEmpty(SqStack S);

// 长度
int SqStackLength(SqStack S);

// 栈顶元素
Status GetSqStackTop(SqStack S, SElemType* e);

// 入栈
Status SqStackPush(SqStack* S, SElemType e);

// 出栈
Status SqStackPop(SqStack* S, SElemType* e);

// 遍历
Status SqStackTraverse(SqStack S, void(Visit)(SElemType e));

#endif