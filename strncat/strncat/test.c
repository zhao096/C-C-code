 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
char* my_strncat(char* strDest, const char* strSource, size_t count)
{
	assert(strDest && strSource);
	char* ret = strDest;

	while(*++strDest);//找到strDestin的\0处

	while(count--)
	{
		if(*strSource != '\0')
		*strDest++ = *strSource++;
	}
	return ret;
}

int main()
{
	//char *strncat( char *strDest, const char *strSource, size_t count );//追加个数

	char arr1[12] = "xxxxx\0xx";
	char arr2[] = "acde";

	//printf("%s", strncat(arr1, arr2, 4));
	printf("%s", my_strncat(arr1, arr2, 4));

	return 0;
}