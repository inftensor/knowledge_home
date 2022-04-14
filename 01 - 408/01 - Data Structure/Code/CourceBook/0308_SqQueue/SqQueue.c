#include "SqQueue.h"


// 初始化
Status InitSqQueue(SqQueue* Q) {
	// 确保存在
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

// 销毁
Status DestroySqQueue(SqQueue* Q) {
	// 确保存在
	if (!Q || !Q->base) {
		return ERROR;
	}

	free(Q->base);
	Q->front = Q->rear = 0;
	return OK;
}

// 置空
Status ClearSqQueue(SqQueue* Q) {
	// 确保存在
	if (!Q || !Q->base) {
		return ERROR;
	}

	Q->front = Q->rear = 0;
	return OK;
}

// 判空
Status SqQueueEmpty(SqQueue Q) {
	return Q.front == Q.rear ? TRUE : FALSE;
}


// 长度
int SqQueueLength(SqQueue Q) {
	// 确保不为空
	if (!Q.base) {
		return 0;
	}
	return (Q.front - Q.rear + MAXQSIZE) % MAXQSIZE;
}

// 获取队头元素
Status SqQueueGetHead(SqQueue Q, QElemType* e) {
	// 确保不为空
	if (!Q.base || Q.front == Q.rear) {
		return ERROR;
	}

	*e = Q.base[Q.front];
	return OK;
}

// 入队
Status EnSqQueue(SqQueue* Q, QElemType e) {
	// 确保存在
	if (!Q || !Q->base) {
		return ERROR;
	}

	// 队列满了就不能插入
	if ((Q->rear + 1) % MAXQSIZE == Q->rear) {
		return ERROR;
	}
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
	return OK;
}

// 出队
Status DeSqQueue(SqQueue* Q, QElemType* e) {
	// 确保存在且不为空
	if (!Q || !Q->base || Q->front == Q->rear) {
		return ERROR;
	}

	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
	return OK;
}

// 遍历
Status SqQueueTraverse(SqQueue Q, void(Vist)(QElemType e)) {
	// 确保存在
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