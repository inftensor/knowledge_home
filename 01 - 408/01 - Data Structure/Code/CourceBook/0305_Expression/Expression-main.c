#include "Expression.h"


int main(int argc, char** argv) {
	const char expr[] = "3*(7-2)#";
	printf("%s的计算结果是%d\n", expr, EvaluateExpression(expr)-'0');
}


