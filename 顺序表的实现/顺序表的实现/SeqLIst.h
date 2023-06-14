#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


#define INIT_CAPACITY 4
//sequence

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;//用指针的形式来代替数组这样开辟空间更好理解（数组的本质是指针）
	int size;//元素个数
	int capacity;//容量
}SeqList;

void InitSeqList(SeqList * obj);
void DestorySeqList(SeqList* obj);

void SeqListBackPush(SeqList* obj,SLDataType x );

void SeqListBackPop(SeqList* obj);

void SeqListPirnt(SeqList* obj);

void SeqListFrontPush(SeqList* obj, SLDataType x);

void SeqListFrontPop(SeqList* obj);

void SeqListInsert(SeqList* obj, int pos, SLDataType x);

void SeqListErase(SeqList* obj, int pos);