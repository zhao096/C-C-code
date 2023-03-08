#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>


#define Name_Max 20
#define Sex_Max 5
#define Class_Max 20
#define Room_Max 20

#define PeoMax 100


#define InitPeo 3
#define AddCap 2

typedef struct PeoInfo
{
	int ID;// 学号
	char Name[Name_Max];// 姓名
	char Sex[Sex_Max];// 性别
	char Class[Class_Max];// 班级
	char Room[Room_Max];// 宿舍号
	int Score;// 成绩

}PeoInfo;
//
//typedef struct management_System
//{
//
//	PeoInfo Contact[PeoMax];//存放人的信息
//	int sz;//已近存放了多少个人
//}Info_System;

typedef struct management_System
{

	PeoInfo* Contact;//存放人的信息
	int sz;//已近存放了多少个人
	int capacity;//容量大小

}Info_System;


void InitCon(Info_System *con);

void Add_Stu_message(Info_System* con);

void Show_Stu_message(const Info_System* con);

void Del_Stu_message (Info_System* con);

void Search_Stu_message(const Info_System* con);

void Modeifyh_Stu_message(Info_System* con);

void Sort_Stu_message(Info_System* con);

void Refresh_Stu_message(Info_System* con);

