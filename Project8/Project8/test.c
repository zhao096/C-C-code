 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

void swap(char* a, char* b)
{

}

void sort(char* name[], int n)
{
	//选择排序来排 
	int i, j;

	for (i = 1; i < n; i++)
	{
		int tmp = i;
		for (j = tmp - 1; j >= 0; j--)
		{
			if (strcmp(name[tmp], name[j]) < 0)
			{
				char* tmp1 = name[tmp];
				name[tmp] = name[j];
				name[j] = tmp1;//char * tmp1 = name[tmp] 存的是地址（name[tmp]），此时tmp1表示的就是地址，而*tmp就找到了其内容了
				tmp--;
			}
			else
			{
				break;
			}

		}
	}
}



int main()
{
	char* name[] = { "Follow me","BASIC",
	"Great Wall","FORTRAN","Computer design" };

	int n = 5;
	sort(name, n);

	for (n = 0; n < 5; n++)
	{
		printf("%s\n", name[n]);
	}


	return 0;
}
