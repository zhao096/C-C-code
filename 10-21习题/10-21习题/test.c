#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int func(int a)
//{
//    int b;
//    switch (a)
//    {
//    case 1: b = 30;
//    case 2: b = 20;
//    case 3: b = 16;
//    default: b = 0;
//        return b;
//    }
//}
//int main()
//    {
//        int i = 0;
//        func(i);
//        printf("%d\n", func(i));
//
//        return 0;
//    }



//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 100; i++)
//	{
//		if(i % 3 == 0)
//		printf("%d ", i);
//	}
//
//	return 0;
//}

//#define M 3
//#include<stdio.h>
//int main()
//{
//	int arr[M] = { 0 };
//	int i = 0;
//	while (i < M)
//	{
//		scanf("%d", &arr[i]);
//		i++;
//	}
//	for(i = 0; i < M ; i++)
//	{
//		 int n = 0;		
//		 for (n = 1; n < M - i ; n++)
//		 {
//			 if (arr[i] < arr[i+n])
//			 {
//				 int a = arr[i];
//				 arr[i] = arr[n+i];
//				 arr[n+i] = a;
//			 }
//		 }
//
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	
//	for (a = 101; a < 200; a += 2 )
//	{
//		int i = 0;
//		for( i = 2; i < 9;i++)
//		{
//			if (a % i == 0)
//			{
//				break;
//			}
//
//		}
//		if (i == 9)
//		{
//			printf("%d ", a);
//		}
//	}
//
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int num = 0;
//	for (a = 1000; a <= 2000; a++)
//	{
//		if (a % 400 == 0 || a % 4 == 0 && a % 100 != 0)
//		{
//			printf("%d ", a);
//			num++;
//		}
//	}
//	printf("num = %d", num);
//
//	return 0;
//}
//#define MAX(x,y) (x > y ? x : y)
//
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d %d", &a, &b);
//	if (a < b)
//	{
//		c = a;
//		a = b;
//		b = c;
//	}
//	//else
//	//{
//	//	c = b;
//	//}
//	c = b;
//	for (; c > 0; c--)
//	{
//		if (a % c == 0 && b % c == 0)
//		{
//			printf("最大公约数 = %d \n", c);
//			break;
//		}
//	}
//	return 0;
//}
#include<stdio.h>
Max_gys(int a, int b)
{
	if (a < b)
	{
		int i = a;
		a = b;
		b = i;
	}
	if (a % b == 0)
		return b;
	else
		return Max_gys(b, a % b);

}

int main()
{
	int a = 0;
	int b = 0;
	scanf(" %d %d", &a, &b);
	int c = Max_gys(a, b);
	printf("%d", c);

	return 0;
}





























