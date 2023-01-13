 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
char* my_strcpy(char* des, const char* sour)
{
	assert(des && sour);
	char* tmp = des;
	while (*des++ = *sour++);
	return tmp;
}

int main()
{
	char arr[] = "xxxxxxxxxx";
	char arr1[] = "abcdef";
	//strcpy(arr, arr1);//strcpy会将\0也传过去
	printf("%s", my_strcpy(arr, arr1));
	return 0;
}