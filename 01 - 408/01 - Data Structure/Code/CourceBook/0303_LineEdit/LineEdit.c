#include "LineEdit.h"


// 模拟文本编辑: #表示上一个无效，@表示整行无效
void LineEdit(char buffer[]) {
	SqStack S;
	InitSqStack(&S);
	int i = 0;
	char ch = buffer[i++];
	SElemType e;

	//while (ch != 'EOF') {
	while (ch != '\0') {
		switch (ch) {
			case '#': 
				SqStackPop(&S, &e);
				break;

			case '@':
				ClearSqStack(&S, &e);
				break;
			default:
				SqStackPush(&S, ch);
		}
		ch = buffer[i++];
	}
	SqStackTraverse(S, PrintElem);  // 这里只模拟一行输入

	// 回收
	DestroySqStack(&S);
}

// 打印元素
void PrintElem(SElemType e) {
	printf("%c ", e);
}