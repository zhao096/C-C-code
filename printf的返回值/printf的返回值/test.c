#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	//printf返回值是字符的个数
	int num = printf("Hello world!\n");
	
	printf("%d", num);
	return 0;
}