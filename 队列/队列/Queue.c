 #define _CRT_SECURE_NO_WARNINGS 1

void QueuePop(Queue * pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	
	if (pq->head->next == NULL)
	{
		free(pq->head);

		pq->head = pq->tail = NULL;
	}
	else
	{
		Queue* cur = pq->head->next;
		free(pq->head);
		pq->head = cur;
	}
	pq->size--;
	return;

}