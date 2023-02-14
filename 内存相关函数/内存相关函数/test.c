 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//int main()
//{
//    int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//    int arr1[10] = { 0 };
//    memcpy(arr1, arr, 20);//¿½±´5¸öint 4 * 5 = 20 byte
//    for(int i = 0; i<10 ; i++)
//    printf("%d ", arr1[i]);
//    return 0;
//
//}
int main()
{
	int arr1[] = { 1,4,7 };

	int arr2[] = { 1,4,2 };

	int ret = memcmp(arr1, arr2,sizeof(arr1));

	printf("%d", ret);

	return 0;
}