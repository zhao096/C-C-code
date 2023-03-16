 #define _CRT_SECURE_NO_WARNINGS 1

#include"SLTable.h"

void check_capacity(SeqList * ps)
{
	assert(ps);

	if ((ps->size == ps->capacity - 1))
	{
		//ps->a = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * ps->size * 2);//仍然会报错，所以要写成如下形式
		SLDateType* tmp = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("tmp");
			return;
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
}

void SeqListInit(SeqList* ps)
{
	assert(ps);//当里面内容未假时就会跳出
	ps->a = (SLDateType*)malloc(sizeof(SLDateType) * InitPeo);
	if (ps->a == NULL)
	{
		perror("ps->a");
		return;
	}
	ps->size = 0;
	ps->capacity = InitPeo;
}

void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);
	check_capacity(ps);

	ps->a[ps->size++] = x;//把最后一个元素放到最后size是元素个数用来做下标刚好指向最后一个的后面
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	assert(ps->size);
	ps->size--;
}

void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);
	check_capacity(ps);
	for (int i = ps->size  ; i > 0 ; i--)
	{	
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	assert(ps->size);//判断成员是否为0，为0就报错

	for (int i = 0 ; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}	
	ps->size--;
}

int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	assert(ps->size);//判断成员是否为0，为0就报错

	int tag = 0;
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			tag = 1;

			return ps->a[i];
		}
	}
	if (tag == 0)
	{
		printf("找不到\n");
	}
	return 0;
}

void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{
	assert(ps);
	assert(ps->size);//判断成员是否为0，为0就报错
	check_capacity(ps);


	for (int i = ps->size ; i > pos - 1; i--)//注意pop是我吗所看到的的位置，而数组的位置是要-1的
	{

		ps->a[i] = ps->a[i - 1];

	}
	ps->a[pos - 1] = x;
	ps->size++;

}	

void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	assert(ps->size);//判断成员是否为0，为0就报错

	for (int i = pos - 1; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}





