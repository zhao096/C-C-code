 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//double mao_pao(double arr[1000],int sz)
//{
//	int a = 0;
//	for (a = 0; a < sz ; a++)
//	{
//		int k = 0;//注意
//		int i = 0;
//
//		for (i = 0; i < sz-a-1; i++)
//		{
//
//			if (arr[i] > arr[i + 1])
//			{
//				double t = arr[i];
//				arr[i] = arr[i + 1];
//				arr[i + 1] = t;//注意别错了
//				k = 1;
//			}
//		}
//		if (k == 0)
//		{
//			break;
//		}
//	}
//	arr[0] = 0;
//	arr[sz-1] = 0;
//	a = 0;
//	double sum = 0;
//	for (a = 0; a < sz; a++)
//	{
//		sum += arr[a];
//	}
//	return sum;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int tmp = n;
//	while (tmp--)//输入n个数据
//	{
//		int k = 0;
//		scanf("%d", &k);
//		int k1 = k;
//		double arr[1000] = { 0 };
//		while (k)//将每个数据输进
//		{
//			double i = 0;
//			scanf("%lf", &i);
//			if (i < 0)
//			{
//				i = 0;
//			}
//			if (i > 100)
//			{
//				i = 100;
//			}
//			arr[--k] = i;//注意点
//
//		}
//		double sum = mao_pao(arr, k1);//冒泡排序去掉最低和最高
//		k1 -= 2;
//		printf("%.2lf\n", sum / (k1));
//	}
//	return 0;
//}
//
int main()
{
	int n = 0;
	int k = 0;
	int k1 = 0;
	int j = 0;
	double max = 100;
	double min = 0;
	double arr[1000] = { 0 };
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &k);
		min = 100; max = 0;
		double sum = 0;//注意点要置回零

		for(j = 0; j < k ;j++)//注意点，既可以时数组内的值j增加也能循环k次
		{
			scanf("%lf", &arr[j]);
			if (arr[j] < min)
				min = arr[j];
			if (arr[j] > max)
				max = arr[j];
			sum += arr[j];
		}
		k -= 2;
		printf("%.2lf", (sum - min - max) / k);
	}
	return 0;
}
