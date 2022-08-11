 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 0;
	double sum = 0.0;//double使输出的数也能为带有小数的使其保持正确
	int ret = 1;//保证数据不会改变
	for (i = 1; i <= 100; i++)
	{
		 sum +=  ret * 1.0 / i;//在除数和被除数中带上一个小数可使最终的积也为小数
		 ret = -ret;//是正负交替进行
	}
	printf("%lf", sum);
	return 0;
}