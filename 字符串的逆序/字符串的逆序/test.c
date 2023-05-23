 #define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
void reverse(char a[])
{
	int left = 0, right = strlen(a) - 1;
	while (left < right)
	{
		char tmp = a[left];
		a[left] = a[right];
		a[right] = tmp;
		left++;
		right--;
	}
}
int main()
{

	char a[] = "abcdef";
	reverse(a);
	printf("%s\n", a);
	return 0;
}