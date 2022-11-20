#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int arr1[3][4] = { 1,2,3,4,5,6,7,8,9,10 ,11,12};//完全初始化
//	int arr2[3][4] = { 1,2,3,4,5 };//不完全初始化
//	int arr3[3][4] = { {1,2},{3,4},{5,6} };//单独对于一列的初始化
//	//二维数组行可以省略，但是列不可以省略
//	int arr4[][4] = { 1,2,3,4,5,6,7,8,9, };
//	printf("%d", arr4[1][1]);
//	int R = sizeof(arr4) / sizeof(arr4[0]); //求出总共有几行
//	int C = sizeof(arr4[0]) / sizeof(arr4[0][0]);//求出有几列
//	return 0;
//}
//void test (void)//不要参数
//{
//
//		;
//
//}
//
//int main()
//{
//	int n = 0;
//		test(n);
//
//}
//
//#include<stdio.h>
//int main() {
//
//	//char arr[] = { 0 };
//	char arr[] = { 'a',48,'c' ,'0'};
//	printf("%s", arr);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//    int arr[10] = { 0 };
//    int i = 0;
//    int sz = sizeof(arr) / sizeof(arr[0]);
//
//    for (i = 0; i < sz; ++i)
//    {
//        printf("&arr[%d] = %p\n", i, &arr[i]);
//    }
//    return 0;
//}
//#include <stdio.h>
//int main()
//{
//    int arr[3][4] = { 0 };
//    int i = 0;
//    int j = 0;
//    for (i = 0; i < 3; i++)
//    {
//        for (j = 0; j < 4; j++)
//        {
//            scanf("%d", &arr[i][j]);
//        }
//    }
//    for (i = 0; i < 3; i++)
//    {
//        for (j = 0; j < 4; j++)
//        {
//            printf("%d ", arr[i][j]);
//        }
//    }
//        return 0;
#include <stdio.h>
//int main()
//{
//	int arr[3][4];
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]);
//		}
//	}
//	return 0;
//}
//int main()
//{
//    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//    int i = 0;
//    for (i = 0; i <= 10; i++)
//    {
//        printf("%d\n", arr[i]);//当i等于10的时候，越界访问了
//    }
//    return 0;
//}
