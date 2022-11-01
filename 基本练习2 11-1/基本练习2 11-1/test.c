 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int print(int i)
{
	if (i / 10 == 0)
	{
		printf("%d ", i);
		return 0;
	}
	else
	{
		print(i / 10);
	}
	printf("%d ", i % 10);
	return 0;

}
int main()
{
	int i = 0;
	printf("输入所要拆的数字");
	scanf("%d", &i);
	print(i);


	return 0;
}