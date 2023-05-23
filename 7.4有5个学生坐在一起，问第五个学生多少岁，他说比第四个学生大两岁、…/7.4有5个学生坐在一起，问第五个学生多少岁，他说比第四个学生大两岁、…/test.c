#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int Age(int n)
{
	if (n == 1)
	{
		return 10;
	}
	return 2 + Age(n - 1);
}
//7.4有5个学生坐在一起，问第五个学生多少岁，他说比第四个学生大两岁、…
int main()
{
	int n = 5;
	int age = Age(n);
	printf("%d", age);
	return 0;
}