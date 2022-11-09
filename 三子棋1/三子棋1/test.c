 #define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	char re = 0;//声明存储是否赢了的标志
	char arr[ROW][COL] = {0};
	init(arr, ROW, COL);
	print(arr, ROW, COL);
	while (1)
	{
		play_move(arr, ROW, COL);
		print(arr, ROW, COL);
		/*printf("电脑走\n");*/
		/*Sleep(2000);*/
		re = is_win(arr, ROW, COL);
		if (re != 'Q')
		{
			break;
		}
		system("cls");
		comput_move(arr, ROW, COL);
		print(arr, ROW, COL);
		re = is_win(arr, ROW, COL);

		if (re != 'Q')
		{
			break;
		}

	}
	if(re == 'O')
	{
		printf("恭喜玩家赢了\n");
	}
	else if (re == 'B')
	{
		printf("平局\n");
	}
	else
	{
		printf("电脑都比你吊\n");
	}



}
void mnue()
{
	printf("**********************\n");
	printf("*******  1. play  ****\n");
	printf("*******  0. exit  ****\n");
	printf("**********************\n");
}

int main()
{
	int input = 0;
	do
	{
		mnue();
		printf("是否玩游戏(1/0):>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			printf("猜数字游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}

	} while(input);




	return 0;
}