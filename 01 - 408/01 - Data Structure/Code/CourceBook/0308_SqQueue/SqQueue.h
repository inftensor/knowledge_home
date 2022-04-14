#ifndef SQQUEUE_H
#define SQQUEUE_H

#include <stdlib.h>
#include "Status.h"

#define MAXQSIZE 1000   // ��󳤶�

typedef int QElemType;

typedef struct {
	QElemType* base;  // 
	int       front;
	int        rear;
} SqQueue;


// ��ʼ��
Status InitSqQueue(SqQueue* Q);

// ����
Status DestroySqQueue(SqQueue* Q);

// �ÿ�
Status ClearSqQueue(SqQueue* Q);

// �п�
Status SqQueueEmpty(SqQueue Q);

// ����
int SqQueueLength(SqQueue Q);

// ��ȡ��ͷԪ��
Status SqQueueGetHead(SqQueue Q, QElemType* e);

// ���
Status EnSqQueue(SqQueue* Q, QElemType e);

// ����
Status DeSqQueue(SqQueue* Q, QElemType* e);

// ����
Status SqQueueTraverse(SqQueue Q, void(Vist)(QElemType e));

#endif // !SQQUEUE_H
