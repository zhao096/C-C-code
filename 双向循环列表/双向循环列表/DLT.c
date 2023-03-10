 #define _CRT_SECURE_NO_WARNINGS 1

#include"DLT.h"

ListNode* BuyMemory(LTDataType  x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node== NULL)
	{
		perror("malloc::BuyMemory");
		//return NULL;
		exit(-1);//直接退出程序
	}
	node->data = x;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

ListNode* ListCreate()
{
	ListNode* head = BuyMemory(-1);
	if (head != NULL)
	{
		head->next = head;
		head->prev = head;
	}
	return head;
}

void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListNode* newnode = BuyMemory(x);
	ListNode* tail = pHead->prev;

	if (newnode != NULL)
	{
		tail->next = newnode;
		newnode->prev = tail;

		newnode->next = pHead;
		pHead->prev = newnode;
	}

}


void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	printf("《=》head《=》");

	while (cur != pHead)
	{
		printf("%d《=》", cur->data);
		cur = cur->next;
	}
	printf("\n");
	
}

bool If_DTLEmpty(ListNode* pHead)
{
	if (pHead->next == pHead)
	{
		return true;//true
	}
	else
	{
		return false;
	}

}


void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	assert(!If_DTLEmpty(pHead));//判断是否为空
	ListNode* new_tail = pHead->prev->prev;
	ListNode* old_tail = pHead->prev;

	new_tail->next = pHead;
	pHead->prev = new_tail;

	free(old_tail);
	old_tail = NULL;

}


void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newnode = BuyMemory(x);
	ListNode* frist = pHead->next;


	newnode->next = frist;
	frist->prev = newnode;

	newnode->prev = pHead;
	pHead->next = newnode;

	//newnode->next = phead->next;
	//phead->next->prev = newnode;

	//phead->next = newnode;
	//newnode->prev = phead;

}



void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(!If_DTLEmpty(pHead));//判断是否为空


	ListNode* frist = pHead->next->next;
	pHead->next = frist;
	frist->prev = pHead;

	//ListNode* front = pHead->next;
	//free(front);
	//front = NULL;
}

ListNode* ListFind(ListNode* pHead, LTDataType x)
{

	assert(pHead);
	if (If_DTLEmpty(pHead))
	{
		printf("无数据\n");
		return NULL;
	}

	ListNode* tail = pHead;
	while (tail)
	{
		if (tail->data == x)
		{
			return tail;
		}
		tail = tail->next;
	}
	printf("找不到\n"); 
	return NULL;
}


void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyMemory(x);


	prev->next = newnode;
	newnode->prev = prev;

	newnode->next = pos;
	pos->prev = newnode;
}


void ListErase(ListNode* pos)
{

	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* tail = pos->next;

	prev->next = tail;
	
	tail->prev = prev;

}

void ListDestory(ListNode* pHead)
{
	assert(pHead);
	free(pHead);
	pHead = NULL;
}



