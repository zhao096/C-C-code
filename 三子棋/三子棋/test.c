 #define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("************************\n");
	printf("*******1.  play  *******\n");
	printf("*******0.  exit  *******\n");
	printf("************************\n");
 }
void game()
{
	//都在内实现游戏的运行
	char board[ROW][COL];//储出数据   --- 二维数组


	InitBoard(board, ROW, COL);
	//打印一下棋盘--本质打印数组内容

	DisplayBoard(board, ROW, COL);
	char ret = 0;
	while (1)
	{	
		//玩家下棋
		playeromove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
         ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;

		computermove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		 ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("赢了\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了\n");
	}
	else
	{
		printf("平局\n");
	}
	DisplayBoard(board, ROW, COL);

}
int main()
{
	int input = 0;	
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:");
		scanf("%d", &input);
		switch (input)//根据input做选择
		{
		case 1:

			printf("三子棋游戏\n");
			game();
			break;

		case 0:

			printf("退出游戏\n");
			break;

		default:

			printf("选择错误,重新选择\n");
			break;
		}

	} while (input);//查看是否是0若为0才跳出
	return 0;
}











//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row; i++)
//	{
//		printf(" %c ", board[i][j]);
//		if (j < col - 1)
//		{
//			printf("|");
//		}
//		printf("\n");
//		printf("---");
//		if (j < col - 1)
//			printf("|");
//		j++;
//	}