 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
int my_strcmp(const char* string1, const char* string2)
{
	assert(string1 && string2);
	while (*string1 == *string2 && *string1 != '\0')//找到不相等的字符
	{
		string1++;
		string2++;
	}
	if ((*string1 - *string2) == 0)
		return 0;
	else
	return (*string1 - *string2)>0?1:-1; //vs环境下1大于2返回1 ， 1<2 返回-1  1 = 2 返回 0
}
int main()
{
	char arr1[] = "cbq";
	char arr2[] = "abq";
	int ret = my_strcmp(arr1, arr2);
	if (ret > 0)
	{
		printf("arr1>arr2");
	}
	else if (ret < 0)
	{
		printf("arr1<arr2");
	}
	else
	{
		printf("arr1=arr2");
	}
	//比较的是对应字符的ASCII码值

	return 0;
}