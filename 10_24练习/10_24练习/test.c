 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int a = 0;
//
//	while ( a  == 0)
//	{
//		printf("%d\n", a);
//
//	}
//	printf("hh");
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int sum = 0;
//	int b = 0;
//	scanf("%d", &b);
//	for (i = 1; i <= b; i++)
//	{
//		int a = 1;
//		for (int j = 1; j <= i; j++)
//		{
//			a *= j;
//		}
//		sum += a;
//	}
//	printf("%d\n", sum);
//	return 0;
//}


int main()
{
	int i = 0;
	int n = 0;
	int sum = 1;
	int add = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		sum *= i;
		add += sum;
	}
	printf("%d ", add);

	return 0;
}










