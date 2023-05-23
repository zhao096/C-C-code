 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
void swap(char* x, char* y)
{
	char tmp = *x;
	*x = *y;
	*y = tmp;
}
void bubule(char* a)
{
	for (int i = 0; i < strlen(a) - 1; i++)
	{
		int tag = 0;
		for (int j = 0; j < strlen(a) - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(&a[j],&a[j+1]);
				tag = 1;
			}
		}
		if (!tag)
		{
			break;
		}
	}

}
int main()
{
	char a[] = "kjihfedcba";
	bubule(a);
	printf("%s", a);

	return 0;
}