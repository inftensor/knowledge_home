#include "LinkQueue.h"


// 初始化（带头结点）
Status InitLinkQueue(LinkQueue* Q) {
	// 确保存在
	if (!Q) {
		return ERROR;
	}
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front) {
		exit(OVERFLOW);
	}
	Q->front->next = NULL;
	return OK;
}

// 销毁
Status DestroyLinkQueue(LinkQueue* Q) {
	// 确保存在
	if (!Q) {
		return ERROR;
	}

	while (Q->front) {
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}

// 置空
Status ClearLinkQueue(LinkQueue* Q) {
	// 确保存在
	if (!Q) {
		return ERROR;
	}

	Q->rear = Q->front->next;
	while (Q->rear) {
		Q->front->next = Q->rear->next;
		free(Q->rear);
		Q->rear = Q->front->next;
	}
	Q->rear = Q->front;
	return OK;
}

// 判空
Status LinkQueueEmpty(LinkQueue Q) {
	return Q.front == Q.rear ? TRUE : FALSE;
}


// 长度
int LinkQueueLength(LinkQueue Q) {
	int count = 0;
	QueuePtr p = Q.front;
	while (p) {
		p = p->next;
		count++;
	}
	return count;
}

// 获取队头元素
Status LinkQueueGetHead(LinkQueue Q, QElemType* e) {
	// 确保存在且不为空
	if (!Q.front || Q.front == Q.rear) {
		return ERROR;
	}
	*e = Q.front->next->data;
	return OK;
}

// 入队
Status EnLinkQueue(LinkQueue* Q, QElemType e) {
	// 确保存在
	if (!Q || !Q->front) {
		return ERROR;
	}

	// 创建新节点
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) {
		// 内存分配失败
		exit(OVERFLOW);
	}
	p->data = e;
	p->next = NULL;

	Q->rear->next = p;
	Q->rear = p;

	return OK;
}

// 出队
Status DeLinkQueue(LinkQueue* Q, QElemType* e) {
	// 确保存在且不为空
	if (!Q || !Q->front || Q->front == Q->rear ) {
		return ERROR;
	}

	QueuePtr p = Q->front->next; // 第一个元素
	*e = p->data;

	Q->front->next = p->next;
	// 如果p已经是最后一个
	if (p == Q->rear) {
		Q->rear = Q->front;
	}
	free(p);
	return OK;
}

// 遍历
Status LinkQueueTraverse(LinkQueue Q, void(Vist)(QElemType e)) {
	// 确保存在且不为空
	if (!Q.front || Q.front == Q.rear) {
		return ERROR;
	}
	QueuePtr p = Q.front->next;
	while (p) {
		Vist(p->data);
		p = p->next;
	}
	return OK;
}