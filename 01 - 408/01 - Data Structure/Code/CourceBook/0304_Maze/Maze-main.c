#include "Maze.h"


int main() {
    MazeType maze;
    PosType start,end;
    start.y = 1;
    start.x = 5;
    end.y   = 5;
    end.x   = 1;
    /*
      ������Թ�Ϊ(oΪ�ϰ�)
       -------
       -xxxxx- ->��
       -xoxxo-
       -xoxox-
       -xoxxo-
   ��->-xxxox-
       -------
    */
    int obs_x[7] = {2, 2, 3, 3,4,4, 5};
    int obs_y[7] = {2, 5, 2, 4,2,5, 4}; 
    InitMaze(maze, obs_x, obs_y, 7);
    PrintMaze(maze);

    MazePath(maze, start, end);
}

