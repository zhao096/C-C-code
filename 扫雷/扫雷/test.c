 #define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void mune()
{
	printf("*********************************\n");
	printf("********    1.开始游戏   ********\n");
	printf("********    0.退出游戏   ********\n");
	printf("*********************************\n");

}
void play()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };


	//初始化棋盘
	IntiBoard(mine, ROWS, COLS,'0');//'0'
	IntiBoard(show, ROWS, COLS,'*');//'*'

	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//布置雷
	DispalyMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	
	//排差雷
	CheckMine(mine,show, ROW, COL);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		mune();
		printf("是否玩游戏:>");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			printf("     扫雷游戏\n");
			play();
			break;
		case 0:
			printf("退出游戏\n");
		default:
			printf("输入错误\n");
		}

	} while (input);

	return 0;
}