#ifndef STATUS_H
#define STATUS_H


#include <stdio.h>


/*
   定义状态码
*/
#define TRUE        1   // 真/是
#define FALSE       0   // 假/否
#define OK          1   // 通过/成功
#define ERROR       0   // 错误/失败
#define INFEARIBLE -1   // 下溢
#define OVERFLOW   -2   // 堆栈上溢

typedef int Status;     // Status 是函数的类型,返回函数结果的状态代码

#endif