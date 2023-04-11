 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"stack.h"


void Swap(int* t1, int* t2)
{
	int tmp = *t1;
	*t1 = *t2;
	*t2 = tmp;
}

int GetMidNumi(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] > a[mid])
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if(a[right] > a[left])
		{
			return left;
		}
		else {
			return right;
		}
	}
	else
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if(a[right] < a[left])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	return right;
}

// 冒泡排序
void BubbleSort(int* a, int n)
{
	int tag = 0;
	for (int j = 0; j < n ; j++)
	{
		for (int i = 0; i < n - j - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i],&a[i+1]);
				tag = 1;
			}
		}
		if (tag == 0)
		{
			break;
		}
	}
	
}
//
// 快速排序递归实现
// 快速排序hoare版本

//先确定一个key 通过这个key来进行分隔
//将一个数组通过key 将小于key的放在其左边 ， 反之放到右边
//用left找大的的、right找小的，找到后交换，然后继续找直到left和right相遇
//让后通过改变left 和 right 来递归实现
int PartSort1(int* a, int left, int right)
{
	if (left >= right)
	{
		return 0 ;
	}

	//生成随机的keyi
	 int r =left + (rand() % (right - left));
	 Swap(&a[left], &a[r]);
	 int keyi = left;

	//三数取中
	//int midi = GetMidNumi(a, left, right);
	//if(left != midi)
	//	Swap(&a[left], &a[midi]);
	//int keyi = left;//此处直接把keyi赋值为left

	int end = right,begin = left;
	while (left < right)
	{
		//while (end)//让right先找这样就能保证最终于key交换的一定是小的（key 在最左边时）
		//{
		//	if (a[end--] <= a[keyi])
		//		break;
		//}
		//while (begin)
		//{
		//	if (a[begin++] > a[keyi])
		//		break;
		//}
		while (right > left && a[right] >= a[keyi])//从右边开始找到小于key的
			right--;
		while (left < right && a[left] <= a[keyi])//从左边开始找到大于key的
			left++;

		Swap(&a[right], &a[left]);
	}
	Swap(&a[keyi], &a[right]);

	keyi = right;

	return keyi;
	
}	
// 快速排序挖坑法

int PartSort2(int* a, int left, int right)
{
	if (left >= right)
	{
		return 0;
	}
	//将keyi所指的数据先拿出来
	//再从左右两边来找先从右边开始找到小的就填到这个拿出来的位置hole上
	//并且把hole改成右边下的位置的下标
	//再从左边找大的，填到hole里
	//重复 直到 left 和 right 相遇
	//最后把拿出去的值放到这个坑即可
	
	//随机选k
	int r = left + (rand() % (right - left));
	Swap(&a[left], &a[r]);

		//三数取中
	//int midi = GetMidNumi(a, left, right);
	//if (left != midi)
	//	Swap(&a[left], &a[midi]);

	int hole = left;

	int keyi = a[left];
	int begin = left, end = right;
	while (left < right)
	{
		while (right > left && a[right] >= keyi)
		{
			right--;
		}
		Swap(&a[hole] , &a[right]);
		hole = right;

		while (left < right && a[left] <= keyi)
		{
			left++;
		}
		Swap(&a[hole], &a[left]);
		hole = left;
	}	
	a[hole] = keyi;

	return hole;
}
// 快速排序前后指针法
//一前一后的指针
//cur 不断的往前走，cur如果遇到小于key的值就先让prev++ ，再交换prev和cur所指的值
int PartSort3(int* a, int left, int right)
{
	if (left >= right)
	{
		return 0;
	}

	//随机选k
	//int r = left + (rand() % (right - left));
	//Swap(&a[left], &a[r]);
	//int keyi = left;

	//三数取中
	int midi = GetMidNumi(a, left, right);
	if (left != midi)
		Swap(&a[left], &a[midi]);
	int keyi = left;//此处直接把keyi赋值为left

	int prev = left ,cur = left+1;

	//通过两个指针进行交换把大的往后移把小的放在前面
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	Swap(&a[prev], &a[keyi]);
	keyi = prev;

	return keyi;

}
void quicksort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int end = right, begin = left;

	int keyi = PartSort3(a,begin, end);
	quicksort(a, begin, keyi-1);
	quicksort(a, keyi+1, end);
}

// 快速排序 非递归实现
//用栈来存区间，通过区间来

void QuickSortNonR(int* a, int left, int right)
{
	stack sk;
	StackInit(&sk);

	StackPush(&sk, left);
	StackPush(&sk, right);


	while (!StackEmpty(&sk))
	{
		right = StackTop(&sk);//
		StackPop(&sk);
		left = StackTop(&sk);
		StackPop(&sk);
		int keyi = PartSort3(a,left,right);

		//[left , keyi-1] keyi [keyi+1,right]
		if (keyi+1 < right)// 先从右边开始入栈，这样就是左边先出栈、keyi + 1 != right 如果等于了说明已经排完了（left <= right）
		{
			StackPush(&sk, keyi + 1);
			StackPush(&sk, right);
		}
		if (keyi-1 > left)//小于表示至少有两个数据，等于表示只有一个数据，若大于则表示不存在空间
		{
			StackPush(&sk,left);
			StackPush(&sk, keyi - 1);

		}
	}
	StackDestroy(&sk);
}

int main()
{
	srand((unsigned int) time(0));
	int arr[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}

	//BubbleSort(arr, 5);
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	//printf("\n");

	QuickSortNonR(arr, 0,9);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}