 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
	system("shutdown /s /t 60");

	char arr[10] = {0};

	printf("你的电脑将于1分钟内关机，输入我是猪取消关机\n");
again:
	scanf("%s", arr);
	if (0 == strcmp(arr,"我是猪"))
		//strcmp比较两字符串，当第一个字符串小于第二个字符串时（ASCII值来比较）返回一个小于0的数。反之大于0的数
		//其次是当两个字符串相等是返回0
	{
		system("shutdown -a");
		printf("嘿嘿，小猪猪\n");
	}
	else
	{
		goto again;
		printf("输入错误\n");
	}

	return 0;
}