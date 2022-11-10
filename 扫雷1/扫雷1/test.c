 #define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


void play()
{
	printf("---------扫雷----------\n");

	//初始化两个棋盘一个用来存雷mine 雷用 '1'表示正常的用‘0’表示
	//另一个用来展示给玩家show  给玩家看到的是*
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	init(mine, ROWS, COLS, '0');
	init(show, ROWS, COLS, '*');
	//
	//printf("\n");
	print(show, ROW, COL);

	set_mine(mine, ROW, COL);
	print(mine, ROW, COL);


	check_mine(mine, show, ROW, COL);
	

}
void mnue()
{
	printf("**************************\n");
	printf("*******    1.play    *****\n");
	printf("*******    0.exit    *****\n");
	printf("***************************\n");

}
void test()
{
	int input = 0;
	do
	{
		mnue();
		printf("是否玩游戏:>(1/0)");
		scanf("%d", &input); 
		printf("\n");
		switch (input)
		{
		case 1:
			play();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default :
			printf("输入错误，请重新输入\n");
			break;
		}

	} while (input);


}


int main()
{
	srand((unsigned int)time(NULL));
	test();
	return 0;
}