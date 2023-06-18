 #define _CRT_SECURE_NO_WARNINGS 1

#include"DLT.h"

ListNode* BuyMemory(LTDataType  x)//申请空间的函数
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));//malloc申请一个大小为一个结构体（一个节点的）空间
	if (node== NULL)//若申请失败
	{
		perror("malloc::BuyMemory");//报错
		//return NULL;
		exit(-1);//直接退出程序
	}
	node->data = x;//将申请中的空间数据置为给定的x
	node->next = NULL;//将next先置为NULL
	node->prev = NULL;//将prev先置为NULL

	return node;//返回借号的空间
}

ListNode* ListCreate()//给头申请空间并且返回头指针的地址
{
	ListNode* head = BuyMemory(-1);//申请空间并且将其数据置为-1
		head->next = head;//将next指向head
		head->prev = head;//prev也是指向头的
	return head;//返回头申请好的空间
}

void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	//ListNode* newnode = BuyMemory(x);//创建新节点
	//ListNode* tail = pHead->prev;//记录原本的尾部数据结构
	////原本的链接顺序：tail <-> head
	////改变后的链接顺序：tail <-> newnode <-> head
	//
	////先改变 tail <-> newnode
	//tail->next = newnode;
	//newnode->prev = tail;
	////再把newnode和head链接起来：newnode<->head
	//newnode->next = pHead;	
	//pHead->prev = newnode;
	ListInsert(pHead,x);
}


void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;//从第一个节点开始
	printf("《=》head《=》");

	while (cur != pHead)//当不是pHead就进去
	{
		printf("%d《=》", cur->data);//打印
		cur = cur->next;//往后走
	}
	printf("\n");
}

bool If_DTLEmpty(ListNode* pHead)//返回bool值,即返回真或假
{
	if (pHead->next == pHead)//就判断phead的->是不是自己即可，因为如果不是则表示是有数据的，反之因为是循环链表没数据就会指向自己了
	{
		return true;//若指向自己则是真 空的
	}
	else
	{
		return false;//反之则非空
	}

}


void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	assert(!If_DTLEmpty(pHead));//判断是否为空
	//ListNode* new_tail = pHead->prev->prev;//记录倒数第二个节点
	//ListNode* old_tail = pHead->prev;//记录倒数第一个节点

	////改变链接关系
	//new_tail->next = pHead;
	//pHead->prev = new_tail;

	//free(old_tail);//释放倒数第一个节点
	//old_tail = NULL;
	ListErase(pHead->prev);
}


void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);//判空
	ListNode* newnode = BuyMemory(x);//创建新节点
	ListNode* frist = pHead->next;//记录原本的链表的第一个数据
	//改变链接关系
	// phead <-> first
	// phead <-> newnode <-> first
	//先改变newnode与第一个数据间的关系，
	// newnode <-> firest
	newnode->next = frist; 
	frist->prev = newnode;
	//再改变新节点个head的链接关系
	// head <-> newnode
	newnode->prev = pHead;
	pHead->next = newnode;
	//改完后 ：phead <-> newnode <-> frist

	//ListInsert(pHead->next,x);
}



void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(!If_DTLEmpty(pHead));//判断是否为空
	ListNode* front = pHead->next;//记录第一个节点


	ListNode* frist = pHead->next->next;//记录第二个节点
	//改变链接关系
	// head <-> front <-> frist  ==  head <-> first
	pHead->next = frist;
	frist->prev = pHead;

	
	free(front);//改变链接关系后把第一个节点释放
	front = NULL;
	//ListErase(pHead->next);

}

ListNode* ListFind(ListNode* pHead, LTDataType x)
{

	assert(pHead);

	ListNode* tail = pHead;//tail指向链表
	while (tail)//通过tail指针来找
	{
		if (tail->data == x)//找结构中的值是不是等于x
		{
			return tail;//找到后返回节点的地址
		}
		tail = tail->next;//往后走
	}
	printf("不存在,找不到\n"); //若到了此处就表示链表中的数据没有x
	return NULL;//此时返回NULL表示不存在该数据的节点
}


void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);//判空
	ListNode* prev = pos->prev;//记录前面的数据
	ListNode* newnode = BuyMemory(x);//创建新节点

	//改变链接关系
	// prev pos
	// prev newnode pos
	
	// prev newnode 
	prev->next = newnode;
	newnode->prev = prev;
	// newnode pos
	newnode->next = pos;
	pos->prev = newnode;

// prev newnode pos
}


void ListErase(ListNode* pos)
{
	assert(pos);//判空
	ListNode* prev = pos->prev;//记录pos前面节点
	ListNode* tail = pos->next;//记录pos后面的节点
	//改变链接关系
	prev->next = tail;
	
	tail->prev = prev;
	//释放pos
	free(pos);
}

void ListDestory(ListNode* pHead)
{
	assert(pHead);
	ListNode* tail = pHead->prev;//从第一个节点开始
	while (tail != pHead)//当没遇到头前就不断释放再往前走
	{
		ListNode* destroy = tail;//记录要释放的节点地址
		tail = tail->next;//tail往后走
		free(destroy);//释放空间
	}
	free(pHead);//最后当把链表中的数据释放完后，再释放头
}



