#pragma once
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

#define ROW 3
#define COL 3
//棋盘初始化
void init(char arr[ROW][COL], int r, int c);
//打印棋盘
void print(char arr[ROW][COL],int r,int c);
//玩家走
void play_move(char arr[ROW][COL], int r, int c);
//电脑走
void comput_move(char arr[ROW][COL], int r, int c);




char is_win(char arr[ROW][COL], int r, int c);