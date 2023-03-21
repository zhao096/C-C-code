 #define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"
int main()
{
	Queue q;

	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	
	while (!QueueEmpty(&q))
	{
		QDataType ret = QueueBack(&q);
		printf("%d ",ret);
		QueuePop(&q);
	}

	printf("\n%d\n", q._size);

	QueueDestroy(&q);

	return 0;
}