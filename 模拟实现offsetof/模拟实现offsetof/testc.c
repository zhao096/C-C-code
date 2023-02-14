 #define _CRT_SECURE_NO_WARNINGS 1





#include<stdio.h>

#define my_offsetof(struct_type,number) (size_t)&(((S*)0)->number)
//将0地址强制转化为这个结构体类型的地址，相当于在0地址这里存放了一个结构体，
//再找到0地址处结构体内成员的地址，这个成员的地址就是这个成员偏移量的大小
typedef struct S
{
	int a;
	char b;
	long c;
	char d;
}S;
int main()
{
	printf("%d ", my_offsetof(S, a));
	printf("%d ", my_offsetof(S, b));
	printf("%d ", my_offsetof(S, c));

	printf("%d ", my_offsetof(S, d));

	return 0;
}