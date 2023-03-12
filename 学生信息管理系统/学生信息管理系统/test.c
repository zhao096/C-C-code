 #define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

enum function
{
	Exit ,
	Add,
	Del,
	Search,
	Modeify,
	Show,
	Sort,
	Refresh
};


void menu()
{
	printf("********************************\n");
	printf("********************************\n");
	printf("*****    1. Add  2.Del     *****\n");
	printf("********************************\n");
	printf("*****  3.Search  4.Modeify *****\n");
	printf("********************************\n");
	printf("*****   5.Show   6.Sort    *****\n");
	printf("********************************\n");
	printf("*****  7.refresh    0.exit *****\n");
	printf("********************************\n");
	printf("********************************\n");

	//1）添加学生信息
	//2）删除学生信息
	//3）查询学生信息
	//4）修改学生信息
	//5）展示所有学生信息
	//6）重新排序学生信息
	//7）刷新学生信息
	//7）自动保存学生信息
	//8）输出当前学生信息
}

int main()
{
	int input = 0;

	Info_System con ;
//初始化
	InitCon(&con);
	//初始化方法二：Info_System con = {0};直接将全部置成0
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);

		switch(input)
		{
		case Add:
			Add_Stu_message(&con);
			break;
		case Del:
			Del_Stu_message(&con);
			break;
		case Search:
			Search_Stu_message(&con);
			break;
		case Modeify:
			Modeifyh_Stu_message(&con);
			break;
		case Show:
			Show_Stu_message(&con);
			break;
		case Sort:
			Sort_Stu_message(&con);
			break;
		case Refresh:
			Refresh_Stu_message(&con);
			break;
		case Exit:
			//保存文件
			SaveContact(&con);
			DestroyContact(&con);
			printf("退出\n");

			break;
		default:
			printf("选择错误，重新选择：\n");
			break;
		}


	} while (input);



	return 0;
}