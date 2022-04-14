#ifndef LINEEDIT_H
#define LINEEDIT_H

#include "SqStack.h"

#ifndef EOF
#define EOF
#define EOF = '\0';
#endif // !EOF

// 模拟文本编辑: #表示上一个无效，@表示整行无效
void LineEdit(char buffer[]);

// 打印元素
void PrintElem(SElemType e);

#endif // !LINEEDIT_H
