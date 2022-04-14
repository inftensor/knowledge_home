#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string.h>				  // �ַ�����
#include "SqStack.h"

typedef SElemType OperatorType;   // �����
typedef SElemType OperandType;    // ����������

// �������
static const char OP[] = { '+', '-', '*', '/', '(', ')', '#' };

// ��������ȼ�
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


// ������ʽ
OperandType EvaluateExpression(const char exp[]);

// �ж�������Ƿ�Ϲ�
Status In(SElemType c);

// �ж����ȼ�
OperatorType Precede(OperatorType o1, OperandType o2);

// ��������
OperandType Operate(OperandType a, OperatorType theta, OperandType b);

#endif // !EXPRESSION_H
