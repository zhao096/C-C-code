 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int R, C = 0;
	scanf("%d %d", &R, &C);
	int n = 0;
	int j = 0;
	int arr[10][10] = { 0 };
	for (j = 0; j < R; j++)
	{
		for (n = 0; n < C; n++)
		{
			scanf("%d", &arr[j][n]);//当你输入1 2 3时scanf只会读到空格就停止，故缓冲区内仍然还有2 3这两个
		}
	}

	for (n = 0; n < C; n++)
	{
		for (j = 0; j < R; j++)
		{
			printf("%d ", arr[j][n]);
		}
		printf("\n");
	}
	

	return 0;
}