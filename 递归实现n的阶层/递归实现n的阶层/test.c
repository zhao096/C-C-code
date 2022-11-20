 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Fac(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * Fac(n - 1);


}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int sum = Fac(n);
	printf("%d", sum);

	return 0;
}