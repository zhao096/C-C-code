 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


void Swap(int* t1, int* t2)
{
	int tmp = *t1;
	*t1 = *t2;
	*t2 = tmp;
}

// 插入排序
//将下标为i处的值与i-1 、 i-2 、 …… 、 0 的进行比较，如果小于就插到该位置并且后面的往后面移
//void InsertSort(int* a, int n)
//{
//	for (int i = 0; i < n - 1 ; i++)
//	{
//		int j = i+1;
//		while (j>0)
//		{
//			if (a[j] < a[j-1])
//			{
//				Swap(&a[j], &a[j-1]);
//				j--;
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//}

void InsertSort(int* a, int n)
{
	for (int i = 1; i < n ; i++)
	{
		int end = i-1;
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

// 希尔排序
//在插入排序的基础上将他们先分成间隔为gap的高各个小组 再将 以gap为间隔元素进行 预排序
//预排序完后就会接近排好
//再进行插入排序这样就会提高插入排序的效率
//把相差为gap的看成一组，所以一组就会有gap个元素，然后对每一组进行排序（所以他们就相差gap）
void ShellSort(int* a, int n)
{
	//int gap = 3;
	//for (int j = 0; j < gap; j++)
	//{
	//	//一次插入排序，其是其插入排序时当gap = 1时
	//	//i < 倒数第二个元素的位置 其中第一组的倒数第二个位置已经是最大的一个了所以直接：
	//	// i < n - gap即可
	//	//对每组进行排序 从下标为j处开始 
	//	for (int i = j; i < n - gap ; i += gap)
	//	{
	//		int end = i ;
	//		int tmp = a[i+ gap];
	//		while (end >= 0)
	//		{
	//			if (tmp < a[end])
	//			{
	//				Swap(&a[end + gap], &a[end]);
	//				end-= gap;
	//			}
	//			else
	//			{
	//				break;
	//			}
	//		}
	//		a[end + gap] = tmp;
	//	}

	//}
	//InsertSort(a, n);
	int gap = n;
	while (gap > 1)
	{
		gap /= 2;//让其不断7预排序只到gap = 1时就能排好（等于1时相当于插入排序）
		//gap = gap / 3 + 1;
		//直接将多组分开进行合并为一组同时进行
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


int main()
{
	int arr[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}

	InsertSort(arr,5);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	//ShellSort(arr, 10);
	ShellSort(arr, 10);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}