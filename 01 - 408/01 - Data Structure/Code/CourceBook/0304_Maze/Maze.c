#include "Maze.h"

// 寻路
Status MazePath(MazeType maze, PosType start, PosType end) {
    SqStack S;
    SElemType e;
    PosType curPos;
    int curStep;

    InitSqStack(&S);
    curStep = 1;
    curPos = start;

    do {
        printf("当前位置(%d, %d)\n", curPos.x, curPos.y);
        if (Pass(maze, curPos)) {
            FootPrint(maze, curPos);  // 留下足迹
            e = Construct(curStep, curPos, East);
            SqStackPush(&S, e);

            if (Equal(curPos, end)) {
                printf("寻找成功");
                PrintMaze(maze);
                return TRUE;
            } 
            curPos = NextPos(curPos, East);
            curStep++;
        } else {
            if (!SqStackEmpty(S)) {
                SqStackPop(&S, &e);
            }
            while(e.di==North && !SqStackEmpty(S)) {
                MarkPrint(maze, e.seat, Impasse);  // 死胡同
                SqStackPop(&S, &e);
            }

            if (e.di < North) {
                ++e.di;
                MarkPrint(maze, e.seat, e.di);
                SqStackPush(&S, e);
            }
            curPos = NextPos(e.seat, e.di);
        }
    } while(!SqStackEmpty(S));
    printf("寻找失败!");
}

// 迷宫初始化
void InitMaze(MazeType maze, int* obs_x, int* obs_y, int n) {
    int i, j, temp;

    for (i=0 ;i<M; i++) {
        for (j=0; j<N; j++) {
            if (i==0 || j==0 || i==M-1 || j==N-1) { // 最外层为墙
                maze[i][j] = Wall;
            } else {
                maze[i][j] = Way;                   // 先全部生成路
            }
        }
    }
    for (i=0; i<n; i++) {
        maze[obs_x[i]][obs_y[i]] = Obstacle;
    }
}

// 之前是否探索过
Status Pass(MazeType maze, PosType seat) {
    int x = seat.x;
    int y = seat.y;

    // 检查是否越界
    if (x<0 || y<0 || x>M-1 || y>N-1) {
        return FALSE;
    }
    if (maze[x][y] !=Way) {
        return FALSE;
    }
    return TRUE;
}

// 获取下一个应该探索的位置
PosType NextPos(PosType seat, int di) {
    PosType tmp = seat;
    switch (di) {
        case East:
            tmp.y++;
            break;
        case Sounth:
            tmp.x++;
            break;
        case West:
            tmp.y--;
            break;
        case North:
            tmp.x--;
            break;
    }
    return tmp;
}

// 留下足迹
void FootPrint(MazeType maze, PosType seat) {
    MarkPrint(maze, seat, East);
}


// 留下标记
void MarkPrint(MazeType maze, PosType seat, int mark) {
    maze[seat.x][seat.y] = mark;
}

// 构造通道信息
SElemType Construct(int ord, PosType seat, int di) {
    SElemType e;
    e.ord = ord;
    e.seat = seat;
    e.di = di;
    return e;
}

// 判断坐标是否相等
Status Equal(PosType a, PosType b) {
    if (a.x==b.x && a.y==b.y) {
        return TRUE;
    } else {
        return FALSE;
    }
}


// 绘制迷宫
void PrintMaze(MazeType maze) {
    printf("\n-----------------------------\n");
    int i, j;
    char mark = ' ';
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
        switch (maze[i][j]){
            case 0:
                mark = '*';
                break;
            case 1:
                mark = 'o';
                break;
            case 4:
                mark = '>';
                break;
            case 5:
                mark = 'u';
            case 6:
                mark = '<';
                break;
            case 7:
                mark = 'n';
                break;
         }
            printf("%c ", mark);
        }
        printf("\n");
    }
    printf("\n");
}


