 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int sushuPD(int n)
{
	int j = 0;
	for (j = 2; j < n; j++)
	{
		if (n % j == 0) 
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int i = 0;
	for (i = 100; i < 201; i++)
	{
		if (sushuPD(i) == 1)
		{
			printf("%d ", i);
		}
	}
	return 0;
}