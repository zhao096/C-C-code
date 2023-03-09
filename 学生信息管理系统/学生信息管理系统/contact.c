 #define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"


void AddCapacity(Info_System* con)
{
	assert(con);
	PeoInfo* ptr = (PeoInfo*)realloc(con->Contact,sizeof(PeoInfo) * (AddCap+ con->capacity));
	if (ptr == NULL)
	{
		perror("realloc");

		return ;
	}
	con->Contact = ptr;
	con->capacity += AddCap;

	ptr = NULL;
	printf("增容成功\n");
}


////初始化
//void InitCon(Info_System* con)
//{
//	assert(con);
//	con->sz = 0;
//	memset(con->Contact, 'a', sizeof(Info_System));//利用memset将一块连续的空间初始化成0最后要初始化多少个字节
//}

void InitCon(Info_System* con)
{
	assert(con);
	con->sz = 0;
	con->capacity = InitPeo;
	PeoInfo* ptr = (PeoInfo*)malloc(sizeof(PeoInfo) *InitPeo);
	if (ptr == NULL)
	{
		perror("malloc");
		return ;
	}
	con->Contact = ptr;
	ptr = NULL;
	memset(con->Contact, 0, sizeof(PeoInfo)*InitPeo);
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
	if (con->sz == con->capacity)
	{
		AddCapacity(con);
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
	assert(con);
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
			printf("修改：\n");
			printf("依次输入学号 名字 班级 性别 宿舍 计算机成绩\n并且以空格/回车分隔\n");
			scanf("%d %s %s %s %s %d", &con->Contact[ret].ID,
				con->Contact[ret].Name,
				con->Contact[ret].Class,
				con->Contact[ret].Sex,
				con->Contact[ret].Room,
				&con->Contact[ret].Score
			);

			printf("修改完成\n");
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
			printf("修改：>\n");
			printf("依次输入学号 名字 班级 性别 宿舍 计算机成绩\n并且以空格/回车分隔\n");
			scanf("%d %s %s %s %s %d", &con->Contact[ret].ID,
				con->Contact[ret].Name,
				con->Contact[ret].Class,
				con->Contact[ret].Sex,
				con->Contact[ret].Room,
				&con->Contact[ret].Score
			);
			printf("修改完成\n");

		}
	}

	else
	{
		printf("选择错误\n");
	}
}

int Sort_Name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->Name, ((PeoInfo*)e2)->Name);
	//注意强转要写成 PeoInfo* 结构体类型
	//返回大于0的数才交换，即是升序形式
}

int Sort_age(const void* e1, const void* e2)
{
	return ((PeoInfo*)e1)->ID  - ((PeoInfo*)e2)->ID;
}
void Sort_Stu_message(Info_System* con)
{
	assert(con);
	int input = 0;
	printf("1.以名字排序\n2.以学号排序\n");
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		//贼雕
		//ASCII升序
		qsort(con->Contact, con->sz, sizeof(con->Contact[0]), Sort_Name);//头文件stdlib，比较函数int compare（const void *elem1, const void *elem2）
		//此处con->Contact 直接找到了数组名传进去，所以qsort内所接受到的结构体时PeoInfo类型的
		//类似buble_qsort(student, 3, sizeof(Stu), stru_name); 
		
		//typedef struct Stu {
		//	char name[20];
		//	int age;
		//} Stu;
		//int stru_name(const void* e1, const void* e2){
		//	return strcmp(((Stu*)e1)->name, ((Stu*)e2)->name);//强制类型转换的优先级小于->，对此我们还应该加上（）来先将void * 变成 Stu*
		//}
		//void str(){
		//	Stu student[3] = { {"zhansang",18},{"lisi",55},{"wangwu",22} };
		//	buble_qsort(student, 3, sizeof(Stu), stru_name);
		//}
		printf("排序成功\n");

		break;
	case 2:
		//升序
		qsort(con->Contact, con->sz, sizeof(con->Contact[0]), Sort_age);
		printf("排序成功\n");
		break;
	default:
		printf("输入错误\n");
		break;
	}
}

void Refresh_Stu_message(Info_System* con)
{
	InitCon(con);
	printf("刷新成功\n");
}



void DestroyContact(Info_System* con)
{
	free(con->Contact);
	con->Contact = NULL;

	con->capacity = 0;
	con->sz = 0;
	con = NULL;

}

