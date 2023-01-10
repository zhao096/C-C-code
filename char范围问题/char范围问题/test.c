 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	char arr[1000] = { 0 };
	int i = 0;
	for (i = 0; i < 1000; i++)
	{
		arr[i] =  - 1 - i;
	}
	printf("%d", strlen(arr));
	return 0;
}