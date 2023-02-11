 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//方法一 ： 在创建一个数组先将要移动的元素拿出然后将原元素向前挪最后将拿出的元素再放回
//int main()
//{
//	char arr[10] = {0};
//	scanf("%s",arr);
//	int i = 0;
//	printf("向左旋转几个字符:" );
//	scanf("%d", &i);
//	int I = 0;
//	char tmp[10] = { 0 };
//
//	for (I = i; I >= 0;I--)//将前i个放到一个新的元素中，从后往前放
//	{
//		tmp[I - 1] = arr[I - 1];
//	}
//
//	for (I = i; I < (int)strlen(arr); I++)//I将后面的几个元素往前放；即第i个(数组从0开始)开始向前i步放到第一个以此类推
//	{
//		arr[I - i]=arr[I] ;
//	}
// 
//	int t = i;
//	for (I = 0; I < t; I++)//I从开始只需要i次 即将tmp中存放的元素放回arr中
//	{
//		arr[strlen(arr) - i ] = tmp[I];//此处strlen(arr) - i 是为了当i>数组一半时仍可以正常，若为arr[i] = arr[I]的话如先前攒4个字符的话在abcdef中
//										//将变成efabcd而会在从arr[4]处开始返回就不对了,应该从arr【2】即从arr[strlen...]处开始放回
//		if(i>0) 
//		i--;
//	}
// 
//	printf("%s", arr);
//	return 0;
//}


//第二种方法：先拿出一个存进tmp、在将剩下的往前移、在将tmp存到最后，左移i次（个）
//void left_move(char arr[], int i)
//{
//
//	int str = strlen(arr);
//	i %= 6;//当大于6个是就会重复的向左移、余6就可以减少次数
//	for (int n = 0; n < i; n++)
//	{
//		char tmp = arr[0];
//
//		for (int t = 0; t < str - 1; t++)
//		{
//			arr[t] = arr[t + 1];
//		}
//
//		arr[str - 1] = tmp;
//		
//	}
//
//}
//int main()
//{
//	char arr[10] = { 0 };
//	scanf("%s", arr);
//	int i = 0;
//	printf("向左旋转几个字符:");
//	scanf("%d", &i);
//	
//	left_move(arr,i);
//
//	printf("%s", arr);
//	return 0;
//}

//第三种方法：将要转移的字先逆序，再将剩下的逆序、最后一起逆序就可以得出
//如逆序两个字符：abcdef-> ba cedf ->  ba fdec -> cedfab

void reserve(char *left , char *right)
{
	assert(left && right);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
int main()
{
	char arr[10] = { 0 };
	scanf("%s", arr);
	int i = 0;
	printf("向左旋转几个字符:");
	scanf("%d", &i);
	int str = strlen(arr);
	i %= 6;//防止越界
	reserve(arr, arr + i - 1);//第一步将要左移的字符先逆序,-1 如当要左移2个字符时指针若要指向第二个字符只需要 + 1 而i为2

	reserve(arr + i, arr + str - 1);//逆序剩下的，

	reserve(arr, arr + str - 1);//-1 同理
	
	printf("%s", arr);
	return 0;
}