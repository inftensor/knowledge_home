#ifndef LINEEDIT_H
#define LINEEDIT_H

#include "SqStack.h"

#ifndef EOF
#define EOF
#define EOF = '\0';
#endif // !EOF

// ģ���ı��༭: #��ʾ��һ����Ч��@��ʾ������Ч
void LineEdit(char buffer[]);

// ��ӡԪ��
void PrintElem(SElemType e);

#endif // !LINEEDIT_H
