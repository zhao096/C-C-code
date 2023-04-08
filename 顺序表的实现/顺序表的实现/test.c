 #define _CRT_SECURE_NO_WARNINGS 1

#include"SeqLIst.h"

int main()
{
	SeqList s;
	InitSeqList(&s);
	SeqListPush(&s, 1);
	SeqListPush(&s, 2);
	SeqListPush(&s, 3);
	SeqListPush(&s, 4);
	SeqListPush(&s, 5);

	SeqListPop(&s);
	SeqListPop(&s);
	SeqListPop(&s);

	SeqListFrontPush(&s, 0);

	SeqListFrontPush(&s, -1);




	SeqListInsert(&s, 1, 3);
	SeqListErase(&s, 2);
	SeqListPirnt(&s);

	DestorySeqList(&s);


	return 0;
}