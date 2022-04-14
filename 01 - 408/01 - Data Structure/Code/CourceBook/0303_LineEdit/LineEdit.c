#include "LineEdit.h"


// ģ���ı��༭: #��ʾ��һ����Ч��@��ʾ������Ч
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
	SqStackTraverse(S, PrintElem);  // ����ֻģ��һ������

	// ����
	DestroySqStack(&S);
}

// ��ӡԪ��
void PrintElem(SElemType e) {
	printf("%c ", e);
}