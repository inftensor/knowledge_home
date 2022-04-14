#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "ELinkList.h"

typedef ELinkList Polynomial;

// ��������ʽ
void CreatePolyn(Polynomial* P, int m, int* expns, float* coefs);  // ����ֱ�Ӵ������ȡ

// ���ٶ���ʽ
void DestroyPolyn(Polynomial* P);

// ��������
int PolynLength(Polynomial P);

// ����ʽ���
void AddPolyn(Polynomial* Pa, Polynomial* Pb);

// ����ʽ���
void SubtractPolyn(Polynomial* Pa, Polynomial* Pb);

// ����ʽ���
void MuliplyPolyn(Polynomial* Pa, Polynomial* Pb);


// ��ӡ����ʽ
void PrintPolyn(Polynomial P);

// �Ƚ�ָ����С
int Cmp(ElemType e1, ElemType e2);

#endif // !POLYNOMIAL_H
