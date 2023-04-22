#pragma once
#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

using namespace std;

class Person
{
public:
	void PersonInit()
	{
		scanf("%s", name);
		scanf("%s", sex);
		scanf("%d", &age);
	}
	void ShowInfo(char name[]);//展示信息

private:
	char name[10];
	char sex[5];
	int age;
};