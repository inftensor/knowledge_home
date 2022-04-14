#include "SqStack.h"


// 打印元素
void PrintEem(SElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {
    SqStack S;
    int i;
    SElemType e;

    // 初始化测试
    InitSqStack(&S);
    // 判空测试
    printf("S是否为空?%d\n", SqStackEmpty(S));
    
    // Push测试
    for (i = 0; i < 10; i++) {
        SqStackPush(&S, i * i);
    }
    printf("S = ");
    SqStackTraverse(S, PrintEem);
    // 长度测试
    printf("S的长度为%d\n", SqStackLength(S));
    // 栈顶测试
    GetSqStackTop(S, &e);
    printf("栈顶元素为%d\n", e);

    // 出栈测试
    while (!SqStackEmpty(S)) {
        SqStackPop(&S, &e);
        printf("当前弹出%d\n", e);
    }

 
}