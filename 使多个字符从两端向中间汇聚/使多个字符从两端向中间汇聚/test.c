 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

int main()
{
	char arr1[] = "####################";
	char arr2[] = "welcome to Yun Nan..";
	int i = 0;
	int r = strlen(arr1)-1;
	printf("%s\n", arr1);

	for (i = 0,r = strlen(arr1) -1; i <= r; i++,r--)
	{
		Sleep(1000);
		system("cls");
		arr1[i] = arr2[i];
		arr1[r] = arr2[r];
		printf("%s\n", arr1);
	}
	return 0;
}