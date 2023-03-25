#include<stdio.h>

int ADD(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}



int main()
{
	int a = 2, b = 3;
	int c = ADD(a, b);
	printf("%d ", c);

	return 0;
}