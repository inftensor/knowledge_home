#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <stdlib.h>
#include "Status.h"

typedef int QElemType;

typedef struct QNode{
	QElemType     data;  
	struct QNode* next;
}QNode, *QueuePtr;

// �������
typedef struct {
	QueuePtr front;  // ��ͷ
	QueuePtr  rear;  // ��β
}LinkQueue;

// ��ʼ��
Status InitLinkQueue(LinkQueue* Q);

// ����
Status DestroyLinkQueue(LinkQueue* Q);

// �ÿ�
Status ClearLinkQueue(LinkQueue* Q);

// �п�
Status LinkQueueEmpty(LinkQueue Q);

// ����
int LinkQueueLength(LinkQueue Q);

// ��ȡ��ͷԪ��
Status LinkQueueGetHead(LinkQueue Q, QElemType* e);

// ���
Status EnLinkQueue(LinkQueue* Q, QElemType e);

// ����
Status DeLinkQueue(LinkQueue* Q, QElemType* e);

// ����
Status LinkQueueTraverse(LinkQueue Q, void(Vist)(QElemType e));

#endif // !LINKQUEUE_H
