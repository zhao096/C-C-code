 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)//此处表示只有一个元素了，所以进行返回
	{
		return;
	}

	int mid = (begin + end) / 2;
	_MergeSort(a, begin,mid , tmp);

	_MergeSort(a, mid + 1, end, tmp);

	//归并

	//第一次返回后来到这
	//这时有两个进行排序 也就是[begin,mid][mid+1,end]
	//只需要把他们先从a数组中存放到tmp中再从tmp中选择后排回来
	
	int begin1 = begin, end1 = mid;
	int begin2 = mid+1, end2 = end;
	
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] >= a[begin2])
		{
			tmp[i++] = a[begin2++];
		}
		else
		{
			tmp[i++] = a[begin1++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	memcpy( a + begin, tmp + begin, sizeof(int) * (end - begin + 1));//des、src

}


void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
		if (tmp == NULL)
		{
			perror("malloc");
			return;
		}

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}
// 归并排序非递归实现

void MergeSortNonR1(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc");
		return;
	}

	
	int begin = 0;
	//间隙 gap 

	int gap = 1;//gap == 1 表示直接从最底部开始进行归并
	while (gap < n)//gap < n  并且 gap 最后要乘等 2 是为了模拟归并中往回反的过程
	{
		//i保证用来对同一层的进行归并
		for (int i = begin;i < n ;i += (2 * gap))
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			//在归并过程中end1、begin2、end2 都有可能出现越界，begin1 < n 并不会出现越界问题
			//因为end1 = begin1 + gap -1 ,所以有可能越界
			//因此需要防范
			if (end1 >= n || begin2 >= n)
			{
				break;
			}
			else
			{
				if (end2 >= n)
				{
					end2 = n - 1;
				}
			}
			int j = i;

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] >= a[begin2])
				{
					tmp[j++] = a[begin2++];
				}
				else
				{
					tmp[j++] = a[begin1++];///
				}
			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}

			memcpy(a + begin, tmp + begin, sizeof(int) * (end2 - begin + 1));//des、src

		}
		gap *= 2;
	}


	free(tmp);
}

void MergeSortNonR2(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc");
		return;
	}


	int begin = 0;
	//间隙 gap 

	int gap = 1;//gap == 1 表示直接从最底部开始进行归并
	while (gap < n)//gap < n  并且 gap 最后要乘等 2 是为了模拟归并中往回反的过程
	{

		//i保证用来对同一层的进行归并
		for (int i = begin; i < n; i += (2 * gap))
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;


			//在归并过程中end1、begin2、end2 都有可能出现越界，begin1 < n 并不会出现越界问题
			//因为end1 = begin1 + gap -1 ,所以有可能越界
			//因此需要防范
			if (end1 >= n )
			{
				end1 = n - 1;
				begin2 = n + 1;
				end2 = n;
			}
			else if(begin2 >= n)
			{
				begin2 = n + 1;
				end2 = n;
			}
			else if (end2 >= n)
			{
				end2 = n - 1;
			}
			printf("[%d,%d][%d,%d] ", begin1, end1, begin2, end2);

			int j = i;

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] >= a[begin2])
				{
					tmp[j++] = a[begin2++];
				}
				else
				{
					tmp[j++] = a[begin1++];///
				}
			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}

		}
		printf("\n");
		gap *= 2;
		memcpy(a, tmp, sizeof(int) * n);
	}

	free(tmp);
}


// 计数排序
//把一个数据放到对应的位置
// 1 9 8 1 3 3 7 7 2 3 4

//开辟一个空间的位置，计算在对应位置出现的次数

void CountSort(int* a, int n)
{
	int max = 0;
	int min = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[max] < a[i])
		{
			max = i;
		}
		if (a[min] > a[i])
		{
			min = i;
		}
	}
	int range = a[max] - a[min] + 1;//min、max都代表的是下标所以要+1
	//找到最大和最小确定所要开辟的空间大小
	//
	int* ptr = (int*)calloc(range,sizeof(int) );
	if (ptr == NULL)
	{
		perror("malloc");
		return;
	}
	//假如最大是9 、最下是1 则range就为8，开辟一个大小为8的数组（从1~9共，就能把）
	//此时ptr的第一个下标所代表数字a[i] == 下标 + a[min] （如 下标为0 要是表示的是1 ；0 + min == 0 + 1 == 1）
	//反之ptr的 下标 ==  a[i] - a[min]
	for (int i = 0; i < n; i++)//i < n 把数组中的元素全部放到对应的位置上
	{
		ptr[a[i]- a[min]]++;//对该下标进行++ 表示出现的次数
	}

	int j = 0;//j 控制覆盖
	for (int i = 0; i < range ; i++)// i < range 把ptr 中的所有数据都取出
	{
		while (ptr[i]--)
		{
			a[j++] = i + a[min];
		}
	}

}

int main()
{
	int a[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		scanf("%d",&a[i]);
	}

	MergeSortNonR2(a,10);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}