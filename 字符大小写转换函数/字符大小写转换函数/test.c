 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<ctype.h>
int main()
{
	if(isupper('A'))
		printf("A\n");
	if (islower('a'))
		printf("a\n");

	printf("%c\n", toupper('a'));
	
	printf("%c\n", tolower ('A'));


	return 0;
}