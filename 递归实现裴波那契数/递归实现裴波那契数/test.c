 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int PBNQS(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return PBNQS(n - 1) + PBNQS(n - 2);
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int num =  PBNQS(n);
	printf("%d", num);
	return 0;
}