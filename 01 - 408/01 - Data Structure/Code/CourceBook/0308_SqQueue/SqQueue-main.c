#include "SqQueue.h"


// ��ӡԪ��
void PrintEem(QElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {
    SqQueue Q;
    int i;
    QElemType e;

    // ��ʼ������
    InitSqQueue(&Q);
    // �пղ���
    printf("S�Ƿ�Ϊ��?%d\n", SqQueueEmpty(Q));

    // ��ջ����
    for (i = 0; i < 10; i++) {
        EnSqQueue(&Q, i * i+3);
    }
    printf("Q = ");
    SqQueueTraverse(Q, PrintEem);
    // ���Ȳ���
    printf("Q�ĳ���Ϊ%d\n", SqQueueLength(Q));
    // ����ͷ����
    SqQueueGetHead(Q, &e);
    printf("����ͷԪ��Ϊ%d\n", e);

    // ���Ӳ���
    while (!SqQueueEmpty(Q)) {
        DeSqQueue(&Q, &e);
        printf("��ǰ����%d\n", e);
    }
}