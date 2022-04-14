#ifndef LSTRING_H
#define LSTRING_H

#include <stdlib.h>
#include "Status.h"

#define CHUNKSIZE 3 // ��Ĵ�С

typedef struct {
	char ch[CHUNKSIZE]; // ��
	struct Chunk* next; // ��һ��λ��
} Chunk;


typedef struct {
	Chunk* head;
	Chunk* tail;
	int  curlen;
} LString;

// ��ʼ��
Status AssignLString(LString* T, const char* words, int len_words);

// // ����
// Status DestoryLString(LString S);

// �ÿ�
Status ClearLString(LString* S);

// �п�
Status LStringEmpty(LString S);

// ����
int LStringLength(LString S);

// �Ӵ�
Status SubLString(LString* Sub, LString S, int pos, int len);

// // �״γ���(�����Ӵ�)
// int IndexOfLString1(LString S, LString T, int pos);

// // �״γ���(�������Ӵ�)
// int IndexOfLString2(LString S, LString T, int pos);
// �״γ���(�����Ӵ�)
int IndexOfLString(LString S, LString T, int pos);

// ����
Status LStringInsert(LString* S, int pos, LString T);

// ɾ��
Status LStringDelete(LString* S, int pos, int len);

// �Ƚϴ�
int LStringCmp(LString S, LString T);

// ����
Status LStringCopy(LString* T, LString S);

// �滻
Status LStringReplace(LString* S, LString T, LString V);

// ����
Status LStringConcat(LString* T, LString S1, LString S2);

#endif // !LSTRING_H
