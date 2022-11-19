 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int count = 0;
//	int arr[1000] = { 0 };
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//		count++;
//	}
//	int del = 0;
//
//	int k[1000] = {-1};
//	scanf("%d", &del);
//	for (i = 0 ; i < n ;i++)
//	{
//		if (arr[i] == del)
//		{
//			k[i] = i;//用k来记录相等的下标i
//		}
//	}
//	for(i = 0; i < count;i++)
//	{
//		if (i == k[i])
//			continue;
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

int main()
{
	int i = 0;
	int n = 0;
	scanf("%d", &n);
	int arr[10] = { 0 };
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int j = 0;
	int del = 0;
	scanf("%d", &del);
	for (i = 0; i < n; i++)
	{
		if (arr[i] != del)
		{
			arr[j++] = arr[i];//arr[j] 与 arr[i]同步 ，当arr[i] = del 时就不进入改变arr[j]也就是不存该数，然后若不是del则会存进去
		}
	}
	for (i = 0; i < j; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}