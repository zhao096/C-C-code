 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	printf("%d\n", sizeof(char));    // 1 byte×Ö½Ú
	printf("%d\n", sizeof(int));     // 4 
	printf("%d\n", sizeof(short));   // 2
	printf("%d\n", sizeof(long));    // 4  (long >= int)
	printf("%d\n", sizeof(float));   // 4
	printf("%d\n", sizeof(double));  // 8

	return 0;
}