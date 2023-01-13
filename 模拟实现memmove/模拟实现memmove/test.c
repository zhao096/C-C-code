#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	//Ä£ÄâÊµÏÖmemmove    void *memmove( void *dest, const void *src, size_t count );
	char arr1[] = "abcdef";
	char arr2[] = "qwer";
	char* p = (char*)memmove(arr1, arr2, 4);
	printf("%s", p);
	return 0;
}