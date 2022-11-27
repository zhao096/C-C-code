 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void maopao_sort(int arr[100],int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)//冒泡排序
	{
		int count = 0;

		int j = 0;
		for (j = 0; j < sz-i; j++)//-i表示除去已经排过了的次数
		{

			if (arr[j] >= arr[j+1])//若一次都没有进去则表示从一个到最后一个，已经排好了不用再交换了
			{
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
				count = 1;
			}
		}
		if(count == 0)
		{
			break;
		}
	}

	
}

void Assignment(int arr3[100], int arr[100], int n ,int num)
{
	for (; n >= 0; n--)
	{
		arr3[num--] = arr[n];
	}
}
void scan(int arr[100],int tmp)
{
	for (; tmp >= 0; tmp--)
	{
		scanf("%d", &arr[tmp]);//输入值tmp 表示的是n / m  的值 
	}
}
int main()
{
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	int arr1[100] = { 0 };
	int arr2[100] = { 0 };
	int arr3[100] = { 0 };//把两个数组1,2放在一个数组内再进行冒泡排序
	scan(arr1, n-1);//减1是因为数组小标从0 开始
	scan(arr2, m-1);
	int num = ( n + m );
	Assignment(arr3, arr1,n-1,num-1);//assignment = 赋值
	Assignment(arr3, arr2,m-1,num-1 - n);//减去前面n的下标让num接在arr1继续存进去

	maopao_sort(arr3,num-1);

	int nu = num;//出一个num让其可以从0开始从小到大的打印
	for(num = 0 ; num < nu ; num++)
	{
		printf("%d ", arr3[num]);
	}
	return 0;
}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d %d", &n, &m);
//	int arr1[100] = { 0 };
//	int arr2[100] = { 0 };
//	int arr3[100] = { 0 };//把两个数组1,2放在一个数组内再进行冒泡排序
//	int n1 = n - 1;
//	int m1 = m - 1;//减1是因为数组小标从0 开始
//	for (; n1 >= 0; n1--)
//	{
//		scanf("%d", &arr1[n1]);//输入值tmp 表示的是n / m  的值 
//	}
//	for (; m1 >= 0; m1--)
//	{
//		scanf("%d", &arr2[m1]);//输入值tmp 表示的是n / m  的值 
//	}
//	m1 = m - 1;
//	n1 = n - 1;
//	int num = (n + m);
//	int num1 = num - 1;
//	for (; n1 >= 0; n1--)
//	{
//		arr3[num1--] = arr1[n1];
//	}//assignment = 赋值
//	//减去前面n的下标让num接在arr1继续存进去
//	for (; m1 >= 0; m1--)
//	{
//		arr3[num1--] = arr2[m1];
//	}
//	num1 = num - 1;
//
//	
//	int i = 0;
//	for (i = 0; i < num1; i++)//冒泡排序
//	{
//		int count = 0;
//
//		int j = 0;
//		for (j = 0; j < num1 - i; j++)//-i表示除去已经排过了的次数
//		{
//
//			if (arr3[j] >= arr3[j + 1])//若一次都没有进去则表示从一个到最后一个，已经排好了不用再交换了
//			{
//				int tmp = arr3[j];
//				arr3[j] = arr3[j + 1];
//				arr3[j + 1] = tmp;
//				count = 1;
//			}
//		}
//		if (count == 0)
//		{
//			break;
//		}
//	}
//
//
//	int nu = num;//出一个num让其可以从0开始从小到大的打印
//	for (num = 0; num < nu; num++)
//	{
//		printf("%d ", arr3[num]);
//	}
//	return 0;
//}