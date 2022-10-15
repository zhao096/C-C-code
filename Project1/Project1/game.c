#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		
	     }

	}
}

void Dispalyboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{

		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}


	}
}

void playermove(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("玩家请以坐标位置下棋:");   
	while(1)                                                       //注意判断合法性，
	if (i>=1 && i <= row && j <= col && j >=1)                    //玩家坐标一般是从1 1这种开始的故左计算机中的0 0应该变成1 1 
	{
		if(board[i - 1][j - 1] != ' ')
		{
			board[i - 1][j - 1] = '*';
			break;
		}
		else if (board[i - 1][j - 1] == ' ')
		{
			printf("此格子已被占用");
		}
		else
		{
			printf("输入错误，重新输入");
		}
	}


}

void computermove(char board[ROW][COL], int row, int col)
{
	int x = rand() % row;
	int y = rand() % col;
	if (board[x - 1][y - 1] != ' ')
	{
		board[x][y] == '#';
	}


}

