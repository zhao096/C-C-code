#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define Mine 10

#define ROWS ROW+2
#define COLS COL+2

#define ROW 9
#define COL 9


void IntiBoard( char board[][COLS],int rows,int cols,char set);

void DisplayBoard(char board[][COLS], int row, int col);

void DispalyMine(char board[][COLS], int row, int col);

void CheckMine(char mine[][COLS],char show[][COLS], int row, int col);
