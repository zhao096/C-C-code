 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void hanio(char A, char B, char C,int n)
{
	if(n == 0)
	{
		return;
	}
	hanio(A, C, B, n - 1);
	printf("%c->%c\n", A, C);
	hanio(B, A, C, n-1);
}
int main()
{
	int n = 3;
	hanio('A','B','C',n);
	return 0;
}