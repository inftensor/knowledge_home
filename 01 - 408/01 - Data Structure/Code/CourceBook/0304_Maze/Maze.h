#ifndef MAZE_H
#define MAZE_H


#include "SqStack.h"

#define M  7  // �Թ�����
#define N  7  // �Թ�����


typedef enum {
	Wall,                         // ��ǽ
	Obstacle,                     // �Թ��ڲ����ϰ�
	Way,                          // ͨ·
    Impasse,                      // ����ͬ
    East,Sounth,West, North       // ̽������
} MazeNode;

typedef int MazeType[M][N];       // �Թ�����

// Ѱ·
Status MazePath(MazeType maze, PosType start, PosType end);

// �Թ���ʼ��(ͨ������n���ϰ�����)
void InitMaze(MazeType maze, int* obs_x, int* obs_y, int n);

// ֮ǰ�Ƿ�̽����
Status Pass(MazeType maze, PosType seat);

// ��ȡ��һ��Ӧ��̽����λ��
PosType NextPos(PosType seat, int di);

// �����㼣
void FootPrint(MazeType maze, PosType seat);

// ���±��
void MarkPrint(MazeType maze, PosType seat, int mark);

// ����ͨ����Ϣ
SElemType Construct(int ord, PosType seat, int di);

// �ж������Ƿ����
Status Equal(PosType a, PosType b);

// �����Թ�
void PrintMaze(MazeType maze);

#endif // !MAZE_H
