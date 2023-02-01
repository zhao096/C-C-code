 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


struct test
{
	int m;
	char* s;
	short p;
	char a[2];
		short q[4];
}*p;

int main()
{
	p = (struct test*)0x100000;
	printf("%p\n", p + 0x1);//0x00 10 00 14 -》14等于十进制的20 即p原类型是一个结构体类型其大小为20byte所以当+1就会直接加20
	printf("%p\n", (unsigned long)p + 0x1);//此处将p强转成了无符号的长整形既然是整形就直接+1即可
	printf("%p\n", (unsigned int *)p + 0x1);//此处转化成了无符号int * 所以其大小又变成了4所以+1就是+4
	return 0;
}