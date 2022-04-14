#include <stdlib.h>
#include "KMP.h"

// 打印字符串
void PrintElem(SString S) {
	int i;
	for (i = 1; i <= S[0]; i++) {
		printf("%c", S[i]);
	}

	printf("\n");
}


int main(void) {
	char words[] = "aaabaaaab";
	char values[] = "aaaab";
	int len_words = sizeof(words) / sizeof(char) -1;   // 减1是因为c还算了 '\0'
	int len_values = sizeof(values) / sizeof(char) -1; 
	
	//int next[len_values + 1];
	int* next = (int*)malloc(sizeof(char) * (len_values + 1));  // KMP所需的next
	SString S, V;
	int j;

	// 初始化
	AssignSString(S, words, len_words);
	AssignSString(V, values, len_values);
	printf("S = ");
	PrintElem(S);
	printf("V = ");
	PrintElem(V);

	// 给出next
	//getNext(V, next);
	getNextval(V, next);
	printf("next = ");
	for (j = 1; j <= len_values; j++) {
		printf("%d ", next[j]);
	}
	printf("\n");

	printf("V在S的%d", IndexKMP(S, V, 1, next));
	free(next);
	return 0;
}