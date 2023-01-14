 #define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"
//找人
int check_Peo(contact* p,char * name)
{
	assert(p && name);
	for (int i = 0; i < p->sz; i++)
	{
		if ((strcmp(p->date[i].name, name)) == 0)
		{
			return i;
		}

	}
	return -1;
}

//初始化通讯录
void Init_contact(contact* p)
{
	assert(p);
	p->sz = 0;
	memset(p->date, 0, sizeof(p->date));
}

//增加联系人
void add(contact * p)
{
	assert(p);
	if (p->sz > Peo_MAX)
	{
		printf("通讯录已满\n");
		return;
	}
	printf("输入联系人名:>");
	scanf("%s",p->date[p->sz].name);
	printf("输入联系人的年龄:>");
	scanf("%d",&( p->date[p->sz].age));
	printf("输入联系人性别:>");
	scanf("%s", p->date[p->sz].sex);
	printf("输入联系人地址:>");
	scanf("%s", p->date[p->sz].addr);
	printf("输入联系人电话:>");
	scanf("%s", p->date[p->sz].tele);		
	
	p->sz++;
}


//删除联系人
void del(contact* p)
{
	assert(p);
	char name[NAME_MAX] = { 0 };
	printf("请输入你要删除的人:>");
	scanf("%s", name);
	int ret = check_Peo(p,name);
	if (ret == -1)
	{
		printf("查无此人\n");
		return;
	}
	for (int i = ret; i < p->sz - 1; i++)
	{
		p->date[i] = p->date[i + 1];
	}
	p->sz--;
	printf("删除成功\n");
}



//展示联系人
void show(contact* p)
{
	assert(p);
	if (p->sz == 0)
	{
		printf("无数据\n");
		return;
	}
	printf("%-10s %-5s %-5s %-30s %-12s\n", "名字", "年龄", "性别", "地址", "电话");
	for (int i = 0; i < (p->sz); i++)
	{
		printf("%-10s %-5d %-5s %-30s %-12s\n", p->date[i].name,
												p->date[i].age,
												p->date[i].sex,
												p->date[i].addr,
												p->date[i].tele)
												;
	}
}




//查找联系人
void search(contact* p)
{
	assert(p);
	char name[NAME_MAX] = { 0 };
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	int ret = check_Peo(p,name);
	if (ret == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("%-10s %-5s %-5s %-30s %-12s\n", "名字", "年龄", "性别", "地址", "电话");
		printf("%-10s %-5d %-5s %-30s %-12s\n", p->date[ret].name,
			p->date[ret].age,
			p->date[ret].sex,
			p->date[ret].addr,
			p->date[ret].tele)
			;
	}
	
}

//修改联系人
void modify(contact* p)
{
	assert(p);
	char name[NAME_MAX] = { 0 };
	printf("请输入要修改的人的名字:>");
	scanf("%s", name);
	int ret = check_Peo(p, name);
	if (ret == -1)
	{
		printf("查无此人\n");
		return;
	}

	printf("此人信息:\n%-10s %-5s %-5s %-30s %-12s\n", "名字", "年龄", "性别", "地址", "电话");
	printf("%-10s %-5d %-5s %-30s %-12s\n", p->date[ret].name, p->date[ret].age, p->date[ret].sex, p->date[ret].addr, p->date[ret].tele);
		
		printf("请输入名字:>");
		scanf("%s", p->date[ret].name);
		printf("请输入年龄:>");
		scanf("%d", &(p->date[ret].age));
		printf("请输入性别:>");
		scanf("%s", p->date[ret].sex);
		printf("请输入地址:>");
		scanf("%s", p->date[ret].addr);
		printf("请输入电话:>");
		scanf("%s", p->date[ret].tele);

	

}