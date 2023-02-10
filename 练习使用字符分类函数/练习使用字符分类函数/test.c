 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<ctype.h>
int main()
{
	
	int i = 0; 
	char a[] = "abcde\nfg\nef";
	
	//int iscntrl(int c);传进字符的ASCII码值//在ASCII码中0~31和127共33个控制字符
	while (!iscntrl(a[i]))//如果是控制字符返回非零的数，再！为假跳出循环
	{
		printf("%c", a[i++]);

	}

	printf("\n"); i++;
	
	while (!isspace(a[i]))//从f开始//遇到空白字符就会返回非0的数，再同理...
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

		printf("ispunct");

	printf("\n");

	return 0;
}