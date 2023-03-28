 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef int HPDataType;
typedef struct Heap//顺序表实现二叉树
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;


void Swap(HPDataType* s1, HPDataType* s2)
{
	/*HPDataType* tmp = s1;*///传址调用当s1被改变时因为tmp存的是外部的地址所以s1的改变也会改变tmp
	//应该直接写成HPDataType tmp 即可 不要写成指针
	HPDataType tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}


//向上调整和向下调整的前提是左右子树必须是大/小堆
void Adjustup(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	/*while (parent > 0)*///此处的最好不要用parent >= 0虽然也能跑的过，而是用child > 0
	while (child > 0)
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




void HeapSort(int* a, int n)
{
	////排升序，要建大堆
	// 用向上调整的方法来建堆
	//for (int i = 1; i < n; i++)
	//{
	//	Adjustup(a, i);
	//}
	// 用向下调整的方法来建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, i, n);

	}
	while (n--)
	{
		Swap(&a[n], &a[0]);
		AdjustDown(a, 0, n);
	}

}

int main()
{
	int arr[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("\n");

	//堆排序
	HeapSort(arr,10);
	return 0;
}