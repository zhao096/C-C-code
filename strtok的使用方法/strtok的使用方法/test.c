 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	char arr1[] = "ZhaoYKun@qq.com";
	//char arr2[] = {'@','.','\0'};和下结果一样
	char arr2[] = "@.";

	printf("%s\n", strtok(arr1, arr2));//返回第一次分隔好的字符的首元素地址
	printf("%s\n", strtok(NULL, arr2));
	printf("%s\n", strtok(NULL, arr2));
	printf("%s\n", strtok(NULL, arr2));


	return 0;
}