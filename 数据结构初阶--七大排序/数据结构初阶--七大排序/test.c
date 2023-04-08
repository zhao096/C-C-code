#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void Swap(int* t1, int* t2)
{
	int tmp = *t1;
	*t1 = *t2;
	*t2 = tmp;
}
// 选择排序
void SelectSort(int* a, int n)
{
	//找出最大的放到最后位
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int maxi = right, mini = left;
		for (int i = left; i <= right; i++)
		{

			if (a[maxi] < a[i])
			{
				maxi = i;
			}
			if (a[mini] > a[i])
			{
				mini = i;
			}
		}
		Swap(&a[maxi], &a[right]);
		if (mini == right)//如果当mini == right 因为上面已经把原本right处的值进行了交换，所以我们需要改变一下mini
		{
			mini = maxi;//因为mini所指向的位置已经变成了 maxi的所指的值 ， 所以要把mini 变成 maxi 指向正确的值

		}
		Swap(&a[mini], &a[left]);

		left++;
		right--;
	}
}

void AjustDown(int* a, int n, int root)
{
	//假设左子树是大的
	int leftchild = root * 2 + 1;
	while (leftchild < n)
	{
		if (leftchild + 1 < n && a[leftchild] < a[leftchild + 1])//注意leftchild + 1 < n
		{
			leftchild++;
		}
		//得到子树中较大的后、就需要比较
		if (a[root] < a[leftchild])
		{
			Swap(&a[root], &a[leftchild]);
			root = leftchild;
			leftchild = root * 2 + 1;
		}
		else
		{
			break;
		}


	}


}

void HeapSort(int* a, int n)
{
	//先建一个大堆
	//得到最后一个元素的父亲
	//从此处开始建立大堆 ， 从下往上
	//n - 1 - 1 
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AjustDown(a, n, i);
	}
	//排升序通过大堆的方法

	while (n--)
	{
		Swap(&a[n], &a[0]);
		AjustDown(a, n, 0);
	}
}

void InsertSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int end = i - 1;
		int tmp = a[i];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				Swap(&a[end + 1], &a[end]);
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;
	//gap = gap / 3 + 1;
	while (gap > 1)
	{
		gap /= 2;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[i + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					Swap(&a[end + gap], &a[end]);
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
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
		else if (a[right] > a[left])
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
		else if (a[right] < a[left])
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
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n - j - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				tag = 1;
			}
		}
		if (tag == 0)
		{
			break;
		}
	}

}

int PartSort1(int* a, int left, int right)
{
	if (left >= right)
	{
		return 0;
	}

	//生成随机的keyi
	int r = left + (rand() % (right - left));
	Swap(&a[left], &a[r]);
	int keyi = left;

	//三数取中
	//int midi = GetMidNumi(a, left, right);
	//if(left != midi)
	//	Swap(&a[left], &a[midi]);
	//int keyi = left;//此处直接把keyi赋值为left

	int end = right, begin = left;
	while (left < right)
	{
	
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
		Swap(&a[hole], &a[right]);
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
	int keyi = left;

	int prev = left, cur = left + 1;

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

	int keyi = PartSort3(a, begin, end);
	quicksort(a, begin, keyi - 1);
	quicksort(a, keyi + 1, end);
}