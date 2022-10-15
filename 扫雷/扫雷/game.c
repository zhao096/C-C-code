 #define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

int Check(char mine[ROWS][COLS],int x , int y)
{
	return (
		mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x + 1][y + 1] +
		mine[x + 1][y]+
		mine[x + 1][y - 1] +
		mine[x][y - 1] +
		mine[x][y + 1]) - 8 *  '0';
}

void IntiBoard(char board[][COLS], int rows, int cols, char set)
{
	int x = 0;
	int y = 0;
	
	for (x = 0; x < rows; x++)
	{
		for (y = 0; y < cols; y++)
		{
			board[x][y] = set;  //注意赋值和等于的区别
		}

	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;

	for (x = 0; x <= col;x++)
	{
		printf("%d ", x);
	}
	printf("\n");
	for (x = 1; x <= row; x++)
	{
		printf("%d ", x);
		for (y = 1; y <= col; y++)
		{
			printf("%c ", board[x][y]);
		}
		printf("\n");
	}
	printf("\n");
}
void DispalyMine(char board[][COLS], int row, int col)
{
	
	int i = Mine;
	while(i)
	{
		int x = rand() % row + 1;
		int y = rand() % row + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			i--;
		}
	}
}

void CheckMine(char mine[][COLS], char show[][COLS], int row, int col)
{
	//1.输入排查的坐标
	//2.排查处是不是雷
	//3.排查出坐标附近有几个雷

	int x = 0;
	int y = 0;
	int win = 0;
	while(win<col*row-Mine)
	{
		printf("请输入要排查的坐标:\n");
		scanf("%d %d", &x, &y);
		printf("\n");
		//确定输入的合法性
 		if (x > 0 && x <= row && y > 0 && y <= col)   // 当你输入数字时请考虑他的局限性！！！
		{
			if (mine[x][y] == '0')  
			{
				int count = Check(mine, x, y);    //统计周围有几个雷
				show[x][y] = count + '0';
				DisplayBoard(show, ROW, COL);
				win++;
			}
			else 
			{
				printf("很遗恨被炸死了\n");
				DispalyMine(mine, row, col);
				break;
			}

		}
		else
		{
			printf("输入错误，请重新输入\n");
		}
	}
	if (mine[x][y] != '1')
		mine[x][y] == '0';
}

