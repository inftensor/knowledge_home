#ifndef MAZE_H
#define MAZE_H


#include "SqStack.h"

#define M  7  // 迷宫行数
#define N  7  // 迷宫列数


typedef enum {
	Wall,                         // 外墙
	Obstacle,                     // 迷宫内部的障碍
	Way,                          // 通路
    Impasse,                      // 死胡同
    East,Sounth,West, North       // 探索方向
} MazeNode;

typedef int MazeType[M][N];       // 迷宫类型

// 寻路
Status MazePath(MazeType maze, PosType start, PosType end);

// 迷宫初始化(通过输入n个障碍构造)
void InitMaze(MazeType maze, int* obs_x, int* obs_y, int n);

// 之前是否探索过
Status Pass(MazeType maze, PosType seat);

// 获取下一个应该探索的位置
PosType NextPos(PosType seat, int di);

// 留下足迹
void FootPrint(MazeType maze, PosType seat);

// 留下标记
void MarkPrint(MazeType maze, PosType seat, int mark);

// 构造通道信息
SElemType Construct(int ord, PosType seat, int di);

// 判断坐标是否相等
Status Equal(PosType a, PosType b);

// 绘制迷宫
void PrintMaze(MazeType maze);

#endif // !MAZE_H
