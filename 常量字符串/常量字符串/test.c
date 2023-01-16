 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	char arr[10] = "abcdef";
	char* p = "asdfg";
	p = "abcde";
	printf("%s", p);
	return 0;
}