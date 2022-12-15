#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	char arr[13] = { 0 };
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 13; i++)
//	{
//		arr[i] = ' ';
//	}
//
//	int mid = (sizeof(arr) / sizeof(arr[0])) / 2;
//	arr[mid] = '*';
//	for (i = 0; i < 13; i++)
//	{
//		printf("%c", arr[i]);
//	}
//	printf("\n");
//
//	int r = mid + 1;
//	int l = mid - 1;
//	for(i = 0 ; i <6 ; i++)
//	{
//
//		arr[l] = '*';
//		arr[r] = '*';
//		for (j = 0; j < 13; j++)
//		{
//			printf("%c", arr[j]);
//		}
//		printf("\n");
//
//		l--;
//		r++;
//	}	
//
//	for(i = 0 ; i< 6 ; i ++)
//	{
//		l++;
//		r--;
//		arr[l] = ' ';
//		arr[r] = ' ';
//		for (j = 0; j < 13; j++)
//		{
//			printf("%c", arr[j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}
////#include<stdio.h>
////int main()
////{
////	char arr[13][13] = { 0 };
////	int i = 0;
////	int j = 0;
////	for (i = 0; i < 13; i++)
////	{
////		for (j = 0; j < 13; j++)
////		{
////			arr[i][j] = ' ';
////		}
////	}
////	int mid = (sizeof(arr) / sizeof(arr[0])) / 2;
////
////	arr[i][mid] = '*';
////
////	return 0;
////}


int main()
{
	int line = 0;//ÉÏ°ë²¿·Ö
	scanf("%d", &line);
	int i = 0;
	for (i = 0; i < line; i++)
	{
		int j = 0;
		for (j = 0; j < line-i - 1; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2*i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 0; i < line -1 ; i++)
	{
		int j = 0;
		for (j = 0; j <= i ; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * (line - i - 2) + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}



