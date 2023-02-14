 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
int my_memcmp(const void* ptr1, const void* ptr2, size_t num)
{
	assert(ptr1 && ptr2);
	while (num--)//注意不能写成if eles的形式这样写会导致内容中间存在的一部分相等时就会返回去了
	{
		if (*((char*)ptr1) - *((char*)ptr2) > 0)
			return 1;
		
		if (*((char*)ptr1) - *((char*)ptr2) < 0)
			return -1;

		++((char*)ptr1);
		++((char*)ptr2);
	}
	return 0;//若上面及不大于也不小于则一定是相等
}


int main()
{
	//int arr1[] = { 1,4,7 };

	//
	//int arr2[] = { 1,4,7 };
	char arr1[] = "abced";
	char arr2[] = "abcef";

	int ret = my_memcmp(arr1, arr2, sizeof(arr1));

	printf("%d", ret);

	return 0;
}