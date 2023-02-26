 #define _CRT_SECURE_NO_WARNINGS 1

#include"STist.h"

SListNode* BuySListNode(SLTDateType x) {
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		perror("malloc failed");
		return NULL;
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SListPrint(SListNode* phead)
{
	SListNode* tail = phead;

	while (tail != NULL)
	{
		printf("%d->", tail->data);
		tail = tail->next;
	}
	printf("NULL\n");
}

void SListPushBack(SListNode** pphead, SLTDateType x) {
	SListNode* newnode = BuySListNode(x);
	SListNode* tail = *pphead;
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else {	
		while (tail->next) {
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListPushFront(SListNode** pphead, SLTDateType x){
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPopBack(SListNode** pphead) {
	assert(pphead);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SListNode* tail = *pphead;

		while (tail->next->next) {
			tail = tail->next;
		}

		free(tail->next);
		tail->next = NULL;

	}
}

void SListPoqpFront(SListNode** pphead) {
	assert(pphead);

	if ((*pphead)->next == NULL) {
		*pphead = NULL;
	}
	else {
		SListNode* frist = *pphead;

		//frist = frist->next;
		*pphead = frist->next;
		free(frist);
		frist = NULL;
	}
}

SListNode* SListFind(SListNode* phead, SLTDateType x) {
	assert(phead);
	SListNode* find = phead;
	while (find)
	{
		if (find->data == x)
		{
			return find;
		}
		find = find->next;
	}
	printf("’“≤ªµΩ\n");
	return NULL;
}

