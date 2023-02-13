 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	char arr[] = "abcdeafg";
	//printf("%s", strchr(arr, 'a'));
	//找字符第一次的出现若存在返回第一次出现的地址，反之返回NULL
	printf("%s", strrchr(arr, 'a'));
	//找字符最后一次出现若存在返回第出现的地址，反之返回NULL

	return 0;
}