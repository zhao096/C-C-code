 #define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<stdio.h>
char* my_strcpy(char* des, const char* sou)
{
	assert(des && sou);

	char *de = des;//µÿ÷∑”√÷∏’Î¥Ê

	while (*des++ = *sou++)
	{
		;
	}
	return de;
}
int main()
{
	char arr1[10] = { 0 };
	char *arr2 = "abcdef";
	printf("%s",my_strcpy(arr1, arr2));
	return 0;
}