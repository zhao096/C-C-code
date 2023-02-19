 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//struct A
//{
//	int a : 2;
//	int b : 5;
//	int c : 10;
//	int d : 30;
//};
//
//int main()
//{
//	
//	printf("%d", sizeof(struct A));
//
//	return 0;
//}


struct B
{
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
}b;

int main()
{
	b.a = 10;
	b.b = 12;
	b.c = 3;
	b.d = 4;

	printf("%d", sizeof(struct B));

	return 0;
}  