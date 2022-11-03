 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int password = 0;
	printf("请输入密码:\n");
	scanf("%d", &password);
	printf("确认密码(Y/N):\n");
	char i = getchar();
	if (i == 'Y')
		printf("确认成功\n");
	else
		printf("确认失败\n");
	return 0; 
}

//int main()
//{
//	int password = 0;
//	printf("请输入密码:\n");
//	scanf("%d", &password);
//	printf("确认密码(Y/N):\n");
//	while ( getchar() != '\n')
//	{
//		;
//	}
//	char i = getchar();
//	if (i == 'Y')
//		printf("确认成功\n");
//	else
//		printf("确认失败\n");
//	return 0;
//}