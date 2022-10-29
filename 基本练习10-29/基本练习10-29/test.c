 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>

//int main()
//{
//	char arr1[] = "bit";
//	char arr2[] = { 'b','i','t' };
//	int a = strlen(arr1);
//	int b = strlen(arr2);
//
//	printf("%s %s %d %d", arr1, arr2,a,b);
//	return 0;
//}
//int is_leap_year(int a)
//{
//	if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//
//	}
//}
//int main()
//{
//	int a = 0;
//	for (a = 1000; a <= 2000; a++)
//	{
//		if (is_leap_year(a))
//		{
//			printf("%d ", a);
//		}
//	}
//	return 0;
//}
//test.c
//test.c



//extern int a;//声明其他文件中的变量
//
//int main()
//{
//    printf("%d", a);
//    return 0;
//}


////int main()
//{
//	printf("1");
//	return 0;
//}
//#include<stdio.h>
//void print(int i, int p , int a)
//{
//	for (i = 1; i <= a; i++)
//	{
//		for (p = 1; p <= i; p++)
//		{
//			printf("%d * %d = %d\t", p, i, i * p);
//		}
//		printf("\n");
//	}
//
//}
//
//
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int p = 0;
//	int a = 0;
//	scanf("%d", &a);
//	print(i, p , a);
//
//	return 0;
//}



//void swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("输入前：");
//	scanf("%d %d", &a, &b);
//	swap(&a, &b);
//	printf("输入后：%d %d", a, b);
//
//	return 0;
//}
//int is_leap_year(int year)
//{
//	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
//}
//
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//	if (is_leap_year(year))
//	{
//		printf("是闰年\n");
//	}
//	
//	return 0;
//}
void su_shu(int i)
{
	int c = 0;
	int a = 0;
	for (c = 2; c <= sqrt(i); c++)
	{
		if (i % c == 0)
		{
			
			a = 1;
			break;
		}
	}
	if(a == 0)
	printf("%d ", i);
}


int main()
{
	int a = 0;
	for (a = 101; a < 200; a += 2)
	{
		su_shu(a);
	}



	return 0;
}











