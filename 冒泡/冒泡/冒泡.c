 #define _CRT_SECURE_NO_WARNINGS 1
void baopao_sort(int arr[], int sz)
{
	int a = 0 ;
	for (a = 0; a <= sz - 1; a++)
	{
		int b = 0 ;
		for (b = 0; b <= sz - 1 - a; b++)
		{
			if (arr[b] < arr[b + 1])
			{
				int tmp = arr[b];
				arr[b] = arr[b + 1];
				arr[b + 1] = tmp;
			}

		}
	}
}



int main()
{

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	baopao_sort(arr,sz);
	return 0;
}