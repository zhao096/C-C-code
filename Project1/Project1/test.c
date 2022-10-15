#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
void menu()
{
	printf("*******************************\n");
	printf("********  1.   play    ********\n");
	printf("********  0.   exit    ********\n");
	printf("*******************************\n");
}
void play()
{
	char board[ROW][COL];

	InitBoard(board, ROW, COL);

    Dispalyboard(board, ROW, COL);

	//玩家走
	//电脑走
	playermove(board, ROW, COL);

	computermove(board, ROW,COL);

}
int main()
{
	int input = 0;
	int srand(ung)
	do
	{
		menu();

		printf("是否玩游戏，用数字代替文字输入:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("三子棋游戏\n");
			play();

			break;
		case 0:
			printf(" 退出游戏 \n");
			break;
		default:
			printf("输入错误,重新输入\n");
			break;
		}

	} while (input);
	return 0;
}