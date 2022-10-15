 #define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

	void DisplayBoard(char board[ROW][COL], int row, int col)
	{
		int i = 0;
		for (i = 0; i < row; i++)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf(" %c ", board[i][j]);
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
				if (i < row - 1)
				{
					int j = 0;
					for(j = 0; j < col; j++)
					{
						printf("---");
						if (j < col - 1)
							printf("|");
					}
					printf("\n");
				}
		}
     }

		playeromove(char board[][COL], int row, int col)
		{
			int x = 0;
			int y = 0;

			while (1)
			{
				printf("玩家走:\n");
				printf("请输入坐标:");
				scanf("%d %d", &x, &y);
				//判断合法性!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				if (x >= 1 && x <= row && y >= 1 && y <= col)
				{
					if (board[x - 1][y - 1] == ' ')
					{
						board[x - 1][y - 1] = '*';
						break;
					}
					else
					{
						printf("错误重新输入\n");
					}
				}
				else
				{
					printf("错误重新输入\n");
				}

			}

		}
		void  computermove(char board[][COL], int row, int col)
		{
			printf("电脑走:\n");
			while(1)
			{
				int x = rand() % row;
				int y = rand() % col;
				if (board[x][y] == ' ')
				{
					board[x][y] = '#';
					break;
				}
			}
		}
		int	IsFull(char board[][COL], int row, int col)      
		{
			int i = 0;
			int j = 0;
			for (i = 0; i < row; i++)
			{
				for (j = 0; j < col; j++)
				{
					if (board[i][j] == ' ')
					{
						return  0;
					}
				}
			}
			return 1;
		}
		char IsWin(char board[ROW][COL], int row, int col)
		{
			int i = 0;
			for (i = 0; i < row; i++)
			{
				if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
				{
					return board[i][1];
				}
			}
		
		for (i = 0; i < col; i++)
		{
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			{
				return board[i][1];
			}
		}
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		{
			return board[1][1];
		}

		int ret = IsFull(board, row, col);
		if (ret == 1)
		{
			return 'Q';//满了
		}
		return 'C';
		}