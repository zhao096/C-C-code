 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
	int arr[10][10] = { 0 };
	int i = 0, r = 0,j = 0,c = 0;
	scanf("%d %d", &c, &r);
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			arr[i][j] = i + j;
		}
	}
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	int key = 0;
	printf("请输入你所要查找的数字>");
	scanf("%d", &key);
	if (arr[0][c-1] > key && key >= 0 )
	{
		int R = arr[0][c - 1];
		int L = 0;
		int half = (R + L) / 2;
		while (1)
		{

			if (half > key)
			{
				R = half - 1;
				half = (R + L) / 2;
			}
			else if (half < key)
			{
				L = half + 1;
				half = (R + L) / 2;

			}
			else
			{
				printf("找到了是：%d",half);
				break;
			}
		}

	}
	else if (arr[0][c-1] < key && key < c + (c-2))//第一层3*3最大的数是4 = 3 + 3 - 2  第二次4*4 ：6 = 4 + 4-2  
	{
		int	L = arr[0][c - 1];
		int R = arr[r - 1][c - 1];
		int half = (R + L) / 2;
		while(1)
		{
		
			if (half > key)
			{
				R = half - 1;
				half = (R + L) / 2;
			}
			else if (half < key)
			{
				L = half + 1;
				half = (R + L) / 2;

			}
			else
			{
				printf("找到了是：%d", half);
				break;
			}	

		}
			
	}

	else if(arr[0][c-1] == key)
	{
		printf("找到了是：%d\n", arr[0][c-1]);
	}
	else
	{
		printf("不存在\n");
	}
	return 0;
}