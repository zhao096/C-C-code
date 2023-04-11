 #define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
int main()
{
	stack p;
	StackInit(&p);

	StackPush(&p, 1);
	StackPush(&p, 2);
	StackPush(&p, 3);
	StackPush(&p, 4);
	
	datetype tmp = StackSize(&p);
	printf("%d", tmp);

	StackPop(&p);


	StackDestroy(&p);
	return 0;
}