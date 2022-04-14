#include "Conversion.h"


void Conversion(int i) {
    // 短除法
    SqStack S;
    SElemType e;
    InitSqStack(&S);

    printf("十进制数%d转为八进制为:", i);
    while (i) {
        SqStackPush(&S, i % 8);
        i /= 8;
    }
    while (!SqStackEmpty(S)) {
        SqStackPop(&S, &e);
        printf("%d", e);
    }

    // 用完即删
    DestroySqStack(&S);
}