#pragma once
#include<stdio.h>

#define ROW 3

#define COL 3

void InitBoard(char board[ROW][COL], int row, int col);

void  Dispalyboard(char board[ROW][COL], int row, int col);


void playermove(char board[][COL],int row,int col);

void computermove(char board[][COL], int row, int col);
