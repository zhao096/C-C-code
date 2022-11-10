 #define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void init(char arr[][COLS], int rows, int cols, char ret)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < cols; i++)
	{
		for (j = 0; j < rows; j++)
		{
			arr[i][j] = ret; //注意此处的ret不用再加单引号否则若给一串将打印最后一个字符
		}

	}

}
void print(char arr[][COLS], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i <= col; i++)
		printf("%d ", i);
	printf("\n");
	for (i = 1; i <= col; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= row; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}

}

void set_mine(char arr1[][COLS],int row, int col)
{
	int count = Easy_parttern;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (arr1[x][y] != '1')
		{
			arr1[x][y] = '1';
			count--;//注意别放在了，可能会导致雷放不够就跳出循环了

		}
	}
}

int num_mine(char arr[ROWS][COLS],int x, int y)
{
	return (arr[x - 1][y - 1] + arr[x - 1][y] + arr[x - 1][y + 1] + arr[x][y - 1] + arr[x][y + 1]

		+ arr[x + 1][y - 1] + arr[x + 1][y] + arr[x + 1][y + 1]) - ( 8 * '0');
}

void check_mine(char arr1[][COLS], char arr2[][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = ROW * COL - Easy_parttern;
	while (count)
	{
		printf("请输入要排查雷的坐标\n");
		scanf("%d %d", &x, &y);
		if (arr2[x][y] == '*')
		{
			if (arr1[x][y] == '1')
			{
				printf("很遗憾你呗炸死了\n");
				print(arr1, ROW, COL);

				break;
			}
			else if (x > 0 && x <= row && y > 0 && y <= col)
			{
				int k = num_mine(arr1, x, y);
				arr2[x][y] = k + '0';
				count--;
				print(arr2, ROW, COL);
				//print(arr1, ROW, COL);
			}
			else
			{
				printf("输入错误\n");
			}
		}
		else
		{
			printf("此处已查过\n");
		}


		if (count == 0)//总的空格数减掉总雷数得到剩余空位

		{
			printf("恭喜你排雷成功\n期待你再创佳绩\n");
		}
	}
	
}

