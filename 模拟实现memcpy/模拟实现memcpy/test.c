 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
void* my_memcpy(char* des, const char* sour,size_t num)
{
	assert(des && sour);
	char* tmp = des;
	size_t i = 0;
	for (i; i < num; i++)//首先要保证改变的字符个数
	{
		if (*sour != '\0')//其次只有当sour不为\0时才应该交换，否则就会非法访问
		{
			*des++ = *sour++;
		}
	}
	return tmp;
}
int main()
{
	char arr[] = "cdefgq";
	char arr1[] = "ab";
	//printf("%s",(char *)memcpy(arr, arr1,2));//第三个参数是以byte为单位的，但是不将\0拷贝进去
	printf("%s",(char *)my_memcpy(arr, arr1, 2));
	return 0;
}