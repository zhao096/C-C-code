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

int Add(int x, int y)
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
		//printf("请输入：");
		//scanf("%d", &input);

		int(*p[5])(int, int) = { NULL,Add,Sub,Mul,Div };
		int (*(*pf)[5])(int, int) = &p;
		printf("相加结果:>%d", p[1](2,3));
		/*if (input == 0)
		{
			printf("退出计算器\n");
			break;
		}
		else if (input <= 4 && input >= 1)
		{
			printf("输入两个值：");
			scanf("%d %d", &a, &b);

			printf("%d\n", p[input](a, b));
		}
		else
		{
			printf("输入错误请重新输入\n");
		}*/

	} while (input);

		return 0;
}