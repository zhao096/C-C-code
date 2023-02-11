 #define _CRT_SECURE_NO_WARNINGS 1
//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//
//编写一个函数找出这两个只出现一次的数字。

#include<stdio.h>

int check_function(int *check , int sz,int num)
{
	for (int j = 1; j < sz; j++)//j应该从1开始不和自己比较
	{
		if (*check == *(check + j))
		{
			num = 1;//若有相等则置为1//反之若则不会置成1
			return num;
		}
	}
	return num;
}

int check_function1(int* check,int * re_check,int sz, int num)
{
	
	for (int j = 0; j < sz; j++)
	{
		if (*check == *(re_check + j))
		{
			num = 1;//若有相等则置为1//反之若则不会置成1
			return num;
		}
	}
	return num;
}



void check_signaldog(int* arr, int sz)
{
	int* check = arr;//让他往前走查找前面的有没有重复的
	
	int* re_check = arr;//查找身后有没有相同的
	
	int* storage_addr = arr;//存储arr的起始地址
	
	int num = 0;

	for (int i = 0; i < sz ; i++)
	{
		check = storage_addr;//让check每次向前一下逐一的寻找
		re_check = arr;
		num = 0;//重置num

		//先前寻找
		num += check_function(check,sz,num);

		//在身后寻找
		num += check_function1(check,re_check, i, num);//i == sz 要刚好不和自己相等

		
		
		if (num == 0)
		{
			printf("单手狗是：%d\n", *storage_addr);
		}
		storage_addr++;
	}

}


int main()
{
	int arr[10] = {0 };
	for(int i  = 0 ; i < 10 ;i++)
	scanf("%d", &arr[i]);
	
	
	int sz = sizeof(arr) / sizeof(arr[0]);
	check_signaldog(arr, sz);

	return 0;
}