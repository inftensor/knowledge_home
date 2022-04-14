#include "Expression.h"


// 计算表达式
OperandType EvaluateExpression(const char expr[]) {
	SElemType c;  // 输入序列
	SElemType t;  // 栈顶元素

	SqStack OPTR; // 运算符栈
	SqStack OPND; // 操作数栈

	OperatorType theta, x;
	OperandType a, b;
	int i = 0;

	InitSqStack(&OPTR);
	SqStackPush(&OPTR, '#');  // 界限符号
	InitSqStack(&OPND);
	c = expr[i++];
    

	while (c!='#' || (GetSqStackTop(OPTR, &t) && t != '#')) {
		if (!In(c)) { // 不是运算符(即为运算数)
			SqStackPush(&OPND, c);
			c = expr[i++];
		} else {
			GetSqStackTop(OPTR, &t);
			switch(Precede(t, c)) {
				case '<':
					SqStackPush(&OPTR, c);
					c = expr[i++];
					break;
				case '=':     // 遇到括号，直接弹出
					SqStackPop(&OPTR, &x);
					c = expr[i++];
					break;
				case '>':	 // 优先级高的先运算
					SqStackPop(&OPTR, &theta);
					SqStackPop(&OPND, &b);
					SqStackPop(&OPND, &a);
					SqStackPush(&OPND, Operate(a, theta, b));  // 运算结果并压入栈
					break;
			}
		}
	}
	GetSqStackTop(OPND, &t);
	return t;
}

// 判定运算符是否合规
Status In(SElemType c) {
	return strchr(OP, c) ? TRUE : FALSE;
}


// 判断优先级
OperatorType Precede(OperatorType o1, OperandType o2) {
	int x, y;
	// 获取两个符号所在OP的位置
	char* p1 = strchr(OP, o1);
	char* p2 = strchr(OP, o2);

	x = p1 - OP;
	y = p2 - OP;
	return PrecedeTable[x][y];
}


// 进行运算
OperandType Operate(OperandType a, OperatorType theta, OperandType b) {
	int x, y, z = CHAR_MAX - 48;
	// 字符转为整形
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

	// 整形转为字符
	return  z + 48;
}