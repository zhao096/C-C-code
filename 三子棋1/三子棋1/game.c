 #define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


int is_full(char arr[ROW][COL], int r, int c)
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < c; i++)
	{
		for (j = 0; j < r; j++)
		{
			if (arr[i][j] == ' ')
			{
				k = 1;
				return k;
			}

		}
	}
	return k;

}

void init(char arr[ROW][COL], int r, int c)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

void print(char arr[][COL], int r, int c)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < c; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < c - 1)
				printf("|");
		}
		printf("\n");
		if (i < r - 1)
		{
			for (j = 0; j < c; j++)
			{
				printf("---");
				if (j < c - 1)
					printf("|");

			}
			printf("\n");
		}

	}

}

void play_move(char arr[][COL], int r, int c)
{
	int x = 0;
	int y = 0;


	while(1)
	{
		printf("玩家走:>");
		scanf("%d %d", &x, &y);
		printf("\n");
		if (x > 0 && x <= ROW && y > 0 && y <= COL)
		{
			if (arr[x - 1][y - 1] == ' ')
			{
				arr[x - 1][y - 1] = 'O';
				break;
			}
			else
			{
				printf("该空已被占请重新输入\n");
			}
		}
		else
		{
			printf("错误输入，请重新输入\n");
		}
	}

}

void comput_move(char arr[][COL], int r, int c)
{
	printf("电脑走\n");
	while (1)
	{
		int x = rand() % c;
		int y = rand() % r;
		if (arr[x][y] == ' ')
		{
			arr[x][y] = 'X';
			break;
		}
	}

}

char is_win(char arr[][COL], int r, int c)
{
	int i = 0;
	int j = 0;
	for (j = 0; j < r; j++)
	{
		if (arr[j][i] == arr[j][i + 1] && arr[j][i+1] == arr[j][i+2] && arr[j][i+1] != ' ')
			return arr[j][i+1];
		if (arr[i][j] == arr[i+1][j] && arr[i+1][j] == arr[i+2][j] && arr[i+1][j] != ' ')
			return arr[i+1][j];
	}

	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != ' ')
		return arr[1][1];
	if(arr[1][2] == arr[1][1] && arr[3][1] == arr[1][1] && arr[1][1] != ' ')
		return arr[1][1];

	int f = is_full(arr, ROW, COL);
	if (f == 0)
	{
		return 'B';
	}

	return 'Q';
}

