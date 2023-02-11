#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//int if_turn(char arr[],char *s2)
//{
//	int ret = strlen(arr);
//	char arr1[10] = { 0 };
//	strcpy(arr1, arr);
//	int t1 = 1;
//	int sum = 0;
//	for (t1 = 1; t1 < ret; t1++)
//	{
//		int i = t1;
//		strcpy(arr, arr1);
//		int I = 0;
//		char tmp[10] = { 0 };
//		for (I = i; I >= 0; I--)//将前i个放到一个新的元素中，从后往前放
//		{
//			tmp[I - 1] = arr[I - 1];
//		}
//
//
//		for (I = i; I < strlen(arr); I++)//I将后面的几个元素往前放；即第i个(数组从0开始)开始向前i步放到第一个以此类推
//		{
//			arr[I - i] = arr[I];
//		}
//		int t = i;
//		for (I = 0; I < t; I++)//I从开始只需要i次 即将tmp中存放的元素放回arr中
//		{
//			arr[strlen(arr) - i] = tmp[I];//此处strlen(arr) - i 是为了当i>数组一半时仍可以正常，若为arr[i] = arr[I]的话如先前攒4个字符的话在abcdef中
//											//将变成efabcd而会在从arr[4]处开始返回就不对了,应该从arr【2】即从arr[strlen...]处开始放回
//			if (i > 0)
//				i--;
//		}
//		if((strcmp(arr,s2)!=0))
//		{
//			sum++;
//		}
//	}
//	if (sum != (strlen(arr) - 2))//abcd 的旋转情况只有3中其中一种是旋转的情况所以要再 - 1 
//	{
//		return 0;
//	}
//
//	return 1;
//}
//int main()
//{
//	char s1[10] = { 0 };
//	char s2[10] = { 0 };
//	scanf("%s %s", s1,s2);
//
//	int ret  = if_turn(s1,s2);
//	if (ret == 0)
//	{
//		printf("不是旋转后的字符串\n");
//	}
//	else
//	{
//		printf("是旋转后的字符串\n");
//	}
//	return 0;
//}

//
//void left_move(char arr[], int i)
//{
//
//	int str = strlen(arr);
//	i %= 6;//当大于6个是就会重复的向左移、余6就可以减少次数
//	for (int n = 0; n < i; n++)
//	{
//		char tmp = arr[0];
//
//		for (int t = 0; t < str - 1; t++)
//		{
//			arr[t] = arr[t + 1];
//		}
//
//		arr[str - 1] = tmp;
//
//	}
//}
//
//int if_left_move(char s1[] , char s2[])
//{
//	int str1 = strlen(s1);
//	int str2 = strlen(s2);
//	if(str1 != str2)
//	{
//		return 0;
//	}
//
//	while(str1--)
//	{
//		left_move(s1, 1);//一次次左移
//		if (!strcmp(s1, s2))//在一次次比较,如果相等返回1
//		{
//			return 1;
//		}
//	
//	}
//	return 0;
//}
//int main()
//{
//	char s1[10] = { 0 };
//	char s2[10] = { 0 };
//	scanf("%s %s", s1, s2);
//
//	int ret =if_left_move(s1, s2);
//	if (ret == 0)
//	{
//		printf("不是旋转后的字符串\n");
//	}
//	else
//	{
//		printf("是旋转后的字符串\n");
//	}
//	return 0;
//}
#include<string.h>
int if_left_move(char s1[], char s2[])
{
	int str1 = strlen(s1);
	int str2 = strlen(s2);
	if (str1 != str2)
	{
		return 0;
	}
	strncat(s1, s1,str1);
	if (strstr(s1, s2) != NULL)
	{
		return 1;
	}
	return 0;
}


int main()
{
	char s1[30] = { 0 };
	char s2[10] = { 0 };
	scanf("%s %s", s1, s2);

	int ret = if_left_move(s1, s2);

	if (ret == 0)
	{
		printf("不是旋转后的字符串\n");
	}
	else
	{
		printf("是旋转后的字符串\n");
	}
	return 0;
}