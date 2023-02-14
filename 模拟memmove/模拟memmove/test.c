#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
void* my_memmove(void * des ,const void* src, size_t count)
{
	assert(des && src);
	void* ret = des;
	//要份前后的原因是当des src重合时会有可能因为src没传递好而导致src处吧自己覆盖了又用覆盖后的值覆盖其余地方
	//当des<src  就好像   des ：1 2 3 4 5 6 7 8    src: 3 4 5 6   count：4  若不是从前往后而是从后往前的话就会使6覆盖到4处
	//主要是看当des > src 时 src ：1 2 3 4     des: 3 4 5 6 7 8  count：4   若仍然为从前往后覆盖则会导致1覆盖到3处
	//从前往后
	if (des < src)
	{
		while (count--)
		{
			*(char*)des = *(char*)src;
			des = (char*)des + 1;
			src = (char*)src + 1;
		}
	}
	//从后往前
	else
	{
		while (count--)
		{
			*((char*)des + count) = *((char*)src + count);
		}
	}
	return ret;
}
int main()
{
	//模拟实现memmove    void *memmove( void *dest, const void *src, size_t count );他还要满足当指向统一空间时
	
	char arr1[] = "abcdef";
	char arr2[] = "qwer";

	printf("%s\n", (char*)memmove(arr1+3, arr1+2, 2));

	printf("%s\n", (char*)my_memmove(arr1, arr2,4 ));


	return 0;
}