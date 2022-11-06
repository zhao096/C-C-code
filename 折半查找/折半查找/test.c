 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 1;
	int a = 0;
	int l = 0;
	int r = sizeof(arr) / sizeof(arr[0]) - 1;
	while (l < r)//注意此处不要用 <= 因为如果这样的话当k<0时将会死循环因为k<0将一直arr[0] = 1 ,而mid = 1 + 1 / 2 = 1 //r = mid - 1 = 0无限循环  
	{
		int mid = (arr[l] + arr[r]) / 2;
		if (k < mid)
			r = mid - 1;
		else if (k > mid)
			l = mid + 1;
		else
		{
			printf("找到了他是:%d\n", mid);
			a = 1;
			break;
		}
	}
	if (a == 0)
		printf("找不到");
	return 0;
}