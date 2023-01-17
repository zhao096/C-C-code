 #define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     // atoi int atoi (const char * str);


int my_atoi(const char* str)
{	
	return *str - '\0';
}
int main()
{
	int i;
	char buffer[256];
	printf("Enter a number: ");
	fgets(buffer, 256, stdin);
	i = my_atoi(buffer);
	printf("The value entered is %d. Its double is %d.\n", i, i * 2);
	return 0;
}