 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//一个班有10人的成绩存放在一个一维数组中，求出成绩最高命干成绩最高的学生的成绩和学号
void reverse(int* a)
{
	int left = 0,right = 9;

	while (left < right)
	{
		int tmp = a[left];
		a[left] = a[right];
		a[right] = tmp;
		left++;
		right--;
	}
}

int main()
{
	int a[10] = {0};
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	reverse(a);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}