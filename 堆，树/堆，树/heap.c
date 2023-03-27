 #define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

void Swap(HPDataType* s1, HPDataType* s2)
{
	/*HPDataType* tmp = s1;*///传址调用当s1被改变时因为tmp存的是外部的地址所以s1的改变也会改变tmp
	//应该直接写成HPDataType tmp 即可 不要写成指针
	HPDataType tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void Adjustup(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	/*while (parent > 0)*///此处的最好不要用parent >= 0虽然也能跑的过，而是用child > 0
	while(child > 0)
	{
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);//需要传址调用
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//void AdjustDown(HPDataType* a, int parent,int n)
//{
//	int leftchild = (parent * 2) + 1;
//	int rightchild = (parent * 2) + 2;
//	while (leftchild < n )
//	{
//		if (a[leftchild] > a[rightchild])
//		{
//			Swap(&a[leftchild], &a[parent]);
//			parent = leftchild;
//		}
//		else
//		{
//			if(rightchild < n)//注意右边的可能因为不存在而越界
//			Swap(&a[rightchild], &a[parent]);
//			parent = rightchild;
//
//		}
//		leftchild = (parent * 2) + 1;
//		rightchild = (parent * 2) + 2;
//		
//	}
//}

void AdjustDown(HPDataType* a, int parent, int n)
{
	//先把左边的看成大的
	int child = (parent * 2) + 1;
	while(child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			++child;
		}

		if(a[child]>a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = (parent * 2) + 1;
		}
		else
		{
			break;
		}
	}
}


void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	if (hp->_a == NULL)
	{
		perror("malloc");
		return;
	}
	hp->_capacity = n;
	hp->_size = 0;
}

void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
	free(hp);
}

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->_capacity == hp->_size)
	{
		HPDataType * p = (HPDataType*)realloc(hp->_a,sizeof(HPDataType) * hp->_capacity * 2);
		if (p == NULL)
		{
			perror("realloc");
			return;
		}
		hp->_a = p;
		hp->_capacity *= 2;//注意开辟空间后要乘2
		p = NULL;
	}
	hp->_a[hp->_size] = x;
	Adjustup(hp->_a, hp->_size);
	hp->_size++;
}


void HeapPop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	//删除数据
	//先将最大的数据和最后一个进行交换
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	//交换后直接--即可
	hp->_size--;
	//再判断一下是否要进行回复成大堆,通过向下调整的方法
	AdjustDown(hp->_a,0,hp->_size);
}


HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
bool HeapEmpty(Heap* hp)
{
	return hp->_size == 0;
}




