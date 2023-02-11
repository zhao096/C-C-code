 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>



void Find_num(int arr[][3],int r , int c,int k)
{
	int i = 0;
	int flag = 0;
	while (i < r && c >= 0)//当超过范围就跳出
	{
		if (arr[i][c - 1] > k)  //从右上角逐渐的开始找    右上角的意义有一排中的最大和一行中的最小
		{
			c--;//当右上角的数大于k ，就需要向前一行因为右上角已经是一行中的的最小
		}
		else if (arr[i][c - 1] < k)
		{
			i++;//当小于k，需要去掉该一排也就可以加1向下走
		}
		else
		{
			flag = 1;
			printf("找到了是:%d\n", arr[i][c - 1]);
			return;
		}
	}
	if (!flag)//若为假就会变成真打印反之为真则会未假
		printf("找不到\n");

}

int main()
{
	//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int i = 0, r = 3, j = 0, c = 3;

	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}


	int key = 0;
	printf("请输入你所要查找的数字>");
	scanf("%d", &key);

	Find_num(arr, r, c, key);

	return 0;
}