 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
void play()
{
	int n = 0;
	int k = rand() % 100 + 1;

	while (1)
	{

		scanf("%d", &n);
		if (n < k)
		{
			printf("猜小了\n");
		}
		else if (n > k)
			printf("猜大了\n");
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}

	}



}
void menu()
{
	printf("********************\n");
	printf("****** 1. 开始 *****\n");
	printf("****** 0. 退出 *****\n");
	printf("********************\n");
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do//先确认是否玩游戏，假如后面玩了且玩完了可以再次进行选择
	{
		menu();
		printf("是否玩游戏:(1/0)\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("猜数字游戏\n");
			play();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新输入\n");
			break;
		}
	} while (input);

	return 0;
}