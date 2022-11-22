 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void print(int* arr,int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{

		printf("%d", *arr);
		arr++;
	}
}

int main()
{
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[1]);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		scanf("%d", &arr[i]);
	}
	print(arr,sz);
	return 0;
}