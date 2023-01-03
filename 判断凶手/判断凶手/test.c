#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//思想：从A~D进行赋值，其中1为凶手 ，其余的都不
// 
//int main()
//{
//	int a=0, b=0, c=0, d=0;
//	for ( a = 1; a <=2; a++)
//	{
//		for ( b = 1; b <=2; b++)
//		{
//			for ( c = 1; c <= 2; c++)
//			{
//				for ( d = 1; d <= 2; d++)
//				{
//					if (((a != 1) + (c == 1) + (d == 1) + (d != 1)) == 3)
//					{
//						if ((c == 1) && (d == 1))
//						{
//							continue;//此处不能用break否则当c=1 d= 1 后就会直接跳到c=2 而不是到d = 2 就会缺失
//						}
//						else
//						goto mur;
//					}
//				}
//			}
//		}
//	}
//
//mur:
//	if (c == 1)
//	{
//		printf("c");
//	}
//	if (d == 1)
//	{
//		printf("d");
//	}
//	return 0;
//}

int main()
{
	int killer = 0;
	for (killer = 'A'; killer <= 'D'; killer++)//附字符A~D相邻通过++方式可以访问,思想：从A~D一个个判断
	{
		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
		{
			printf("凶手是%c", killer);
		}
	}

	return 0;
}
