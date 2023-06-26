 #define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_rear = NULL;
	q->_size = 0;
}

void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* pf = (QNode*)malloc(sizeof(QNode));//先申请一个链表节点空间
	if (pf == NULL)//判断是否申请成功
	{
		perror("malloc");
		return;
	}
	//判断第一个节点是否存在（队列中没有数据的时候rear是NULL）
	if (q->_rear)//若不为NULL
	{
		q->_rear->_pNext = pf;//进行尾插，也就是在最后一个节点后面插入新生成的节点pf
		q->_rear = pf;//再把尾部修改一下
	}
	else//当队列中没有数据的时候
	{
		//此时把头和尾指针都指向pf这样就创建好链表的开始了
		q->_rear = pf;
		q->_front = pf;
	}
	q->_rear->_data = data;//将rear指向后，将尾部的数据填充为所给的data
	q->_rear->_pNext = NULL;//再将尾部指针的下一个位置置成NULL
	q->_size++;//元素个数++
}

bool QueueEmpty(Queue* q)
{
	assert(q);
	return q->_size == 0;//查看size是否为0，若为则返回真（1）反之则为假（0）
}
void QueuePop(Queue* q)
{
	assert(q);//判空
	assert(!QueueEmpty(q));//查看队列中是否有数据
	QNode* tmp = q->_front->_pNext;//用tmp记录一下第二个位置的数据的地址
	if (q->_front == q->_rear)//判断一下是否为最后一个元素
	{
		free(q->_front);//释放头指向的空间
		//若是则直接吧rear和front都置为NULL
		q->_front = q->_rear = NULL;
	}
	else//反之当不止只有一个数据时
	{
		free(q->_front);//同样是否头位置的空间

		q->_front = tmp;//改变一下头位置然其指向第二个数据的位置也就是新头
	}
	q->_size--;//元素减少一位
}

QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));//判断队列是否有数据
	return q->_front->_data;//返回头位置的数据
}

QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));//判断队列是否有数据
	return q->_rear->_data;//返回尾位置的数据
}

int QueueSize(Queue* q)
{
	return q->_size;//返回size即可
}

void QueueDestroy(Queue* q)
{
	assert(q);
	//从前往后的进行各链表节点释放
	while (q->_front)//判断头是否为空
	{
		QNode* next = q->_front->_pNext;//用next记录下一个位置的地址(防止找不到)
		free(q->_front);//释放当前位置
		q->_front = next;//让front指向下一个位置
	}
	q->_front = q->_rear = NULL;//链表数据全部释放完后把front/rear也置为NULL
	q->_size = 0;//把size置为0
}




