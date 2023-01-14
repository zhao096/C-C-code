 #define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void menu()
{
	printf("***********************************\n");
	printf("*********  1.add    2.del    ******\n");
	printf("*********  3.search 4.modify ******\n");
	printf("*********  5.show   0.exit   ******\n");
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
		case 1:
			add(&con);
			break;
		case 2:
			del(&con);
			break;
		case 3:
			search(&con);
			break;
		case 4:
			modify(&con);
			break;
		case 5:
			show(&con);
			break;
		case 0:
			printf("退出通讯录\n");
			break;
		}

	} while (input);


	return 0;
}

