#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

	typedef int datetype;

	typedef struct stack
	{
		datetype* date;
		int size;
		int capacity;
	}stack;

void StackInit(stack* ps);
void StackDestroy(stack* ps);

void StackPush(stack* ,datetype x);
void StackPop(stack* ps);
//获取栈顶的数据
datetype StackTop(stack* ps);
//获取栈上的个数
int StackSize(stack* ps);

bool StackEmpty(stack* ps);






