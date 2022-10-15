#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//符号的定义
#define ROW 3
#define COL 3

//函数的声明


void InitBoard(char board[ROW][COL], int row, int col);

 void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
 playeromove( char board[][COL],int row,int col);

 void  computermove(char board[][COL], int row, int col);

 //判断输赢
  char IsWin( char board[][COL],int row, int col);