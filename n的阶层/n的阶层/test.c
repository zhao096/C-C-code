 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Fac(int n)
{
	int i = 0;
	int sum = 1;
	for (; n > 1; n--)
	{
		sum *= n;
	}
	return sum;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int sum = Fac(n);
	printf("%d", sum);


	return 0;
}