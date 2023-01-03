 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	int COL = 0;
	scanf("%d", &i);
	int arr[100][100] = { 0 };
	for (COL = 0; COL < i; COL++)
	{
		for (j = 0; j <= COL; j++)
		{
			if (i >= 2 && j >= 1)
			{
				arr[COL][j] = arr[COL - 1][j - 1] + arr[COL - 1][j];
			}
			else
			{
				arr[COL][j] = 1;
			}
		}
	}
	for (COL = 0; COL < i; COL++)
	{
		for (j = 0; j <= COL; j++)
		{ 
			printf("%-3d", arr[COL][j]);
		}
		printf("\n");
	}

	return 0;
}