#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "ELinkList.h"

typedef ELinkList Polynomial;

// 创建多项式
void CreatePolyn(Polynomial* P, int m, int* expns, float* coefs);  // 这里直接从数组获取

// 销毁多项式
void DestroyPolyn(Polynomial* P);

// 返回项数
int PolynLength(Polynomial P);

// 多项式相加
void AddPolyn(Polynomial* Pa, Polynomial* Pb);

// 多项式相减
void SubtractPolyn(Polynomial* Pa, Polynomial* Pb);

// 多项式相乘
void MuliplyPolyn(Polynomial* Pa, Polynomial* Pb);


// 打印多项式
void PrintPolyn(Polynomial P);

// 比较指数大小
int Cmp(ElemType e1, ElemType e2);

#endif // !POLYNOMIAL_H
