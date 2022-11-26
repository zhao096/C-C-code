 #define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<stdio.h>

int my_strlen(const char* string)
{
	assert(string);
	int count = 0;
	while( *string++ != '\0')
	{	
		count++;
	}
	return count;
}
int main()
{
	char arr[] = "abcdef";
	printf("%d", my_strlen(arr));
	return 0;
}