#ifndef HSTRING_H
#define HSTRING_H

#include <stdlib.h>
#include "Status.h"



typedef struct{
	char*   ch;
	int length;
} HString;

// 初始化
Status AssignHString(HString* T, const char* words, int len_words);

// // 销毁
// Status DestoryHString(HString S);

// 置空
Status ClearHString(HString* S);

// 判空
Status HStringEmpty(HString S);

// 长度
int HStringLength(HString S);

// 子串
Status SubHString(HString* Sub, HString S, int pos, int len);

// // 首次出现(依赖子串)
// int IndexOfHString1(HString S, HString T, int pos);

// // 首次出现(不依赖子串)
// int IndexOfHString2(HString S, HString T, int pos);
// 首次出现(不依赖子串)
int IndexOfHString(HString S, HString T, int pos);

// 插入
Status HStringInsert(HString* S, int pos, HString T);

// 删除
Status HStringDelete(HString* S, int pos, int len);

// 比较串
int HStringCmp(HString S, HString T);

// 复制
Status HStringCopy(HString* T, HString S);

// 替换
Status HStringReplace(HString* S, HString T, HString V);

// 连接
Status HStringConcat(HString* T, HString S1, HString S2);

#endif // !HSTRING_H
