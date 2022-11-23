// #define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int arr1[10][10] = { 0 };
//	int arr2[10][10] = { 0 };
//	int n = 0;
//	int m = 0;
//	int i = 0;
//	int j = 0;
//	scanf("%d %d", &n, &m);
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			scanf("%d", &arr1[i][j]);
//			scanf("%d", &arr2[i][j]);
//		}
//	}
//	int z = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			if (arr1[i][j] != arr2[i][j])
//			{
//				z = 1;
//				goto err;
//			}
//			
//		}
//	}
//err:
//	if (z == 1)
//	{
//		printf("No\n");
//
//	}
//	else
//	{
//		printf("Yes\n");
//	}
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void scan(int arr[10][10], int n, int m)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
}
int main()
{
	int arr1[10][10] = { 0 };
	int arr2[10][10] = { 0 };
	int n = 0;
	int m = 0;
	int i = 0;
	int j = 0;
	scanf("%d %d", &n, &m);
	scan(arr1, n, m);
	scan(arr2, n, m);
	int z = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (arr1[i][j] != arr2[i][j])
			{
				z = 1;
				goto err;
			}

		}
	}
err:
	if (z == 1)
	{
		printf("No\n");

	}
	else
	{
		printf("Yes\n");
	}
	return 0;
}