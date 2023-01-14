#pragma once
#include<assert.h>
#include<stdio.h>
#include<string.h>

#define Peo_MAX 100
#define NAME_MAX 10 
#define SEX_MAX 5
#define ADDR_MAX 30
#define TELE_MAX 12

struct PeoInfo 
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char addr[ADDR_MAX];
	char tele[TELE_MAX];
		
};

typedef struct contact
{
	struct PeoInfo date[Peo_MAX];//每个联系人的消息
	int sz;//人数
}contact;


//初始化通讯录
void Init_contact(contact *p);

//增加联系人
void add(contact* p);

//删除联系人
void del(contact* p);

//显示所有联系人
void show(contact* p);

//查找联系人
void search(contact* p);

//修改联系人
void modify(contact* p);