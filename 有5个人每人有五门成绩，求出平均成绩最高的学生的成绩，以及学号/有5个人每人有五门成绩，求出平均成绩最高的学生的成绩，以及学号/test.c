 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//有5个人每人有五门成绩，求出平均成绩最高的学生的成绩，以及学号
int main()
{
	int arr[5][5] = { {99,99,99,99,99},
					  {100,100,100,100,100},
					  {60,60,60,60,60},
					  {78,78,78,78,78},
					  {88,88,88,88,88} };
	int average = 0;
	int sum = 0;
	int tag = 0;
	for (int i = 0; i < 5; i++)
	{
		sum = 0;
		for (int j = 0; j < 5; j++)
		{
			sum += arr[i][j];
		}

		int tmp = sum / 5;

		if (average < tmp)
		{
			average = tmp;
			tag = i;
		}
		
	}

	printf("averag:%d 学号:%d", average, tag + 1);
	return 0;
}