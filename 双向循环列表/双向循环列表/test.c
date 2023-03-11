 #define _CRT_SECURE_NO_WARNINGS 1
#include"DLT.h"


void test1(ListNode* head)
{
	ListPushBack(head,1);
	ListPushBack(head, 2);
	ListPushBack(head, 3);
	ListPushBack(head, 4);
	ListPrint(head);

	ListPopBack(head);
	ListPopBack(head);
	ListPrint(head);

}



void test2(ListNode* head)
{
	ListPushFront(head, 1);
	ListPushFront(head, 2);
	ListPushFront(head, 3);
	ListPushFront(head, 4);
	ListPrint(head);

	ListPopFront(head);
	ListPopFront(head);
	ListPrint(head);

	ListNode*  ptr = ListFind(head, 2);
	printf("%d ", ptr->data);
}

int main()
{
	ListNode*  head = ListCreate();

	//test1(head);

	test2(head);
	ListDestory(head);
	free(head);
	head = NULL;
	return 0;
}
		
		
		
		