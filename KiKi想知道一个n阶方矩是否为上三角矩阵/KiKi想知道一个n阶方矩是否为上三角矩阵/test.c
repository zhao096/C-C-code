 #define _CRT_SECURE_NO_WARNINGS 1
//上三角矩阵即主对角线以下的元素都为0的矩阵，主对角线为从矩阵的左上角至右下角的连线。
#include<stdio.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int j = 0;
	int arr[10][10] = { 0 };
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]); // 00 01 02
									// 10 11 12
									// 20 21 22
		}
	}
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i > j)
			{
				sum += arr[i][j];
			}
		}
	}
	if (sum == 0)
	{
		printf("YES");
	}
	else {
		printf("NO");
	}


	return 0;
}