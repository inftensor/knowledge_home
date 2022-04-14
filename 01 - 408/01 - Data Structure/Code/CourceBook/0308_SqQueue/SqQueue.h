#ifndef SQQUEUE_H
#define SQQUEUE_H

#include <stdlib.h>
#include "Status.h"

#define MAXQSIZE 1000   // 最大长度

typedef int QElemType;

typedef struct {
	QElemType* base;  // 
	int       front;
	int        rear;
} SqQueue;


// 初始化
Status InitSqQueue(SqQueue* Q);

// 销毁
Status DestroySqQueue(SqQueue* Q);

// 置空
Status ClearSqQueue(SqQueue* Q);

// 判空
Status SqQueueEmpty(SqQueue Q);

// 长度
int SqQueueLength(SqQueue Q);

// 获取队头元素
Status SqQueueGetHead(SqQueue Q, QElemType* e);

// 入队
Status EnSqQueue(SqQueue* Q, QElemType e);

// 出队
Status DeSqQueue(SqQueue* Q, QElemType* e);

// 遍历
Status SqQueueTraverse(SqQueue Q, void(Vist)(QElemType e));

#endif // !SQQUEUE_H
