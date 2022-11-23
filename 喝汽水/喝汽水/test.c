 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水
int main()
{
	int n = 20;
	scanf("%d", &n);
	int sum = 0;
	sum = (n / 2) + (n / 1);
	printf("%d", sum);

	return 0;
}