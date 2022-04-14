#ifndef HANOI_H
#define HANOI_H

#include "Status.h"


typedef struct {
	int** palates;  // ������Ϣ
	int	  high[3];  // �������ĸ߶�
} Tower;

// �ƶ���ŵ�� yΪ������, ��x��ǰ��n��Բ���ƶ���z��
void hanoi(int n, char x, char y, char z);

// ��n��x�ƶ���z
void move(char x, int n, char z);

#endif // !HANOI_H
