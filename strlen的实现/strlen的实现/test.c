 #define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<stdio.h>

//int my_strlen(const char* string)
//{
//	assert(string);//防止string == NULL
//	int count = 0;
//	while( *string++ != '\0')
//	{	
//		count++;
//	}
//	return count;
//}
size_t my_strlen(const char* string)
{
	const char* star = string;//若没在最开始加const 就会报错，因为string也是const
	while (*string++)//这样写他在判断成string为0后仍会加1
	{
		;
	}
	return string - star -1;//所以要减1
}
int main()
{
	char arr[] = "abcdef";
	printf("%d", my_strlen(arr));//链式访问，他会返回字符个数
	return 0;
}