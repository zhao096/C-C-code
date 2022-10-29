 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int k = (a > b ? b : a);

	while (1)
	{
		if (a % k == 0 && b % k == 0)
		{
			break;
		}
		else
		{
			k--;
		}
	}
	int min = a * b / k;
	int sum = k + min;
	printf("%d", sum);


	return 0;
}