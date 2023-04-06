 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


void Swap(int* t1, int* t2)
{
	int tmp = *t1;
	*t1 = *t2;
	*t2 = tmp;
}

// 选择排序

// 从数组中最小/最大与其第一个位置/最后一个位置的元素进行比较，如果第一个/最后一个位置不适合，则进行交换
// 1. 遍历一遍数组 找出最大/最小的数
// 2. 与第一位/最后一位进行比较
// 3. 判断是否需要进行交换
// 4. 缩小范围
void SelectSort(int* a, int n)
{
	//找出最大的放到最后位
	int left = 0;
	int right = n-1;
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
		//if (maxi != right)
		//{
		//	Swap(&a[maxi], &a[right]);
		//}
		//if (mini != left)
		//{
		//	Swap(&a[mini], &a[left]);
		//}
		//无论是否在同一位置 直接
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


// 堆排序
//向上调整
void Adjustup(int* a, int child)
{
	int parent = child / 2 - 1;
	//此处最好不要用parent 因为当parent == 0 时还要进入
	while (child > 0)
	{
		if (a[parent] < a[child])//建一个大堆
		{
			Swap(&a[parent], &a[child]);
		}
		else
		{
			break;
		}
		child = parent;

		parent = child / 2 - 1;
	}
}

//向下调整
//建大堆
void AjustDown(int* a, int n, int root)
{
	//假设左子树是大的
	int leftchild = root * 2 + 1;
	while (leftchild < n)
	{
		if (a[leftchild] < a[leftchild + 1])
		{
			leftchild++;
		}
		//得到子树中较大的后、就需要比较
		if (a[root] < a[leftchild])
		{
			Swap(&a[root], &a[leftchild]);
		}
		else
		{
			break;
		}

		root = leftchild;
		leftchild = root * 2 + 1;
	}
		

}

void HeapSort(int* a, int n)
{
	//先建一个大堆
	//得到最后一个元素的父亲
	//从此处开始建立大堆 ， 从下往上
	for (int i = n / 2 - 1;i >= 0; i--)
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




int main()
{
	int arr[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}

	SelectSort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	//ShellSort(arr, 10);
	/*HeapSort(arr, 10);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}*/

	return 0;
}