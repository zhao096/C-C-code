#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void menu()
{
	printf("***********************************\n");
	printf("*********  1.add    2.del    ******\n");
	printf("*********  3.search 4.modify ******\n");
	printf("*********  5.show   6.sort   ******\n");
	printf("********        0.exit       ******\n");
	printf("***********************************\n");
}


int main()
{
	int input = 0;
	struct contact con;//创建联系人变量

	Init_contact(&con);
	do
	{
		menu();
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		default:
			printf("选择错误\n");
			break;
		case Add:
			add(&con);
			break;
		case Del:
			del(&con);
			break;
		case Search:
			search(&con);
			break;
		case Modify:
			modify(&con);
			break;
		case Show:
			show(&con);
			break;
		case Sort:
			sort(&con);
			break;
		case Exit:
			printf("退出通讯录\n");
			break;
		}

	} while (input);

	ret_memory(&con);
	return 0;
}

