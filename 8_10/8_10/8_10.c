 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	printf("hehe\n");
//	main();
//	return 0;
//}
////递归自己调用自己
//void print(int num)
//{
//	if (num > 9)
//	{
//		print(num/10);
//	}
//	printf("%d ", num%10);
//}
//int main()
//{
//	 int num = 0;
//	scanf("%u", &num);
//	print(num);
//	return 0;
//}
int Fib(int r)
{
	if (r <= 2)
		return 1;
	else
		return Fib(r - 2) + Fib(r - 1);
}
int main()
	{
	int n = 0;
	scanf("%d", &n);
	int ret = Fib(n);
	printf("%d", ret);
	return 0;
	}