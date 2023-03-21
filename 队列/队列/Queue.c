 #define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"



void QueueInit(Queue* q)
{
	assert(q);
	q->_front = NULL;
	q->_rear = NULL;
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
		q->_rear = NULL;
	}
	free(q->_front);
	q->_front = tmp;
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
}




