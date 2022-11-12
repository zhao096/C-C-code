 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	char arr[] = {1,2,3,4,5,6,7,8,9};
	int i = 0;
	for(i = 0 ;  i< 9 ; i++)
	printf("%d ", arr[i]);
	printf("\n");

		memset(arr, 1, 4);


	for (i = 0; i < 9; i++)
	printf("%d ", arr[i]);

	return 0;
}