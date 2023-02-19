 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
union A
{
	char arr;
	int i;
};

int Judge_system(union A* a)
{
	a->i = 1;
	return a->arr;
}
int main()
{
	union A a = {0};
	//printf("%d", sizeof(union A));

	int ret = Judge_system(&a);
	if (ret == 0)
	{
		printf("¥Û∂À\n");
	}
	else
	{

		printf("%d–°∂À\n",ret);
	}
	return 0;
}