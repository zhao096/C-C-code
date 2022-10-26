#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//    int i = 0;
//    int j = 1;
//    for (i = 1; i < 10; i++)
//    {
//        for (j = 1; j <= i; j++)
//        {
//            printf("%d * %d = %d   ", j, i,i * j);
//        }
//        printf("\n");
//    }
//
//    return 0;
////}
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int b = 0;
//	for (b = 1; b < 10; b++)
//	{
//		if (arr[0] < arr[b])
//		{
//			int n = arr[0];
//			arr[0] = arr[b];
//			arr[b] = n;
//			b = 1;
//		}
//	}
//	printf("%d", arr[0]);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	double sum = 0;
//	int var = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		double a = var*(1.0 / i);
//		sum += a;
//		var = -var;
//	}
//	printf("%lf\n", sum);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int i = 0;	
//	int num = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i / 10 == 9 || i % 10 == 9)
//		{
//			num++;
//			printf("%d ", i);
//		}
//
//	}
//	printf("\n");
//	printf("%d", num);
//
//
//	return 0;
//}
#include<stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 1;
	int L = 0;
	int R = sizeof(arr) / sizeof(arr[0]) -1;
	while (L < R)
	{
		int mid = (R + L) / 2;

		if (k < arr[mid])
		{
			R = arr[mid] - 1;
		}
		else if (k > arr[mid])
		{
			L = arr[mid] + 1;
		}
		else
		{
			printf("找到了是:%d\n",arr[mid]);
			break;
		}
	}
	if (L >= R)
	{
		printf("找不到\n");
	}
	return 0;
}




