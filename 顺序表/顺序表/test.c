#define _CRT_SECURE_NO_WARNINGS 1

#include"SLTable.h"

int main()
{

	SeqList con;

	SeqListInit(&con);
	
	//SeqListDestroy(&con);



	SeqListPushFront(&con, 20);

	SeqListPushBack(&con, 10);

	SeqListPushBack(&con, 5);

	SeqListPrint(&con);

	SeqListInsert(&con, 2, 8);
	SeqListInsert(&con, 4, 7);

	SeqListPrint(&con);
	
	SeqListPopBack(&con);

	SeqListPopFront(&con);

	SeqListErase(&con, 1);

	SeqListPrint(&con);


	return 0;
}