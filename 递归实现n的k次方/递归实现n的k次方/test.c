 #define _CRT_SECURE_NO_WARNINGS 1
double Pow(int n, int k)
{
	if (k == 0)
		return 1.0;
	else if (k > 0)
		return n * Pow(n, k - 1);
	else
		return 1.0 / Pow(n, -k);
}

#include<stdio.h>
int main()
{
	int n = 0;
	int k = 0;
	double ret = 0.0;
	scanf("%d %d", &n, &k);
	ret = Pow(n, k);
	printf("%lf", ret);
	return 0;
}