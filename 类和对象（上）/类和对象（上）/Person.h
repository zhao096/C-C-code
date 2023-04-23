#pragma once
#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

using namespace std;

class Person
{
public:

	void ShowInfo();//展示信息

private:
	char name[10];
	char sex[5];
	int age;
};