 #define _CRT_SECURE_NO_WARNINGS 1
#include"STist.h"

void TestSTL1()
{
	SListNode* STL = NULL;

	SListPushBack(&STL, 1);
	SListPushBack(&STL, 2);
	SListPushBack(&STL, 3);
	SListPushBack(&STL, 4);
	SListPopBack(&STL);

	printf("%c", SListFind(&STL, 2)->data);
	SListPoqpFront(&STL);



}




int main()
{

	TestSTL1();

	return 0;
}