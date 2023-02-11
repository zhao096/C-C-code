 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	char arr[] = 0;
	scanf("%s", arr);
	char arr_chcek = 0;
	scanf("%s", arr_chcek);
	int i = 0;
	for (i = 0; i < strlen(arr); i++)
	{
		char tmp = arr[i];
		if (strstr(arr, tmp) != NULL)
		{
			*(strstr(arr, tmp)) = ' '
		}
	}
	return 0;
}