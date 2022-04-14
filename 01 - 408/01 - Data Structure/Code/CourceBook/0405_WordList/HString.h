#ifndef HSTRING_H
#define HSTRING_H

#include <stdlib.h>
#include "Status.h"



typedef struct{
	char*   ch;
	int length;
} HString;

// ��ʼ��
Status AssignHString(HString* T, const char* words, int len_words);

// // ����
// Status DestoryHString(HString S);

// �ÿ�
Status ClearHString(HString* S);

// �п�
Status HStringEmpty(HString S);

// ����
int HStringLength(HString S);

// �Ӵ�
Status SubHString(HString* Sub, HString S, int pos, int len);

// // �״γ���(�����Ӵ�)
// int IndexOfHString1(HString S, HString T, int pos);

// // �״γ���(�������Ӵ�)
// int IndexOfHString2(HString S, HString T, int pos);
// �״γ���(�������Ӵ�)
int IndexOfHString(HString S, HString T, int pos);

// ����
Status HStringInsert(HString* S, int pos, HString T);

// ɾ��
Status HStringDelete(HString* S, int pos, int len);

// �Ƚϴ�
int HStringCmp(HString S, HString T);

// ����
Status HStringCopy(HString* T, HString S);

// �滻
Status HStringReplace(HString* S, HString T, HString V);

// ����
Status HStringConcat(HString* T, HString S1, HString S2);

#endif // !HSTRING_H
