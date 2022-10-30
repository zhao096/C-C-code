 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		if (5 == i)
//		{
//			continue;
//		}
//		printf("%d ", i);
//
//	}
//	return 0;
//}

int main()
{
	int i = 0;
	while (i < 10)
	{
		i++;
		if (5 == i)
		{
			continue;
		}
		printf("%d ", i);
		
	}


	return 0;
}