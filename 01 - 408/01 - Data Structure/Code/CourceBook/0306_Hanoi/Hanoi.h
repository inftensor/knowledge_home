#ifndef HANOI_H
#define HANOI_H

#include "Status.h"


typedef struct {
	int** palates;  // 盘子信息
	int	  high[3];  // 三座塔的高度
} Tower;

// 移动汉诺塔 y为辅助塔, 将x塔前的n个圆盘移动到z塔
void hanoi(int n, char x, char y, char z);

// 将n从x移动到z
void move(char x, int n, char z);

#endif // !HANOI_H
