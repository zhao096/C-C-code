 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	int arr[100] = { 0 };
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int count = 0;

	if(arr[0]<=arr[1])
	{
		for (int j = 0; j < n - 1; j++)//看是满足往前的递增，若满足则不用交换
		{
			if (arr[j] > arr[j + 1])//冒泡排序中的第二个循环
			{
				//int tmp = arr[j];
				//arr[j] = arr[j + 1];
				//arr[j + 1] = tmp;
				count = 1;
			}
		}
	}

	
	if (count == 0)
	{
		printf("sorted");
	}
	else
	{
		printf("unsorted");
	}
	return 0;
}
//if(arr[0] >= arr[1])
//{
//	int n1 = n - 1;
//	for (n; n > 0; n--)//从后面看是满足从后往前的递增
//	{
//		if (arr[n1] < arr[n - 1])
//		{
//			int tmp = arr[n1];
//			arr[n1] = arr[n1 - 1];
//			arr[n1 - 1] = tmp;
//			count = 1;
//		}
//	}
//}