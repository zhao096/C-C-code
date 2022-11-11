 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int Cheak(int* ar, int lef , int ri , int ke )//在形参部分起的名称可以和实参一样也可以不一样但尽量有意义
{
	while (lef <= ri)
	{

		int mid = (ri + lef) / 2;

		if (ke < *(ar+mid))
		{
			ri = mid - 1;
		}
		else if (ke > *(ar + mid))
		{
			lef = mid + 1;
		}
		else
		{
			return *(ar + mid);
		}

	}
	return 0;



}
int main()
{
	int arr[] = { 1,3,5,7,9,11,13,15,17,19};
	int k = 0;
	int l = 0;
	printf("输入一个数，我来帮你找到它");
	scanf("%d", &k);
	printf("\n");
	int r = sizeof (arr) /sizeof(arr[1]) -1;
	int num = Cheak(arr, l, r, k); // arr为首元素的地址，虽然如此但在形参接收时也可以直接用int arr[] 代替int * ar ，此处就直接用第二种了
									 //但在初学时尽量用第一种，int arr [1] =  *(arr + 1) 注意点+1一定要加括号 
	if (num == 0)
		printf("不在范围内\n");
	else
		printf("找到了 k  = %d", num);

	return 0;
}
