#include "SqQueue.h"


// ��ʼ��
Status InitSqQueue(SqQueue* Q) {
	// ȷ������
	if (!Q) {
		return ERROR;
	}

	Q->base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q->base) {
		exit(OVERFLOW);
	}

	Q->front = Q->rear = 0;
	return OK;
}

// ����
Status DestroySqQueue(SqQueue* Q) {
	// ȷ������
	if (!Q || !Q->base) {
		return ERROR;
	}

	free(Q->base);
	Q->front = Q->rear = 0;
	return OK;
}

// �ÿ�
Status ClearSqQueue(SqQueue* Q) {
	// ȷ������
	if (!Q || !Q->base) {
		return ERROR;
	}

	Q->front = Q->rear = 0;
	return OK;
}

// �п�
Status SqQueueEmpty(SqQueue Q) {
	return Q.front == Q.rear ? TRUE : FALSE;
}


// ����
int SqQueueLength(SqQueue Q) {
	// ȷ����Ϊ��
	if (!Q.base) {
		return 0;
	}
	return (Q.front - Q.rear + MAXQSIZE) % MAXQSIZE;
}

// ��ȡ��ͷԪ��
Status SqQueueGetHead(SqQueue Q, QElemType* e) {
	// ȷ����Ϊ��
	if (!Q.base || Q.front == Q.rear) {
		return ERROR;
	}

	*e = Q.base[Q.front];
	return OK;
}

// ���
Status EnSqQueue(SqQueue* Q, QElemType e) {
	// ȷ������
	if (!Q || !Q->base) {
		return ERROR;
	}

	// �������˾Ͳ��ܲ���
	if ((Q->rear + 1) % MAXQSIZE == Q->rear) {
		return ERROR;
	}
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
	return OK;
}

// ����
Status DeSqQueue(SqQueue* Q, QElemType* e) {
	// ȷ�������Ҳ�Ϊ��
	if (!Q || !Q->base || Q->front == Q->rear) {
		return ERROR;
	}

	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
	return OK;
}

// ����
Status SqQueueTraverse(SqQueue Q, void(Vist)(QElemType e)) {
	// ȷ������
	if (!Q.base || Q.front == Q.rear) {
		return ERROR;
	}

	int i = Q.front;
	while (i < Q.rear) {
		Vist(Q.base[i]);
		i = (i + 1) % MAXQSIZE;
	}
	printf("\n");
	return OK;
}