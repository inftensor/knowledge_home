#ifndef LSTRING_H
#define LSTRING_H

#include <stdlib.h>
#include "Status.h"

#define CHUNKSIZE 3 // 块的大小

typedef struct {
	char ch[CHUNKSIZE]; // 块
	struct Chunk* next; // 下一个位置
} Chunk;


typedef struct {
	Chunk* head;
	Chunk* tail;
	int  curlen;
} LString;

// 初始化
Status AssignLString(LString* T, const char* words, int len_words);

// // 销毁
// Status DestoryLString(LString S);

// 置空
Status ClearLString(LString* S);

// 判空
Status LStringEmpty(LString S);

// 长度
int LStringLength(LString S);

// 子串
Status SubLString(LString* Sub, LString S, int pos, int len);

// // 首次出现(依赖子串)
// int IndexOfLString1(LString S, LString T, int pos);

// // 首次出现(不依赖子串)
// int IndexOfLString2(LString S, LString T, int pos);
// 首次出现(依赖子串)
int IndexOfLString(LString S, LString T, int pos);

// 插入
Status LStringInsert(LString* S, int pos, LString T);

// 删除
Status LStringDelete(LString* S, int pos, int len);

// 比较串
int LStringCmp(LString S, LString T);

// 复制
Status LStringCopy(LString* T, LString S);

// 替换
Status LStringReplace(LString* S, LString T, LString V);

// 连接
Status LStringConcat(LString* T, LString S1, LString S2);

#endif // !LSTRING_H
