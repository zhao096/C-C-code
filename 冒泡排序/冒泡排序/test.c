 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int arr[10] = { 0,4,2,3,1,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]) ;
	int i = 0;
	int j = 0;
	for (i = 0; i < (sz - 1); i++)//
	{

		int count = 0;

		for (j = 0; j < sz - 1 - i; j++)//d当你第一次没有交换时，说明后面的更大，但是j仍然会++，“这样就会使后面大的在和后面进行比较”
		{
			if (arr[j] >= arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;

				count = 1;
			}

		}
		if (count != 1)
		{
			break;
		}
	}

	for (i = 0; i < sz ; i++)
	{
		printf("%d", arr[i]);
	}

	return 0;
}


