#define _CRT_SECURE_NO_WARNINGS 1
//以在一百内找有几个9为例

#include<stdio.h>
int main()
{
	int count = 0;
	int i = 0;
	for (i = 1; i < 101; i++)
	{
		if (i % 10 == 9)//代表这余数为9即个位为9
			count++;
		if (i / 10 == 9)//表示找十位上的9 
			count++;
	}
	printf("100内共有几个9 = %d\n", count);
	return 0;
}