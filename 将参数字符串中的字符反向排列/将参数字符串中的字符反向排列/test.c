 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
char reverse_string(char arr[],int i,int b)//注意传数组时要用数组接否则无法在函数内部改变数组的内容
{
	if (i >= b)
	{
		return 0;
	}
	else
	{
		int tmp = arr[i];
		arr[i] = arr[b];  //交换
		arr[b] = tmp;
		return reverse_string(arr, i + 1, b - 1);
	}

}
int main()
{
	//char arr[] = "abcdef";
	char arr[] = { 'a','b','c','d','e','f','\0'};
	int i = 0;
	//int b = sizeof(arr) / sizeof(arr[0]) -1; //sizeof(arr)内有7个字符（\0）也就说arr的空间为70 / 10 = 7 ,故还需要-1才能确保为6
	int b = strlen(arr);
	reverse_string(arr,i,b);
	for (i = 0; i <= b; i++)
	{
		printf("%c", arr[i]);
	}
	return 0;
}