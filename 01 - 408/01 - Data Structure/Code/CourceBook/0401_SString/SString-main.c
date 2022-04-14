#include "SString.h"

// 遍历
void PrintElme(SString S) {
	int i;
	for (i=1; i<=S[0]; i++) {
		printf("%c", S[i]);
	}
	printf("\n");
}

int main(int argc, char** argv) {
	SString S, Sub, V;
	// 初始化测试
	char words[] = "hello word!";
	AssignSString(S, words, sizeof(words)/sizeof(char)-1);
	PrintElme(S);
	char values[] = "or";
	AssignSString(V, values, sizeof(values) / sizeof(char) - 1);

	// 判空测试
	printf("是否为空?%d\n", SStringEmpty(S));

	// 长度测试
	printf("长度为%d\n", SStringLength(S));

	// 子串测试
	SubSString(Sub, S, 1, 5);
	printf("S%d到%d的子串为：", 1, 5);
	PrintElme(Sub);

	// 首次出现测试
	printf("V在S中首次出现为%d", IndexOfSString1(S, V, 1));

	// 插入测试
	SStringInsert(S, 1, V);
	printf("当前的S = ");
	PrintElme(S);
	// 删除测试
	SStringDelete(S, 1, 2);
	printf("当前的S = ");
	PrintElme(S);

	// 替换测试
	SStringReplace(S, Sub, V);
	printf("替换后,S = ");
	PrintElme(S);

	// 连接测试
	printf("Sub = ");
	PrintElme(Sub);
	SStringConcat(S, Sub, V);
	printf("连接后,S = ");
	PrintElme(S);

	// 置空测试
	ClearSString(S);
	printf("是否为空?%d\n", SStringEmpty(S));
}