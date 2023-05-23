 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
char arr[4] = { 0 };

void exchange(int a, int n)
{
	if (a % 10 == 0)
	{
		return;
	}
	arr[n] = (a % 10) + '0';
	exchange(a / 10, n - 1);
}

int main()
{
	int a = 436;
	int n = 3;
	exchange(a,n-1);
	printf("%s", arr);
	return 0;
}