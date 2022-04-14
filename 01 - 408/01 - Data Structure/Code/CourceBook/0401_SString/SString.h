#ifndef SSTRING_H
#define SSTRING_H

#include "Status.h"

#define MAXSTRLEN  255   // 顺序串的最大长度

typedef unsigned char SString[MAXSTRLEN+1];

// 初始化
Status AssignSString(SString T, const char* words, int len_words);

// // 销毁
// Status DestorySString(SString S);

// 置空
Status ClearSString(SString S);

// 判空
Status SStringEmpty(SString S);

// 长度
int SStringLength(SString S);

// 子串
Status SubSString(SString Sub, SString S, int pos, int len);

// 首次出现(依赖子串)
int IndexOfSString1(SString S, SString T, int pos);

// 首次出现(不依赖子串)
int IndexOfSString2(SString S, SString T, int pos);

// 插入
Status SStringInsert(SString S, int pos, SString T);

// 删除
Status SStringDelete(SString S, int pos, int len);

// 比较串
int SStringCmp(SString S, SString T);

// 复制
Status SStringCopy(SString T, SString S);

// 替换
Status SStringReplace(SString S, SString T, SString V);

// 连接
Status SStringConcat(SString T, SString S1, SString S2);

#endif // !SSTRING_H
