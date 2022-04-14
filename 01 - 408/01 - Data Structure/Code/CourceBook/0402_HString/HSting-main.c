#include "HString.h"

// 遍历
void PrintElme(HString S) {
	int i;
	for (i = 0; i <= S.length; i++) {
		printf("%c", S.ch[i]);
	}
	printf("\n");
}

int main(int argc, char** argv) {
	HString S, Sub, V;
	// 初始化测试
	char words[] = "hello word!";
	AssignHString(&S, words, sizeof(words) / sizeof(char) - 1);
	PrintElme(S);
	char values[] = "or";
	AssignHString(&V, values, sizeof(values) / sizeof(char) - 1);

	// 判空测试
	printf("是否为空?%d\n", HStringEmpty(S));

	// 长度测试
	printf("长度为%d\n", HStringLength(S));

	// 子串测试
	SubHString(&Sub, S, 1, 5);
	printf("S%d到%d的子串为：", 1, 5);
	PrintElme(Sub);

	// 首次出现测试
	printf("V在S中首次出现为%d\n", IndexOfHString(S, V, 1));

	// 插入测试
	HStringInsert(&S, 1, V);
	printf("当前的S = ");
	PrintElme(S);
	// 删除测试
	HStringDelete(&S, 1, 2);
	printf("当前的S = ");
	PrintElme(S);

	// 替换测试
	HStringReplace(&S, Sub, V);
	printf("替换后,S = ");
	PrintElme(S);

	// 连接测试
	printf("Sub = ");
	PrintElme(Sub);
	HStringConcat(&S, Sub, V);
	printf("连接后,S = ");
	PrintElme(S);

	// 置空测试
	ClearHString(&S);
	printf("是否为空?%d\n", HStringEmpty(S));
}

