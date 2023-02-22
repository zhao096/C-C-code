 #define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define InitPeo 4

typedef int SLDateType;

typedef struct SeqList
{
	SLDateType* a;
	int size;//数组中的元素类型个数
	int capacity;
}SeqList;

// 对数据的管理:增删查改 
//初始化顺序表
void SeqListInit(SeqList* ps);
//将表返回
void SeqListDestroy(SeqList* ps);
//打印表里的内容
void SeqListPrint(SeqList* ps);
//在顺序表 尾插 入一个数据
void SeqListPushBack(SeqList* ps, SLDateType x);
//在顺序表 尾删 除数据
void SeqListPopBack(SeqList* ps);
//在线性表 头插 入数据
void SeqListPushFront(SeqList* ps, SLDateType x);
//在线性表 头删 除数据
 void SeqListPopFront(SeqList* ps);
//// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x);
//// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, int pos, SLDateType x);
//// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, int pos);