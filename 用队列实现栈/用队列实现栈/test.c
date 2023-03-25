#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int QDataType;

typedef struct QListNode
{
	struct QListNode* _pNext;//指向下一个
	QDataType _data;//数据
}QNode;

typedef struct Queue
{
	QNode* _front;//头
	QNode* _rear;//尾
	int _size;
}Queue;

void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_rear = NULL;

	q->_size = 0;
}

void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* pf = (QNode*)malloc(sizeof(QNode));
	if (pf == NULL)
	{
		perror("malloc");
		return;
	}
	if (q->_rear)
	{
		q->_rear->_pNext = pf;
		q->_rear = pf;
	}
	else
	{
		q->_rear = pf;
		q->_front = pf;
	}
	q->_rear->_data = data;
	q->_rear->_pNext = NULL;
	q->_size++;
}

bool QueueEmpty(Queue* q)
{
	assert(q);
	return q->_size == 0;
}
void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	QNode* tmp = q->_front->_pNext;
	if (q->_front == q->_rear)
	{
		free(q->_front);

		q->_front = q->_rear = NULL;
	}
	else
	{
		free(q->_front);

		q->_front = tmp;
	}
	q->_size--;
}

QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->_front->_data;
}

QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->_rear->_data;
}

int QueueSize(Queue* q)
{
	return q->_size;
}

void QueueDestroy(Queue* q)
{
	assert(q);
	//assert(!QueueEmpty(q));
	while (q->_front)
	{
		QNode* next = q->_front->_pNext;
		free(q->_front);
		q->_front = next;
	}
	q->_front = q->_rear = NULL;
	q->_size = 0;
}

typedef struct {
	Queue q1;
	Queue q2;
} MyStack;


MyStack* myStackCreate() {
	MyStack* sk = (MyStack*)malloc(sizeof(int) * 100);
	if (sk == NULL)
	{
		perror("malloc");
		return NULL;
	}
	QueueInit(&sk->q1);
	QueueInit(&sk->q2);
	return sk;
}

void myStackPush(MyStack* obj, int x) {
	assert(obj);
	QueuePush(&obj->q1, x);
}

int myStackPop(MyStack* obj) {
	assert(obj);
	Queue* empty = &obj->q2;
	Queue* nonempty = &obj->q1;
	int ret = 0;
	if (QueueEmpty(&obj->q1))
	{
		empty = &obj->q1;
		nonempty = &obj->q2;
	}
	while (QueueSize(nonempty) > 1)
	{
		QueuePush(empty, QueueFront(nonempty));
		QueuePop(nonempty);
	}
	ret = QueueFront(nonempty);
	QueuePop(nonempty);
	return ret;


	//将数据转移到空的位置


}

int myStackTop(MyStack* obj) {
	return QueueEmpty(&obj->q1) ? QueueBack(&obj->q2) : QueueBack(&obj->q1);
}

bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);

}

void myStackFree(MyStack* obj) {
	assert(obj);
	QueueDestroy(&obj->q2);
	QueueDestroy(&obj->q1);

	free(obj);
	obj = NULL;
}

// int main()
// {
// 	MyStack* obj = myStackCreate();
// 	myStackPush(obj, 1);

// 	int param_2 = myStackPop(obj);

// 	int param_3 = myStackTop(obj);

// 	bool param_4 = myStackEmpty(obj);

// 	myStackFree(obj);
// 	return 0;
// }

