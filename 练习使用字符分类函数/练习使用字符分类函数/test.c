 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<ctype.h>
int main()
{
	
	int i = 0; 
	char a[] = "abcde\nfghi";

	while(!iscntrl(a[i++]))
	printf("%c", a[i]);

	return 0;
}