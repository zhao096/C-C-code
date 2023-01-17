#pragma once
#include<assert.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define Peo_MAX 1000
#define NAME_MAX 10 
#define SEX_MAX 5
#define ADDR_MAX 30
#define TELE_MAX 12


#define Inti_Peo_space 3
#define Add_space 2






enum program
{
	Exit,//0
	Add,//1    递增的
	Del,
	Search,
	Modify,
	Show,
	Sort
};


typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char addr[ADDR_MAX];
	char tele[TELE_MAX];


}PeoInfo;


typedef struct contact
{
	PeoInfo* data;//联系人的数据的空间
	int sz;//人数
	int capacity;//当前结构体的最大容量
}contact;




//初始化通讯录
void Init_contact(contact* p);


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


//通过姓名给他排序
void sort(contact* p);


//归还所借的动态内存，否则会导致内存泄漏、
void ret_memory(contact* p);

//将数据存储在文件中以二进制的形式
void SaveContact(contact* p);
