#pragma once
#include<stdlib.h>
#include<time.h>
#include<stdio.h>

#define Easy_parttern 80
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2



void init(char arr[][COLS], int rows , int cols , char ret);

//´òÓ¡ÆåÅÌ
void print(char arr[][COLS], int row, int col);

//ÉèÖÃÀ×
void set_mine(char arr1[][COLS], int row, int col);

//ÅÅÀ×
void check_mine(char arr1[][COLS], char arr2[][COLS], int row, int col);
