#include<stdio.h>
int main()
{
	double m = 100;
	int i = 0;
	for (i = 1; i <= 10; i++)
	{
		m /= 2.0;
	}
	printf("%d",m);

	return 0;
}