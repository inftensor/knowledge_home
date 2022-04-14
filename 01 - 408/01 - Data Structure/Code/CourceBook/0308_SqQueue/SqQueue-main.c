#include "SqQueue.h"


// 打印元素
void PrintEem(QElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {
    SqQueue Q;
    int i;
    QElemType e;

    // 初始化测试
    InitSqQueue(&Q);
    // 判空测试
    printf("S是否为空?%d\n", SqQueueEmpty(Q));

    // 入栈测试
    for (i = 0; i < 10; i++) {
        EnSqQueue(&Q, i * i+3);
    }
    printf("Q = ");
    SqQueueTraverse(Q, PrintEem);
    // 长度测试
    printf("Q的长度为%d\n", SqQueueLength(Q));
    // 队列头测试
    SqQueueGetHead(Q, &e);
    printf("队列头元素为%d\n", e);

    // 出队测试
    while (!SqQueueEmpty(Q)) {
        DeSqQueue(&Q, &e);
        printf("当前出队%d\n", e);
    }
}