#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


#define INIT_CAPACITY 4
//sequence

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
}SeqList;

void InitSeqList(SeqList * obj);
void DestorySeqList(SeqList* obj);

void SeqListPush(SeqList* obj,SLDataType x );

void SeqListPop(SeqList* obj);

void SeqListPirnt(SeqList* obj);

void SeqListFrontPush(SeqList* obj, SLDataType x);

void SeqListFrontPop(SeqList* obj);

void SeqListInsert(SeqList* obj, int pos, SLDataType x);

void SeqListErase(SeqList* obj, int pos);