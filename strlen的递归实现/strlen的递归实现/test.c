#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int my_strlen(char* i)
{
	if (*i == '\0')
		return 0;
	else
	{
		i++;
		return 1 + my_strlen(i);
	}
	
}
int main()
{
	char arr[] = "bit";
	int num = my_strlen(arr);
	printf("%d", num);
	return 0;
}