 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int arr[] = { 13,15,16,20,24,30,35,80,81,99 };
	int k = 15;
	int a = 0;
	int l = 0;
	int r = sizeof(arr) / sizeof(arr[0]) - 1;
	while (l <= r)//
	{
		int mid = (l + r) / 2;
		if (k < arr[mid])
			r = mid - 1;
		else if (k > arr[mid])
			l = mid + 1;
		else
		{
			printf("找到了他是:%d\n", arr[mid]);
			a = 1;
			break;
		}
	}
	if (a == 0)
		printf("找不到");
	return 0;
}