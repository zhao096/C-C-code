 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void menu()
{
	printf("********************************\n");
	printf("**********1.Add   2.Sub*********\n");
	printf("**********3.Mul   4.Div*********\n");
	printf("**********   0.exit    *********\n");
	printf("********************************\n");
}

int Add(int x ,int y)
{
	return  x + y;
}

int Sub(int x, int y)
{
	return  x - y;
}

int Mul(int x, int y)
{
	return  x * y;
}

int Div(int x, int y)
{
	return  x / y;
}

int main()
{
	int input = 0;
	int a = 0;
	int b = 0;
	do
	{
		menu();
		printf("请输入：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入两个值：");
			scanf("%d %d", &a, &b);
			printf("%d\n", Add(a, b));
			break;
		case 2:
			printf("请输入两个值：");
			scanf("%d %d", &a, &b);
			printf("%d\n",Sub(a, b));
			break;
		case 3:
			printf("请输入两个值：");
			scanf("%d %d", &a, &b);
			printf("%d\n",Mul(a, b));
			break;
		case 4:
			printf("请输入两个值：");
			scanf("%d %d", &a, &b);
			printf("%d\n",Div(a, b));
			break;
		case 0:
			printf("退出计算器\n");
			break;
		default:
			printf("输入错误请重新输入\n");
			break;
		}

	} while(input);

	return 0;
}