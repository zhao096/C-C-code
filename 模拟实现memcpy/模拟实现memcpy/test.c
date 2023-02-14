 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//void* my_memcpy(char* des, const char* sour,size_t num)
//{
//	assert(des && sour);
//	char* tmp = des;
//	size_t i = 0;
//	for (i; i < num; i++)//首先要保证改变的字符个数
//	{
//		if (*sour != '\0')//其次只有当sour不为\0时才应该交换，否则就会非法访问
//		{
//			*des++ = *sour++;
//		}
//	}
//	return tmp;
//}
//int main()
//{
//	char arr[] = "cdefgq";
//	char arr1[] = "ab";
//	//printf("%s",(char *)memcpy(arr, arr1,2));//第三个参数是以byte为单位的，但是不将\0拷贝进去
//	printf("%s",(char *)my_memcpy(arr, arr1, 2));
//	return 0;
//}
// 
// 
//void * memcpy ( void * destination, const void * source, size_t num );
void* my_memcpy(void* des, const void* sor, size_t num)
{
	assert(des && sor);
	void* ret = des;//该函数返回des的地址
	if (des < sor)//从前往后将sor的前面开始放进des的前面
	{
		while (num--)
		{
			*((char*)des) = *((char*)sor);
			++(char*)des;
			++(char*)sor;
		}
	}
	
	else//des > sor 将sor从后往前放进des的后面
	{
		while (num--)//并且此处刚好num-- 指向正确的位置，否则还需要num-1
		{
			*((char*)des + num) = *((char*)sor + num);
		}
	}
	return  ret;
}
int main()
{
	char arr[] = "cdefgq";
	char arr1[] = "ab";
	
	//printf("%s\n",(char *)memcpy(arr+3, arr+2,2));//第三个参数是以byte为单位的，但是不将\0拷贝进去、

	printf("%s", (char*)my_memcpy(arr+3, arr+2, 2));
	return 0;
}