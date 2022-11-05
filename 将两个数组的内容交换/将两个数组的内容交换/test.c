 #define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8 };
//	int arr2[] = { 8,7,6,5,4,3,2,1 };
//	int i = 0;
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	while (i < sz)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//		i++;
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", arr1[i]);
//
//	}
//	printf("\n");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", arr2[i]);
//
//	}
//
//	return 0;
//}

//void Swap(char arr1[], char arr2[], int sz)
//{
//	int i = 0;
//	while (i < sz)	
//	{
//		char tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//		i++;
//	}
//}
//
//#include<stdio.h>
//int main()
//{
//	//int arr1[] = { 1,2,3,4,5,6,7,8 };
//	//int arr2[] = { 8,7,6,5,4,3,2,1 };
//	char arr1[] = "abcdef";
//	char arr2[] = { 'g','h','i','z','k','l','\0' };
//	int i = 0;
//	int sz = sizeof(arr1) / sizeof(arr1[0]) - 1;
//	Swap(arr1, arr2, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%c", arr1[i]);
//
//	}
//	printf("\n");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%c", arr2[i]);
//
//	}
//
//	return 0;
//}


char Swap(char arr1[], char arr2[], int sz)
{
	char tmp = 0;
	if (sz < 0)
		return 0;
	else
		tmp = arr1[sz];
		arr1[sz] = arr2[sz];
		arr2[sz] = tmp;
		return Swap(arr1, arr2, sz - 1);
}

#include<stdio.h>
int main()
{
	//int arr1[] = { 1,2,3,4,5,6,7,8 };
	//int arr2[] = { 8,7,6,5,4,3,2,1 };
	char arr1[] = "abcdef";
	char arr2[] = { 'g','h','i','z','k','l','\0' };
	int i = 0;
	int sz = sizeof(arr1) / sizeof(arr1[0]) - 1;
	Swap(arr1, arr2, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%c", arr1[i]);

	}
	printf("\n");
	for (i = 0; i < sz; i++)
	{
		printf("%c", arr2[i]);

	}

	return 0;
}