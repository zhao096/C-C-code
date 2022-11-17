 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	int k[100] = { 0 };
	int t = 0;
	int sum = 0;
	int i = 0;
	for(i = 0; i < 100 ; i++)
	{
		t++;//t++个位乘1，十位乘6，....		

		k[i] = n % 6;//存每一位的余数，....
		n = n / 6;//得到商，给后面的循环
		if (n == 0)//当n/6 == 0时说明已经到除不了了，只有余数了，就应该跳出来
		{

			break;
		}
	}
	int a = 1;

	for (i = 0; i < t; i++)
	{
		sum = sum + (k[i] * a);
		a *= 10;
	}
	printf("%d", sum);

	return 0;
}