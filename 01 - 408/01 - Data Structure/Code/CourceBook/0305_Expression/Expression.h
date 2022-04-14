#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string.h>				  // 字符操作
#include "SqStack.h"

typedef SElemType OperatorType;   // 运算符
typedef SElemType OperandType;    // 操作数类型

// 运算符号
static const char OP[] = { '+', '-', '*', '/', '(', ')', '#' };

// 运算符优先级
static const char PrecedeTable[7][7] =
{
	{'>', '>', '<', '<', '<', '>', '>'},
	{'>', '>', '<', '<', '<', '>', '>'},
	{'>', '>', '>', '>', '<', '>', '>'},
	{'>', '>', '>', '>', '<', '>', '>'},
	{'<', '<', '<', '<', '<', '=', ' '},
	{'>', '>', '>', '>', ' ', '>', '>'},
	{'<', '<', '<', '<', '<', ' ', '='}
};


// 计算表达式
OperandType EvaluateExpression(const char exp[]);

// 判定运算符是否合规
Status In(SElemType c);

// 判断优先级
OperatorType Precede(OperatorType o1, OperandType o2);

// 进行运算
OperandType Operate(OperandType a, OperatorType theta, OperandType b);

#endif // !EXPRESSION_H
