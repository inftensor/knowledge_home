#ifndef KMP_H
#define KMP_H

#include "SString.h"

// KMP模式匹配
int IndexKMP(SString S, SString T, int pos, int next[]);


// 求KMP所需的next
void getNext(SString T, int* next);

void getNextval(SString T, int* nextval);
#endif // !KMP_H
