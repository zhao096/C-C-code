 #define _CRT_SECURE_NO_WARNINGS 1
//写一个宏，可以将一个整数的二进制位的奇数位和偶数位交换。
#include<stdio.h>

#define Swap_odevity(x) ((size_t)-1 ^ (x)) 

int main()
{
	int a = 0;
	scanf("%d", &a);
	
	printf("%d", Swap_odevity(a));
	return 0;
}