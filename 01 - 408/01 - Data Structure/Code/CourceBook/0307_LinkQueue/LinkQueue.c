#include "LinkQueue.h"


// ��ʼ������ͷ��㣩
Status InitLinkQueue(LinkQueue* Q) {
	// ȷ������
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

// ����
Status DestroyLinkQueue(LinkQueue* Q) {
	// ȷ������
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

// �ÿ�
Status ClearLinkQueue(LinkQueue* Q) {
	// ȷ������
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

// �п�
Status LinkQueueEmpty(LinkQueue Q) {
	return Q.front == Q.rear ? TRUE : FALSE;
}


// ����
int LinkQueueLength(LinkQueue Q) {
	int count = 0;
	QueuePtr p = Q.front;
	while (p) {
		p = p->next;
		count++;
	}
	return count;
}

// ��ȡ��ͷԪ��
Status LinkQueueGetHead(LinkQueue Q, QElemType* e) {
	// ȷ�������Ҳ�Ϊ��
	if (!Q.front || Q.front == Q.rear) {
		return ERROR;
	}
	*e = Q.front->next->data;
	return OK;
}

// ���
Status EnLinkQueue(LinkQueue* Q, QElemType e) {
	// ȷ������
	if (!Q || !Q->front) {
		return ERROR;
	}

	// �����½ڵ�
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) {
		// �ڴ����ʧ��
		exit(OVERFLOW);
	}
	p->data = e;
	p->next = NULL;

	Q->rear->next = p;
	Q->rear = p;

	return OK;
}

// ����
Status DeLinkQueue(LinkQueue* Q, QElemType* e) {
	// ȷ�������Ҳ�Ϊ��
	if (!Q || !Q->front || Q->front == Q->rear ) {
		return ERROR;
	}

	QueuePtr p = Q->front->next; // ��һ��Ԫ��
	*e = p->data;

	Q->front->next = p->next;
	// ���p�Ѿ������һ��
	if (p == Q->rear) {
		Q->rear = Q->front;
	}
	free(p);
	return OK;
}

// ����
Status LinkQueueTraverse(LinkQueue Q, void(Vist)(QElemType e)) {
	// ȷ�������Ҳ�Ϊ��
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