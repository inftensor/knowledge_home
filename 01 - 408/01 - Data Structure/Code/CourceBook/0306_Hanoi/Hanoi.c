#include "Hanoi.h"


// 定义全局变量
Tower   T;   //汉诺塔
int Gstep = 0;   // 步数

// 移动汉诺塔 y为辅助塔, 将x塔前的n个圆盘移动到z塔
void hanoi(int n, char x, char y, char z) {
	if (n == 1) {
		move(x, 1, z);
	}	else {
		hanoi(n - 1, x, z, y); // 将x上的1至n-1移动到y, z做辅助
		move(x, n, z);
	    hanoi(n - 1, y, x, z);
	}
}

// 将n从x移动到z
void move(char x, int n, char z) {
	Gstep++;
	printf("第%d步: 将第 %2d 个圆盘从 %c 移动到 %c \n", Gstep, n, x, z);
}