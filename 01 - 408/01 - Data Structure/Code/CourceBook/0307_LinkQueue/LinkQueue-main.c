#include "LinkQueue.h"


// ��ӡԪ��
void PrintEem(QElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {
    LinkQueue Q;
    int i;
    QElemType e;

    // ��ʼ������
    InitLinkQueue(&Q);
    // �пղ���
    printf("S�Ƿ�Ϊ��?%d\n", LinkQueueEmpty(Q));

    // ��ջ����
    for (i = 0; i < 10; i++) {
        EnLinkQueue(&Q, i * i);
    }
    printf("Q = ");
    LinkQueueTraverse(Q, PrintEem);
    // ���Ȳ���
    printf("Q�ĳ���Ϊ%d\n", LinkQueueLength(Q));
    // ����ͷ����
    LinkQueueGetHead(Q, &e);
    printf("����ͷԪ��Ϊ%d\n", e);

    // ���Ӳ���
    while (!LinkQueueEmpty(Q)) {
        DeLinkQueue(&Q, &e);
        printf("��ǰ����%d\n", e);
    }


}