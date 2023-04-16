 #define _CRT_SECURE_NO_WARNINGS 1

#include"SeqLIst.h"
//sequence 顺序

void If_Add_Capacity(SeqList* obj)
{
	if (obj->size == obj->capacity)
	{
		SLDataType* ptr = (SLDataType*)realloc(obj->a, sizeof(SLDataType) * obj->capacity * 2);
		if (ptr == NULL)
		{
			perror("realloc");

			return;
		}
		obj->a = ptr;
		obj->capacity *= 2;
		ptr = NULL;
	}
	return;
}

void InitSeqList(SeqList* obj)
{
	assert(obj);

	obj->capacity = INIT_CAPACITY;
	obj->size = 0;
	obj->a = (SLDataType*)malloc(sizeof(SLDataType) * obj->capacity);
	if (obj->a == NULL)
	{
		perror("malloc");
		return;
	}
}

void DestorySeqList(SeqList* obj)
{
	assert(obj);

	free(obj->a);
	obj->a = NULL;
	obj->capacity = obj->size = 0;
}

void SeqListBackPush(SeqList* obj, SLDataType x)
{
	assert(obj);
	
	If_Add_Capacity(obj);

	obj->a[(obj->size)++] = x;

}

void SeqListBackPop(SeqList* obj)
{
	assert(obj);
	assert(obj->size > 0);//为真就过、为假就会报错
	
	obj->size--;
}

void SeqListPirnt(SeqList* obj) 
{
	assert(obj);
	for (int i = 0; i < obj->size; i++)
	{
		printf("%d ", obj->a[i]);
	}
	printf("\n");
}


void SeqListFrontPush(SeqList* obj, SLDataType x)
{
	assert(obj);

	If_Add_Capacity(obj);
	for (int i = obj->size; i > 0; i--)
	{
		obj->a[i] = obj->a[i - 1];
	}
	obj->a[0] = x;
	obj->size++;
}

void SeqListFrontPop(SeqList* obj)
{
	assert(obj);
	assert(obj->size > 0);
	for (int i = 0; i < obj->size - 1; i++)
	{
		obj->a[i] = obj->a[i + 1];
	}
	obj->size--;
}

void SeqListInsert(SeqList* obj, int pos, SLDataType x)
{
	assert(obj);
	pos -= 1;//换成下标
	assert(pos >= 0 && pos <= obj->size);
	If_Add_Capacity(obj);
	int i = obj->size;
	for (i; i > pos; i--)//从最后开始将填充数据
	{
		obj->a[i] = obj->a[i - 1];
	}
	obj->a[i] = x;
	obj->size++;
}

void SeqListErase(SeqList* obj, int pos)
{
	assert(obj);
	assert(obj->size > 0);

	pos -= 1;//换成下标
	assert(pos >= 0 && pos <= obj->size);

	for (int i = pos; i < obj->size - 1; i++)
	{
		obj->a[i] = obj->a[i + 1];
	}
	obj->size--;

}


