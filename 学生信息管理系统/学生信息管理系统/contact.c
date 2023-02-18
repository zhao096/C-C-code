 #define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

//初始化
void InitCon(Info_System* con)
{
	assert(con);
	con->sz = 0;
	memset(con->Contact, 0, sizeof(Info_System));//利用memset将一块连续的空间初始化成0最后要初始化多少个字节
}

int FindById(int Id, const Info_System* con)
{
	int t = con->sz;//不要改变sz，用t来代替需要查找的人
	while (t--)
	{
		if (Id == con->Contact[t].ID)
		{
			return t;
		}
	}
	printf("找不到此人\n");
	return -1 ;//返回-1是因为区别于返回0（返回0表示查找的人的下标为0）
}
int FindByName(char * name,const Info_System* con)
{
	int t = con->sz;//不要改变sz，用t来代替需要查找的人
	while (t--)
	{
		if (strcmp(name, con->Contact[t].Name) == 0)//--ret 是因为ret表示的是总人数，而总人数-1才能找到最后一个人
		{
			return t;
		}

	}
	printf("找不到此人\n");

	return -1;//返回-1是因为区别于返回0（返回0表示查找的人的下标为0）
}

//增加
void Add_Stu_message(Info_System* con)
{
	assert(con);
	if (con->sz == PeoMax)
	{
		printf("信息已满,请删除或刷新后再试\n");
		return;
	}
	printf("依次输入学号 名字 班级 性别 宿舍 计算机成绩\n并且以空格/回车分隔\n");
	//printf("依次输入%-10s %-20s %-5s %-20s %-20s %-10s\n", "学号", "名字", "班级", "性别", "宿舍", "计算机成绩");
	//对于下面的输入操作我们需要引用并且存进结构体中 对于数组来说不需要加上& 
	//因为其数组名表示其地址 而对于整形就需要&了
	//先从con这是Info_System结构体的变量所以直接->访问再访问里面的成员Contact
	//而又是其又是PeoInfo结构体的数组变量所以
	//就有可以先访问一个数组空间再用.操作符来找到其内容，
	//这里不用-> 是因为前面con->Contact[con->sz] 已经表示成Contact[PeoMax]变量了不需要在*解引用了
	scanf("%d %s %s %s %s %d", &con->Contact[con->sz].ID,
		con->Contact[con->sz].Name,
		con->Contact[con->sz].Class,
		con->Contact[con->sz].Sex,
		con->Contact[con->sz].Room,
		&con->Contact[con->sz].Score
	);
	con->sz += 1;
	//con->sz++;
	printf("添加完成\n");
}


void Show_Stu_message(const Info_System* con)
{
	assert(con);

	printf("%-10s %-20s %-20s %-5s %-20s %-10s\n", "学号", "名字", "班级", "性别", "宿舍", "计算机成绩");
	for (int i = 0; i < con->sz;i++)//解引用操作符的优先级都很（最）高
	{
		printf("%-10d %-20s %-20s %-5s %-20s %-10d\n", con->Contact[i].ID,
			con->Contact[i].Name,
			con->Contact[i].Class,
			con->Contact[i].Sex,
			con->Contact[i].Room,
			con->Contact[i].Score);
	}

}


void Del_Stu_message(Info_System* con)
{
	assert(con);
	if (con->sz == 0)
	{
		printf("没有学生信息\n");
		return;
	}
	int input = 0;
	printf("输入学号进行删除；>");
	scanf("%d", &input);
	int ret = FindById(input,con);
	if (ret != -1)
	{
		for (ret; ret < con-> sz - 1; ret++) //sz -1 也要转化成下标
		{
			con->Contact[ret] = con->Contact[ret+1]; //注意返回的就是所对应的下标
		}
		con->sz--;
		printf("删除成功\n");
	}
	//if (ret!=-1)
	//{
	//	memmove(con->Contact + ret, con->Contact + ret + 1, (con->sz)*sizeof(PeoInfo) - (ret) * sizeof(PeoInfo));
	//	con->sz--;
	//	printf("删除成功\n");
	//}

}


