#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int a_win = 0;
int b_win = 0;
void Win(int A[10], int B[10])
{
	for (int i = 0; i < 10; i++)
	{
		if (A[i] > B[i])
		{
			a_win++;
		}
		else//不考虑平手，平手算B赢
		{
			b_win++;
		}
	}
}


int main()
{
	int A[10] = {0};
	int B[10] = {0};
	printf("A队的成绩:");

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &A[i]);
	}
	printf("B队的成绩:");
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &B[i]);
	}

	Win(A, B);
	printf("A:%d B:%d\n", a_win, b_win);
	return 0;
}