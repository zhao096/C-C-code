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
	return *string1 - *string2;
}
int main()
{
	char arr1[] = "abdef";
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