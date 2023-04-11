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
	assert(pphead);
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
	assert(pphead);
	SListNode* newnode = BuySListNode(x);

	newnode->next = *pphead;//将新开辟的空间的地址指向链表的第一个元素的地址
	*pphead = newnode;//改变链表的起始元素
}

void SListPopBack(SListNode** pphead) {
	assert(pphead);
	assert(*pphead);
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
	assert(*pphead);
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
	SListNode* find = phead;
	while (find)
	{
		if (find->data == x)
		{
			return find;
		}
		find = find->next;
	}
	printf("找不到\n");
	return NULL;
}

void SListInsertAfter(SListNode* pos, SLTDateType x) {
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListEraseAfter(SListNode* pos) {
	assert(pos);
	if (pos->next == NULL)
	{
		return;
	}
	else {
		SListNode* del = pos->next;
		pos->next = pos->next->next;
		free(del);
		del = NULL;
	}
}

void SListDestroy(SListNode* plist) {
	assert(plist);

	SListNode* prev, * tail;
	prev = plist;
	tail = plist->next;
	while (prev)
	{	
		free(prev);
		prev = tail;
		if(tail != NULL)
		tail = tail->next;
	}
	plist = NULL;
}

