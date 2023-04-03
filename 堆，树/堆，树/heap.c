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

//建小堆
void AdjustDown(HPDataType* a, int parent, int n)//a数组，parent父亲节点、n元素个数
{
	//先把左边的看成大的
	int child = (parent * 2) + 1;
	while(child < n)
	{
		if (child + 1 < n && a[child] > a[child + 1])
		{
			++child;
		}

		if(a[child]<a[parent])
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

	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(hp->_a, i, n);
	}
}

void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
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

void PrintTopK(int n, int k)
{
	FILE* pd = fopen("test.txt", "r");

	//对于树来说他其实是数组，只不过那树来展示
	//所以我们需要开辟一遍空间

	int* ttopk = (int*)malloc(sizeof(int) * k);

	if (pd == NULL || ttopk == NULL)
	{
		perror("PrintTopk");
		fclose(pd);
		free(ttopk);
		return;
	}

	//从文件中取出元素并且开辟小堆

	for (int i = 0; i < k; i++)
	{
		fscanf(pd, "%d", &ttopk[i]);
	}
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(ttopk, i, k);
	}

	//将文件中的数据和小堆顶的数据进行比较，如果大于就进去，否则退出
	int val = 0;
	int ret = fscanf(pd, "%d",&val);
	while (ret != EOF)
	{
		if (ttopk[0] < val)
		{
			Swap(&ttopk[0], &val);
			AdjustDown(ttopk, 0, k);
		}
		ret = fscanf(pd, "%d", &val);
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d\n", ttopk[i]);
	}

	fclose(pd);
	free(ttopk);
}
void TestTopk()
{
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}
	srand((unsigned int)time(0));
	for (int i = 0; i < 100; i++)//生成100个数
	{
		int s = rand() % 100;
		fprintf(pf, "%d\n", s);
	}

	fclose(pf);
	pf = NULL;

	PrintTopK(100, 10);//总共100数据，找出最大的前10个
}



// 二叉树查找值为x的结点
//BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
//{
//	if (root == NULL)
//		return NULL;
//	if (root->data == x)
//	{
//		return root;
//	}
//	BinaryTreeFind(root + 1, x);
//	BinaryTreeFind(root + 2, x);
//}








