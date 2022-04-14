#ifndef SSTRING_H
#define SSTRING_H

#include "Status.h"

#define MAXSTRLEN  255   // ˳�򴮵���󳤶�

typedef unsigned char SString[MAXSTRLEN+1];

// ��ʼ��
Status AssignSString(SString T, const char* words, int len_words);

// // ����
// Status DestorySString(SString S);

// �ÿ�
Status ClearSString(SString S);

// �п�
Status SStringEmpty(SString S);

// ����
int SStringLength(SString S);

// �Ӵ�
Status SubSString(SString Sub, SString S, int pos, int len);

// �״γ���(�����Ӵ�)
int IndexOfSString1(SString S, SString T, int pos);

// �״γ���(�������Ӵ�)
int IndexOfSString2(SString S, SString T, int pos);

// ����
Status SStringInsert(SString S, int pos, SString T);

// ɾ��
Status SStringDelete(SString S, int pos, int len);

// �Ƚϴ�
int SStringCmp(SString S, SString T);

// ����
Status SStringCopy(SString T, SString S);

// �滻
Status SStringReplace(SString S, SString T, SString V);

// ����
Status SStringConcat(SString T, SString S1, SString S2);

#endif // !SSTRING_H
