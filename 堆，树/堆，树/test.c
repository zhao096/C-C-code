#define _CRT_SECURE_NO_WARNINGS 1

#include"heap.h"

int main()
{
	Heap hp;
	hp._a = 0;
	HeapCreate(&hp,hp._a,4);

	HeapPush(&hp, 12);
	HeapPush(&hp, 22);
	HeapPush(&hp, 34);
	HeapPush(&hp, 134);
	HeapPush(&hp, 77);
	HeapPush(&hp, 77);
	HeapPush(&hp, 77);
	HeapPush(&hp, 77);
	HeapPush(&hp, 77);
	HeapPush(&hp, 77);
	HeapPush(&hp, 77);
	HeapPush(&hp, 77);
	HeapPush(&hp, 77);
	HeapPush(&hp, 77);
	HeapPush(&hp, 77);


	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	printf("\n");

	HeapDestory(&hp);


	return 0;
}