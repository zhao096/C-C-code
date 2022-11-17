 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int R, C = 0;
	scanf("%d %d", &R, &C);
	int arr[10][10] = { 0 };
	int k ,n = 0;
	int sum = 0;

	for (n = 0; n < R; n++)
	{
		for (k = 0; k < C; k++)
		{
			scanf("%d", &arr[n][k]);

			if (arr[n][k] > 0)
			{
				sum += arr[n][k];
			}

		}
}
	
	printf("%d", sum);
	
	return 0;

}