 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
const char* my_strstr(const char* string, const char* sour)
{
	assert(string && sour);
	if (*sour == '\0')
	{
		return string;

	}
	char* tagg = (char*)string;
	char* tagr = (char*)sour;//用两个指针记录string和sour的地址
	while (*string)//遍历的寻找方法,注意此处要用*string
	{

		tagg = (char*)string;//通过记录的位置返回
		tagr = (char*)sour;

		while (*tagg++ == *tagr++ && *tagg != '\0')
		{
			if (*tagr == '\0')
			{
				return string;
			}
		}
		string++;//放到后面来++是因为在前面会导致返回值被++也就是上面这里的return string
	}	
	return NULL;//当string的长度为0时无法进入循环即找不到相同的时候就会返回0
}
int main()
{
	char arr1[] = "cbabcd";
	char arr2[] = "bc";
	//printf("%s",strstr(arr1, arr2));
	const char* ret = my_strstr(arr1, arr2);

	if (ret == NULL)
	{
		printf("找不到\n");
	}
	else
	{
		printf("%s", ret);

	}
	return 0;
}