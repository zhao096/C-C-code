#pragma once
// slist.h
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDateType;

typedef struct SListNode
{
	SLDateType data;//SLDateType typedef定义类型和顺序表一样都是为了更加方便去改变结构中的存的类型
	struct SListNode* next;//定义一个结构体类型的指针，因为到时候next指向一个结构体类型
}SListNode;//用typedef将struct SListNode改变成SListNode这样更方便于我们后面使用（可以不用加上struct，直接用代替的就好）

// 动态申请一个节点
SListNode* BuySListNode(SLDateType x);
// 单链表打印
void SListPrint(SListNode* plist);
// 单链表尾插
void SListPushBack(SListNode** pplist, SLDateType x);
// 单链表的头插
void SListPushFront(SListNode** pplist, SLDateType x);
// 单链表的尾删
void SListPopBack(SListNode** pplist);
// 单链表头删
void SListPopFront(SListNode** pplist);
// 单链表查找
SListNode* SListFind(SListNode* plist, SLDateType x);
// 单链表在pos位置之后、插入x
// 分析思考为什么不在pos位置之前插入？
//当给定pos位置后就没有办法在将前面的内容进行改变
void SListInsertAfter(SListNode* pos, SLDateType x);
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos);
// 单链表的销毁
void SListDestroy(SListNode* plist);	
