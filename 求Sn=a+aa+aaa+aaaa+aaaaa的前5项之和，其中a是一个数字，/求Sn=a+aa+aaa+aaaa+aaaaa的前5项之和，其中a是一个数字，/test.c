 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 0;
	int a = 0;
	scanf("%d", &a);
	int n = a;
	int count = 10;
	while (a / 10)
	{
		count *= 10;
	}
	int sum = 2;
	int tmp = 2;
	for (i = 0; i < 4; i++)//注意i<4，而不是i<5,S1并没有在循环内进行
	{	
		tmp = (n + (tmp * count));
		sum += tmp;
	}
	printf("Sn = %d", sum);
	return 0;
}