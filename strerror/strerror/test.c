 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<errno.h>

//strerror是返回错误码所对应的错误消息
//而错误码是：1、2、3、4、5组成无法直接看出错误所以需要strerror来翻译翻译成错误消息
int main()
{

	//printf("%s\n", strerror(0));
	//printf("%s\n", strerror(1));
	//printf("%s\n", strerror(2));
	//printf("%s\n", strerror(3));
	//printf("%s\n", strerror(4));
	//printf("%s\n", strerror(5));
	//打开文件

	FILE* pc = fopen("test.txt", "r");
	if (pc == NULL)
	{
		printf("%s\n", strerror(errno));
		perror("fopen");
		

	}

	FILE* p = fopen("test.c", "r");

	if (p == NULL)
	{
		perror("error is  of");

		return 1;
	}
	//读文件
	//关闭文件
	fclose(p);//注意里面的内容是一开始存打开文件的指针变量
	return 0;
}