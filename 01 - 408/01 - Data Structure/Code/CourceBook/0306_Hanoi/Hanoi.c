#include "Hanoi.h"


// ����ȫ�ֱ���
Tower   T;   //��ŵ��
int Gstep = 0;   // ����

// �ƶ���ŵ�� yΪ������, ��x��ǰ��n��Բ���ƶ���z��
void hanoi(int n, char x, char y, char z) {
	if (n == 1) {
		move(x, 1, z);
	}	else {
		hanoi(n - 1, x, z, y); // ��x�ϵ�1��n-1�ƶ���y, z������
		move(x, n, z);
	    hanoi(n - 1, y, x, z);
	}
}

// ��n��x�ƶ���z
void move(char x, int n, char z) {
	Gstep++;
	printf("��%d��: ���� %2d ��Բ�̴� %c �ƶ��� %c \n", Gstep, n, x, z);
}