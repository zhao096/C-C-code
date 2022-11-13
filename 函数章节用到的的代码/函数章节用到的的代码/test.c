#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//void leave(int a)	
//{
//	if (a / 10 != 0)  //当a / 10 不等于0说明他是一个大于10的数
//	{
//		leave(a / 10);
//	}
//	printf("%d ", a % 10);//打印
//	//当递归回来时就会下来打印
//}
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	leave(a);
//
//
//	return 0;
//}
//int leave(int a)
//{
//	if (a / 10 == 0)//先设置限制条件,到个位
//	{
//		printf("%d ", a % 10);
//		return 0;//当进到限制内就会开始返回
//	}
//	leave(a / 10);
//	printf("%d ", a % 10);//返回后就会下来打印  当第一次返回时会变12余（莫）2并打印
//	return 0;//此处可以不写但会有一个警告而已
//}
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	leave(a);
//
//
//	return 0;
//}
//int Strlen(int sz)
//{
//	if (sz == 0)
//		return 1;
//	else
//		return 1 + Strlen(sz - 1);
//
//}
//
//int main()
//{
//	char a[]= "abcd";
//	int sz = sizeof(a) / sizeof(a[0]) - 2; //减2因为首先要剪掉最后的\0和减掉因为数组是从 0 开始的 0 ~ 3
//	int n = Strlen(sz);
//	printf("%d", n);
//	return 0;
//}
//int Strlen(char a[])
//{
//	if (*a == '\0')
//		return 0;
//	else
//		return 1 + Strlen(a+1);
//}
//
//int main()
//{
//	char a[] = "abcd";
//	int n = Strlen(a);
//	printf("%d", n);
//	return 0;
//}
//int Fac(int x)
//{
//	if (x <= 2)//因为前俩个无法相加
//	{
//		return 1;//当减到小于等于2时就直接为1并返回
//	}
//	else
//	{
//		return Fac(x - 2) + Fac(x - 1);//加上前两个数
//	}
//}
//int main()
//{
//	int i = 0;
//	scanf("%d", &i);
//	int n = Fac(i);
//	printf("%d", n);
//	return 0;
//}

int Fac(int x)
{
	int a = 1;
	int b = 1;
	int sum = 0;

	for (; x > 2; x--)
	{
		sum = a + b;
		a = b;
		b = sum;
	}
	return sum;
}
int main()
{
	int i = 0;
	scanf("%d", &i);
	int n = Fac(i);
	printf("%d", n);
	return 0;
}