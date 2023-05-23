#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int Max(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	int i, j;
	scanf("%d %d", &i, &j);
	int max = Max(i, j);
	printf("%d", max);
	return 0;
}