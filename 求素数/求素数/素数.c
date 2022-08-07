 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 0;
	int j = 2;
		for (i = 101; i < 201; i++)
		{
			for (j = 2; j < i; j++)
			{
				if (i % j == 0)
				{
					break;
				}
			}
			if (i == j)
			{
				printf("%d ", i);
			}
		}
	return 0;
}