void Search_Stu_message(const Info_System* con)
{
	assert(con);
	int i = 0;
	printf("1.Id\n2.Name\n选择查找方法：>");
	scanf("%d", &i);
	if (i == 1)
	{
		int input = 0;

		printf("输入学号进行查找:>");
		scanf("%d", &input);
		int ret = FindById(input, con);
		if (ret != -1)
		{
			printf("%-10s %-20s %-20s %-5s %-20s %-10s\n", "学号", "名字", "班级", "性别", "宿舍", "计算机成绩");

			printf("%-10d %-20s %-20s %-5s %-20s %-10d\n", con->Contact[ret].ID,
				con->Contact[ret].Name,
				con->Contact[ret].Class,
				con->Contact[ret].Sex,
				con->Contact[ret].Room,
				con->Contact[ret].Score);
		}
	}
	else if (i == 2)
	{
		char name[20] = { 0 };
		printf("输入姓名进行查找:>");
		scanf("%s",name);
		int ret = FindByName(name, con);
		
		if (ret != -1)
		{
			printf("%-10s %-20s %-20s %-5s %-20s %-10s\n", "学号", "名字", "班级", "性别", "宿舍", "计算机成绩");

			printf("%-10d %-20s %-20s %-5s %-20s %-10d\n", con->Contact[ret].ID,
				con->Contact[ret].Name,
				con->Contact[ret].Class,
				con->Contact[ret].Sex,
				con->Contact[ret].Room,
				con->Contact[ret].Score);
		}
	}

	else
	{
		printf("选择错误\n");
	}
	

}


void Modeifyh_Stu_message(Info_System* con)
{

	int i = 0;
	printf("1.Id\n2.Name\n选择查找方法：>");
	scanf("%d", &i);
	if (i == 1)
	{
		int input = 0;

		printf("输入要修改的学生信息的学号:>");
		scanf("%d", &input);
		int ret = FindById(input, con);
		if (ret != -1)
		{
			printf("原信息:\n%-10s %-20s %-20s %-5s %-20s %-10s\n", "学号", "名字", "班级", "性别", "宿舍", "计算机成绩");

			printf("%-10d %-20s %-20s %-5s %-20s %-10d\n", con->Contact[ret].ID,
				con->Contact[ret].Name,
				con->Contact[ret].Class,
				con->Contact[ret].Sex,
				con->Contact[ret].Room,
				con->Contact[ret].Score);
			

			printf("修改：>\n");
			printf("依次输入学号 名字 班级 性别 宿舍 计算机成绩\n并且以空格/回车分隔\n");
			scanf("%d %s %s %s %s %d", &con->Contact[ret].ID,
				con->Contact[ret].Name,
				con->Contact[ret].Class,
				con->Contact[ret].Sex,
				con->Contact[ret].Room,
				&con->Contact[ret].Score
			);


		}
	}
	else if (i == 2)
	{
		char name[20] = { 0 };
		printf("输入要修改的学生信息的姓名:>");
		scanf("%s", name);
		int ret = FindByName(name, con);

		if (ret != -1)
		{
			printf("原信息:\n%-10s %-20s %-20s %-5s %-20s %-10s\n", "学号", "名字", "班级", "性别", "宿舍", "计算机成绩");

			printf("%-10d %-20s %-20s %-5s %-20s %-10d\n", con->Contact[ret].ID,
				con->Contact[ret].Name,
				con->Contact[ret].Class,
				con->Contact[ret].Sex,
				con->Contact[ret].Room,
				con->Contact[ret].Score);


			printf("修改：>\n");
			printf("依次输入学号 名字 班级 性别 宿舍 计算机成绩\n并且以空格/回车分隔\n");
			scanf("%d %s %s %s %s %d", &con->Contact[ret].ID,
				con->Contact[ret].Name,
				con->Contact[ret].Class,
				con->Contact[ret].Sex,
				con->Contact[ret].Room,
				&con->Contact[ret].Score
			);
		}
	}

	else
	{
		printf("选择错误\n");
	}
}
