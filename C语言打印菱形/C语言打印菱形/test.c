 #define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	char arr[][5] = { {' ',' ','*'},{' ','*',' ','*'},{'*',' ',' ',' ','*'},{' ','*',' ','*'},{' ',' ','*'} };
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}