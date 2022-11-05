 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//int Strlen(int* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
void inti(int* str)
{
	int i = 10;
	while (i)
	{
		*str = 0;
		str++;
		i--;
	}
}
void print(int* str)
{
	int i = 10;
	while (i)
	{
		printf("%d ", *str);
		str++;
		i--;
	}
}
void reverse(int arr[],int num)
{
	int i = 0;
	while (i < num)
	{
		int tmp = arr[i];
		arr[i] = arr[num];
		arr[num] = tmp;
		i++;
		num--;
	}

}

int main()
{
	int arr[10] = { 0 };
	int num = sizeof(arr)/sizeof(arr[1]) - 1;
	inti(arr);
	print(arr);
	reverse(arr,num);
	printf("\n");
	print(arr);

	


	return 0;
}