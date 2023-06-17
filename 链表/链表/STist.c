 #define _CRT_SECURE_NO_WARNINGS 1

#include"STist.h"

SListNode* BuySListNode(SLDateType x) {//接收传进来的数据
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));//用malloc开辟一个结构体大小的空间给新节点
	if (newnode == NULL)//熟系的判断是否申请成功
	{
		perror("malloc failed");
		return NULL;
	}
	newnode->data = x;//在申请的结构体空间中放入数据
	newnode->next = NULL;//将其下一个位置暂时指向NULL
	return newnode;//返回这个节点，返回类型是个指针类型也就是newnode的地址
}

void SListPrint(SListNode* phead)
{
	SListNode* tail = phead;//用一个指针来指向开始

	while (tail != NULL)//只要tail不到NULL都要进群
	{
		printf("%d->", tail->data);//进来打印tail的date
		tail = tail->next;//往后走
	}
	printf("NULL\n");//打印一下最后的NULL
}

void SListPushBack(SListNode** pphead, SLDateType x) {//注意此处用二级指针是因为可能要修改结构体变量（或理解成传进来的是一级指针类型为了修改他就需要用二级指针）
	assert(pphead);//判空，注意此处的判空是判的pphead 而不是 STL（*pphead） 
	SListNode* newnode = BuySListNode(x);//先创建一个新节点,调用创建节点的函数
	SListNode* tail = *pphead;//一个指针指向链表开始（可能为NULL）
	
	if (*pphead == NULL)//此处就是一个类似初始化的步骤
	{
		*pphead = newnode;//此处修改了了结构体变量，即修改了STL的指向指向新创建的链表的开始
	}

	else {//当不是最开始时就正常的进行尾插	
		while (tail->next) {//找尾部的NULL
			tail = tail->next;//没找到就改变tail 让其变成next 继续往后找
		}
		tail->next = newnode;//找到后把最后一个位置的数据的next 变成 新节点即可
	}
}

//头插就会简单很多
void SListPushFront(SListNode** pphead, SLDateType x){//同样用到二级指针，因为需要改变链表结构体变量
	assert(pphead);
	SListNode* newnode = BuySListNode(x);//创建节点

	newnode->next = *pphead;//将新开辟的空间的地址指向链表原本第一个元素的 地址
	*pphead = newnode;//改变链表的起始地址
}

void SListPopBack(SListNode** pphead) {//可能会修改外部数据所以用二级指针
	assert(pphead);
	assert(*pphead);
	if ((*pphead)->next == NULL)//查看第一个数据位置是不是最后一个数据如果是的话
	{
		free(*pphead);//直接释放第一个位置的数据即可
		*pphead = NULL;//把没用的指针置为NULL
	}
	else
	{
		SListNode* tail = *pphead;//用tail代替*pphead，使*pphead不被改变

		while (tail->next->next) {//往后看两位，当为空时，就表示到了倒数第二的位置
			tail = tail->next;//一步一步走
		}

		free(tail->next);//找到后，tail表示的是倒数第二，而tail->next就是尾，free释放尾即可
		tail->next = NULL;//tail->next改变成NULL，因为此时tail变成了最后一个数据
	}
}

void SListPopFront(SListNode** pphead) {
	assert(pphead);//防止pphead为空
	assert(*pphead);//查看是否有第一个数据

	SListNode* frist = *pphead;//记录第一个数据的位置
	*pphead = frist->next;//改变链表的头，改成下一个位置（可能为空当只有一个数据的时候）
	free(frist);//(释放第一个数据的位置)
	frist = NULL;//没有的指针置为空
}

SListNode* SListFind(SListNode* phead, SLDateType x) {//指针接收结构体
	SListNode* find = phead;
	while (find)//一个循环来找想要的数据
	{
		if (find->data == x)//当找到时
		{
			return find;//返回此处的地址
		}
		find = find->next;//不断往后找和找尾方法一样
	}
	printf("找不到\n");
	return NULL;//若找不到返回NULL
}

void SListInsertAfter(SListNode* pos, SLDateType x) {//此处把链表的地址传给了pos
	assert(pos);
	SListNode* newnode = BuySListNode(x);//创建新节点
	newnode->next = pos->next;//先改变newnode的节点
	pos->next = newnode;//再把pos->next改成newnode
}
void SListInsertFront(SListNode** pphead,SListNode* pos, SLDateType x) {//当是在pos位置前面插入时就要考虑头插了所以可能会改变链表的开始就需要用到二级指针
	assert(pphead);
	assert(pos); 
	if (pos == *pphead)//如果pos位置在第一个那就等于在第一个位置前面插入数据也就是头插
	{
		SListPushFront(pphead, x);
	}
	else
	{
		SListNode* tail = *pphead;
		while (tail->next != pos)//找到pos位置的前一个位置
		{
			tail = tail->next;
		}
		SListNode* newnode = BuySListNode(x);//申请一个节点
		newnode->next = tail->next;//先把newnode的指针改变，这样避免当tail改变后找不到tail->next的情况
		tail->next = newnode;//再将tail->next 指向改变成 newnode
	}
}


void SListErase(SListNode** pphead,SListNode* pos) {
	assert(pos);//不用再对*pphead进行检查了因为pos已经间接的检查了*pphead 检查的是是否链表中是否有数据假如没有的话pos也会报错
	assert(pphead);//判空
	SListNode* tail = *pphead;
	if (*pphead == pos)//若是第一个元素
	{
		SListPopFront(pphead);//那就直接头删
	}
	else
	{
		while (tail->next != pos)//找到pos位置的前一个位置
		{
			tail = tail->next;
		}
		tail->next = pos->next;//将前面位置的next改变成pos位置的next，这样就把pos位置给断开了
		free(pos);//把pos位置处的空间给释放
	}
}


void SListEraseAfter(SListNode* pos) {
	assert(pos);
	if (pos->next == NULL)//注意查看pos位置后面是否还有数据
	{
		return;//若没有则直接返回了
	}
	else {
		SListNode* del = pos->next;//记录pos后面的位置
		pos->next = pos->next->next;//改变链接关系让pos的后面位置指向pos位置后的后面位置
		free(del);//释放del
		del = NULL;
	}
}

void SListDestroy(SListNode* plist) {
	assert(plist);

	SListNode* prev, * tail;//双指针
	prev = plist;//指向头
	tail = plist->next;//指向第二个数据的位置
	while (prev)//当prve==NULL就不用进循环了也表示释放完了
	{	
		free(prev);//释放prev出的空间
		prev = tail;//将prve指向tail
		if(tail != NULL)//判断tail是不是NULL
			tail = tail->next;//若是NULL就不能再往后了
	}
	plist = NULL;//将没用的指针赋成空指针
}

