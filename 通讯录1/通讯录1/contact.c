 #define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"
//找人
int check_Peo(contact* p,char * name)
{
	assert(p && name);
	for (int i = 0; i < p->sz; i++)
	{
		if ((strcmp(p->data[i].name, name)) == 0)
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
	memset(p->data, 0, sizeof(p->data));
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
	scanf("%s",p->data[p->sz].name);
	printf("输入联系人的年龄:>");
	scanf("%d",&( p->data[p->sz].age));
	printf("输入联系人性别:>");
	scanf("%s", p->data[p->sz].sex);
	printf("输入联系人地址:>");
	scanf("%s", p->data[p->sz].addr);
	printf("输入联系人电话:>");
	scanf("%s", p->data[p->sz].tele);		
	
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
		p->data[i] = p->data[i + 1];
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
		printf("%-10s %-5d %-5s %-30s %-12s\n", p->data[i].name,
												p->data[i].age,
												p->data[i].sex,
												p->data[i].addr,
												p->data[i].tele)
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
		printf("%-10s %-5d %-5s %-30s %-12s\n", p->data[ret].name,
			p->data[ret].age,
			p->data[ret].sex,
			p->data[ret].addr,
			p->data[ret].tele)
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
	printf("%-10s %-5d %-5s %-30s %-12s\n", p->data[ret].name, p->data[ret].age, p->data[ret].sex, p->data[ret].addr, p->data[ret].tele);
		
		printf("请输入名字:>");
		scanf("%s", p->data[ret].name);
		printf("请输入年龄:>");
		scanf("%d", &(p->data[ret].age));
		printf("请输入性别:>");
		scanf("%s", p->data[ret].sex);
		printf("请输入地址:>");
		scanf("%s", p->data[ret].addr);
		printf("请输入电话:>");
		scanf("%s", p->data[ret].tele);

	

}

void sort(contact* p)
{
	int i = 0;
	for (i = 0; i < p->sz - 1; i++)
	{
		int k = 0;
		for(int j = 0 ; j < p->sz - i -1 ;j++)
		if (strcmp(p->data[j].name, p->data[j + 1].name) > 0)
		{
			p->data[p->sz + 1] = p->data[j];
			p->data[j] = p->data[j + 1];
			p->data[j + 1] = p->data[p->sz + 1];
			k = 1;
		}
		if (k == 0)
		{
			break;
		}
	}
	printf("排序成功\n");
}


