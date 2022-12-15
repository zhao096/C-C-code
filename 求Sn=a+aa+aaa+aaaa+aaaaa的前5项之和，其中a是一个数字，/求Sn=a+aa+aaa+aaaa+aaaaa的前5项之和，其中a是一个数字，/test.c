 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 0;
	int a = 0;
	scanf("%d", &a);
	int n = a;
	int count = 10;
	while (n / 10)
	{
		count *= 10;
		n /= 10;
	}
	int sum = 0;
	int tmp = 0;
	for (i = 0; i < 5; i++)
	{	
		tmp = (n + (tmp * count));
		sum += tmp;
	}
	printf("Sn = %d", sum);
	return 0;
}