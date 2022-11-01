 #define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int n_de_k_ci(int x, int k)
//{
//	if (k == 0)
//		return 1;
//	else
//		k--;
//	return x * n_de_k_ci(x,k);
//}
//int main()
//{
//	int k = 0;
//	int n = 0;
//	scanf("%d %d", &n, &k);
//	printf("n = %d k = %d \n", n, k);
//	int num = n_de_k_ci(n, k);
//	printf("nµÄk´Î = %d", num);
//	return 0;
//}


#include<stdio.h>
int DigitSum(int n)
{
	if (n < 9)
	{
		return n % 10;
	}
	else
		return n % 10 + DigitSum(n / 10);
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int num = DigitSum(n);
	printf("%d", num);
	return 0;
}