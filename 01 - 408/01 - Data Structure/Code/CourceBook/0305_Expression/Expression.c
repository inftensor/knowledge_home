#include "Expression.h"


// ������ʽ
OperandType EvaluateExpression(const char expr[]) {
	SElemType c;  // ��������
	SElemType t;  // ջ��Ԫ��

	SqStack OPTR; // �����ջ
	SqStack OPND; // ������ջ

	OperatorType theta, x;
	OperandType a, b;
	int i = 0;

	InitSqStack(&OPTR);
	SqStackPush(&OPTR, '#');  // ���޷���
	InitSqStack(&OPND);
	c = expr[i++];
    

	while (c!='#' || (GetSqStackTop(OPTR, &t) && t != '#')) {
		if (!In(c)) { // ���������(��Ϊ������)
			SqStackPush(&OPND, c);
			c = expr[i++];
		} else {
			GetSqStackTop(OPTR, &t);
			switch(Precede(t, c)) {
				case '<':
					SqStackPush(&OPTR, c);
					c = expr[i++];
					break;
				case '=':     // �������ţ�ֱ�ӵ���
					SqStackPop(&OPTR, &x);
					c = expr[i++];
					break;
				case '>':	 // ���ȼ��ߵ�������
					SqStackPop(&OPTR, &theta);
					SqStackPop(&OPND, &b);
					SqStackPop(&OPND, &a);
					SqStackPush(&OPND, Operate(a, theta, b));  // ��������ѹ��ջ
					break;
			}
		}
	}
	GetSqStackTop(OPND, &t);
	return t;
}

// �ж�������Ƿ�Ϲ�
Status In(SElemType c) {
	return strchr(OP, c) ? TRUE : FALSE;
}


// �ж����ȼ�
OperatorType Precede(OperatorType o1, OperandType o2) {
	int x, y;
	// ��ȡ������������OP��λ��
	char* p1 = strchr(OP, o1);
	char* p2 = strchr(OP, o2);

	x = p1 - OP;
	y = p2 - OP;
	return PrecedeTable[x][y];
}


// ��������
OperandType Operate(OperandType a, OperatorType theta, OperandType b) {
	int x, y, z = CHAR_MAX - 48;
	// �ַ�תΪ����
	x = a - '0';
	y = b - '0';

	switch (theta) {
		case '+':
			z = x + y;
			break;
		case '-':
			z = x - y;
			break;
		case '*':
			z = x * y;
			break;
		case '/':
			z = x / y;
			break;
	}

	// ����תΪ�ַ�
	return  z + 48;
}