#ifndef WORDLIST_H
#define WRODLIST_H

#include <stdlib.h>
#include <string.h>

#include "ELinkList.h"
#include "HString.h"

#define MAXBOOKNUM   1000 // �鼮����
#define MAXKEYNUM    2500 // ����������
#define MAXLINELEN    500 // ��Ŀ���е���󳤶�
#define MAXWORDNUM     10 // ���ʱ���������

typedef Status Boolen;

// ���ʱ�
typedef struct {
	char* item[MAXWORDNUM];  // �ʱ���
	int               last;  // �ʱ���
} WordListType;

// ������
typedef struct {
	HString       key;	    // �ؼ���
	ELinkList bnolist;      // ������
} IdxTermType;

// ��������
typedef struct {
	IdxTermType item[MAXKEYNUM + 1];
	int                        last;
} IdxListType;


// ȫ�ֱ���
char gBuf[MAXLINELEN];
WordListType gWdList;

// ������
void Main(char* bookinfo, char* bookidx);

// ��ʼ��������
void InitIdxList(IdxListType* idexlist);

// ��ȡ��Ŀ��Ϣ
void GetLine(FILE* f);

// ��ȡ�ؼ���
void ExtractKeyWord(ElemType* bno);


// ����������
Status InsIdxList(IdxListType* idxlist, int bno);

// ���عؼ���
void GetWord(int i, HString* wd);

// ����
int Locate(IdxListType idxlist, HString wd, Boolen* b);

// ����ؼ���
void InsertNewKey(IdxListType* idxlist, int i, HString wd);

// �����鼮���
Status InsertBook(IdxListType* idxlist, int i, int bno);

// �����Ϣ
void PutText(FILE* g, IdxListType idxlist);

// �ж��Ƿ�Ϊ���õ�
static Status isCommonWords(char* str);

#endif // !WORDLIST_H
