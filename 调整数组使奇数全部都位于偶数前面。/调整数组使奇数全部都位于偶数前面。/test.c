 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void Swap(int arr[10],int sz)
{
	int a = 0;
	int i = 0;
	int num = 0;
	for (i = 0; i < sz; i++)//sz - num 是排除后面的已经确定的偶数
	{
			if (arr[i] % 2 == 0)
			{
				int tmp = arr[i];
				arr[i--] = arr[sz];
				arr[sz--] = tmp;
				//num++;//倒数有几个被交换了
				//i--为了让arr[i] 被交换成arr[sz]后再被测一次
				//sz--;是为了下次被交换的是倒数第二个
			}
	}
}
int main()
{
	int arr[10] = { 0 };
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	//输入一个整数数组，实现一个函数，来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
	//所有偶数位于数组的后半部分。
	//
	int sz = sizeof(arr) / sizeof(arr[0]) -1;
	Swap(arr,sz);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}