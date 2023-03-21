#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


typedef int QDataType;

typedef struct QListNode
{
	struct QListNode* _pNext;//指向下一个
	QDataType _data;//数据
}QNode;

typedef struct Queue
{
	QNode * _front;//头
	QNode* _rear;//尾
	int _size;
}Queue;


void QueueInit(Queue* q);
// 队尾入队列
void QueuePush(Queue* q, QDataType data);
// 队头出队列
void QueuePop(Queue* q);
// 获取队列头部元素
QDataType QueueFront(Queue* q);
// 获取队列队尾元素
QDataType QueueBack(Queue* q);
// 获取队列中有效元素个数
int QueueSize(Queue* q);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
bool QueueEmpty(Queue* q);
// 销毁队列
void QueueDestroy(Queue* q);