 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	char n[100] = { 0 };
	gets(n);
	int l ,r;
	r = strlen(n);
	for (l = 0; l < r; r--, l++)
	{
		int tmp = n[l];
		n[l] = n[r - 1];
		n[r - 1] = tmp;
	}
	printf("%s", n);
	return 0;
}