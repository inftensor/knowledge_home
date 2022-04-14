#include "KMP.h"


// KMP模式匹配
int IndexKMP(SString S, SString T, int pos, int next[]) {
	// 确保合理
	if (pos <1 || pos > S[0] ) {
		return 0;
	}
	int i = pos;
	int j = 1;
	while (i <= S[0] && j <= T[0]) {
		if (j == 0 || S[i] == T[j]) { // 匹配成功
			i++;
			j++;
		} else { // 匹配失败，j后移
			j = next[j]; 
		}
	}
	if (j > T[0]) { // 已经找到
		return i - T[0];
	}
	return 0;  // 未找到
}

// 求KMP所需的next
void getNext(SString T, int* next) {
	int i = 1;  
	int j = 0;

	next[1] = 0;  // 第一个失效
	while (i < T[0]) {
		if (j == 0 || T[i] == T[j]) {
			i++;
			j++;
			next[i] = j;
		} else {
			j = next[j];
		}
	}
	return;
}

void getNextval(SString T, int* nextval) {
	int i = 1;
	int j = 0;
	nextval[1] = 0;
	while (i < T[0]) {
		if (j == 0 || T[i] == T[j]) {
			i++;
			j++;
			if (T[i] != T[j]) {
				nextval[i] = j;
			}  else {
				nextval[i] = nextval[j];
			}
		}  else {
			j = nextval[j];
		}
	}
}