#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char a[][5] = { {' ','A','B','a','3'}
					  ,{'4','a','c','G','7'}
					  ,{' ',' ',' ','F','a'} };
	int number = 0;
	int lower = 0;
	int upper = 0;
	int print = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (isdigit(a[i][j]))
			{
				number++;
			}
			else if (islower(a[i][j]))
			{
				lower++;
			}
			else if (isupper(a[i][j]))
			{
				upper++;
			}
			else if(isprint(a[i][j]))
			{
				print++;
			}
		}
	}
	printf("%d %d %d %d ", number, lower, upper, print);

	return 0;
}