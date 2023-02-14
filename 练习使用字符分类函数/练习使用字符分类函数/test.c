 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<ctype.h>
int main()
{
	
	int i = 0; 
	char a[] = "abcde\nfg\nef";
	
	//int iscntrl(int c);传进字符的ASCII码值
	while (!iscntrl(a[i]))//如果是控制字符返回非零的数，再！为假跳出循环
	{
		printf("%c", a[i++]);	

	}

	printf("\n"); i++;
	
	while (!isspace(a[i]))//从f开始遇到 空白字符 就会返回非0的数
	{
		printf("%c", a[i++]);
	}
	
	printf("\n");  

	if(isdigit('6')) //检查是不是字符数字0~9
		printf("isdigit");

	
	printf("\n");


	if(isxdigit('f'))//十六进制0~f

		printf("isxdigit");
	
	printf("\n");


	if (islower('z'))//为小写字母，返回非0的数

		printf("islower");

	printf("\n");


	if (isupper('A'))//大写字母

		printf("isupper");

	printf("\n");

	if (isalpha('A')&& isalpha('a'))//大小写都行

		printf("isalpha");


	printf("\n");

	if (isalnum('3' ) && isalnum('a'))//数字和大小写字母

		printf("isalnum");

	printf("\n");


	if (ispunct('@'))//除数字，字母的标点符号的图形字符
	{ 
		printf("ispunct");
	}
	printf("\n");
	 
	if (isgraph('@'))//除了空格的可打印出的字符
	{
		printf("isgraph");
	}
	printf("\n");
	
	if (isprint('!'))//判断是不是可打印字符
	{
		printf("isgraph");
	}
	printf("\n");

	return 0;
}