 #define _CRT_SECURE_NO_WARNINGS 1


//挖坑法
void QuickSort1(int* a, int left, int right)
{
	if (left >= right)
		return;

	int begin = left, end = right;

	//// 随机选key
	/*int randi = left + (rand() % (right - left));
	Swap(&a[left], &a[randi]);*/

	// 三数取中
	//int midi = GetMidNumi(a, left, right);
	//if (midi != left)
	//	Swap(&a[midi], &a[left]);

	int tmp = a[left];
	
	int hole = left;
	while (left < right)
	{
		while (left < right && a[right] >= tmp)
		{
			--right;
		}
		a[hole] = a[right];
		hole = right;

		while (left < right && a[left] <= tmp)
		{
			++left;
		}
		a[hole] = a[left];
		hole = left;
		
	}
	a[hole] = tmp;//把坑的位置放好原本拿出去的值

	// [begin, keyi-1] keyi [keyi+1, end] 
	// 递归
	QuickSort1(a, begin, hole - 1);
	QuickSort1(a, hole + 1, end);
}



// 前后指针法
int PartSort3(int* a, int left, int right)
{
	int prev = left;
	int cur = left + 1;

	int keyi = a[left];

	while(left <= right)
	{
		if (a[right] < keyi)
		{
			prev++;
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[prev], &a[left]);
}