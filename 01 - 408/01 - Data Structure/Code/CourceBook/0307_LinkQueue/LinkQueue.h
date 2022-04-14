#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <stdlib.h>
#include "Status.h"

typedef int QElemType;

typedef struct QNode{
	QElemType     data;  
	struct QNode* next;
}QNode, *QueuePtr;

// 定义队列
typedef struct {
	QueuePtr front;  // 队头
	QueuePtr  rear;  // 队尾
}LinkQueue;

// 初始化
Status InitLinkQueue(LinkQueue* Q);

// 销毁
Status DestroyLinkQueue(LinkQueue* Q);

// 置空
Status ClearLinkQueue(LinkQueue* Q);

// 判空
Status LinkQueueEmpty(LinkQueue Q);

// 长度
int LinkQueueLength(LinkQueue Q);

// 获取队头元素
Status LinkQueueGetHead(LinkQueue Q, QElemType* e);

// 入队
Status EnLinkQueue(LinkQueue* Q, QElemType e);

// 出队
Status DeLinkQueue(LinkQueue* Q, QElemType* e);

// 遍历
Status LinkQueueTraverse(LinkQueue Q, void(Vist)(QElemType e));

#endif // !LINKQUEUE_H
