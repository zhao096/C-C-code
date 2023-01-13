 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
char* my_strcat(char* des, const char * sour)
{
	assert(des && sour);
	char* tmp = des;
	while (*++des);//++ 比 * 优先级高找到\0
	while (*des++ = *sour++);
	return tmp;
}
int main()
{
	//模拟实现strcat
	//他会将sour字符串覆盖置des的\0及以后的字符,并且会把\0也传进来
	char arr1[20] = "ab\0cd";
	char arr2[] = "ef";
	//strcat(arr1, arr2);
	
	printf("%s", my_strcat(arr1, arr2));
	return 0;
}