 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int y = 0;
//	int m = 0;
//	scanf("%d %d", &y, &m);
//	if (m == 2)
//	{
//		if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
//			printf("%d", 29);
//		else
//			printf("%d", 28);
//	}
//	else if (m <= 7)
//	{
//		if (m % 2 == 0)
//			printf("%d", 30);
//		else
//			printf("%d", 31);
//	}
//	else
//	{
//		if (m % 2 == 0)
//			printf("%d", 31);
//		else
//			printf("%d", 30);
//	}
//
//	return 0;
//}
int main()
{
	int y = 0;
	int m = 0;
	while ((scanf("%d %d", &y, &m)) == 2)
	{
		int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int day = a[m];
		if (m == 2 && ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0)))
		{
			day++;
		}
		printf("%d\n", day);
	}
	

	return 0;
}