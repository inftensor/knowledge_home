#ifndef WORDLIST_H
#define WRODLIST_H

#include <stdlib.h>
#include <string.h>

#include "ELinkList.h"
#include "HString.h"

#define MAXBOOKNUM   1000 // 书籍容量
#define MAXKEYNUM    2500 // 索引表容量
#define MAXLINELEN    500 // 数目串行的最大长度
#define MAXWORDNUM     10 // 单词表的最大容量

typedef Status Boolen;

// 单词表
typedef struct {
	char* item[MAXWORDNUM];  // 词表集合
	int               last;  // 词表长度
} WordListType;

// 索引表
typedef struct {
	HString       key;	    // 关键词
	ELinkList bnolist;      // 存放书号
} IdxTermType;

// 索引类型
typedef struct {
	IdxTermType item[MAXKEYNUM + 1];
	int                        last;
} IdxListType;


// 全局变量
char gBuf[MAXLINELEN];
WordListType gWdList;

// 主函数
void Main(char* bookinfo, char* bookidx);

// 初始化索引表
void InitIdxList(IdxListType* idexlist);

// 读取数目信息
void GetLine(FILE* f);

// 提取关键词
void ExtractKeyWord(ElemType* bno);


// 插入索引表
Status InsIdxList(IdxListType* idxlist, int bno);

// 返回关键词
void GetWord(int i, HString* wd);

// 查找
int Locate(IdxListType idxlist, HString wd, Boolen* b);

// 插入关键词
void InsertNewKey(IdxListType* idxlist, int i, HString wd);

// 插入书籍序号
Status InsertBook(IdxListType* idxlist, int i, int bno);

// 输出信息
void PutText(FILE* g, IdxListType idxlist);

// 判断是否为常用的
static Status isCommonWords(char* str);

#endif // !WORDLIST_H
