#include "LinkQueue.h"


// 打印元素
void PrintEem(QElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {
    LinkQueue Q;
    int i;
    QElemType e;

    // 初始化测试
    InitLinkQueue(&Q);
    // 判空测试
    printf("S是否为空?%d\n", LinkQueueEmpty(Q));

    // 入栈测试
    for (i = 0; i < 10; i++) {
        EnLinkQueue(&Q, i * i);
    }
    printf("Q = ");
    LinkQueueTraverse(Q, PrintEem);
    // 长度测试
    printf("Q的长度为%d\n", LinkQueueLength(Q));
    // 队列头测试
    LinkQueueGetHead(Q, &e);
    printf("队列头元素为%d\n", e);

    // 出队测试
    while (!LinkQueueEmpty(Q)) {
        DeLinkQueue(&Q, &e);
        printf("当前出队%d\n", e);
    }


}