// #define _CRT_SECURE_NO_WARNINGS 1
//int main()
//{
//	int i = 1;
//	do
//	{
//		printf("%d", i++);
//	} while (i--);
//
//	return 0;
//}
#include<string.h>
#include<stdio.h>
int main()
{
	char arr[] = "I like beijing.";
	int num = (strlen(arr) - 1)/2; //三个ysu需要退3-1次
	int i = 0;
	while (num--);
	{
		while (i < num -1)
		{
			char tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
		}
	}
	printf("%s", arr);
	return 0;

}