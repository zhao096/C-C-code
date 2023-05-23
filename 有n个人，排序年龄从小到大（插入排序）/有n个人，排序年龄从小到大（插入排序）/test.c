#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void swap(int * x, int * y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void InsertSort(int *a)
{
	int cur = 0;
	for (cur = 0; cur < 10 ;cur++)
	{
		int prev = cur - 1;
		int tmp = cur;
		while (tmp && a[tmp] < a[prev])
		{
			swap(&a[tmp], &a[prev]);
			tmp--;
			prev--;
		}
	}
}

int main()
{
	int a[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}

	InsertSort(a);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}