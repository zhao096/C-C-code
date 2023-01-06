 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	char arr[10] = {0};
	scanf("%s",arr);
	int i = 0;
	printf("向左旋转几个字符:" );
	scanf("%d", &i);
	int I = 0;
	char tmp[10] = { 0 };

	for (I = i; I >= 0;I--)//将前i个放到一个新的元素中，从后往前放
	{
		tmp[I - 1] = arr[I - 1];
	}

	for (I = i; I < strlen(arr); I++)//I将后面的几个元素往前放；即第i个(数组从0开始)开始向前i步放到第一个以此类推
	{
		arr[I - i]=arr[I] ;
	}
	int t = i;
	for (I = 0; I < t; I++)//I从开始只需要i次 即将tmp中存放的元素放回arr中
	{
		arr[strlen(arr) - i ] = tmp[I];//此处strlen(arr) - i 是为了当i>数组一半时仍可以正常，若为arr[i] = arr[I]的话如先前攒4个字符的话在abcdef中
										//将变成efabcd而会在从arr[4]处开始返回就不对了,应该从arr【2】即从arr[strlen...]处开始放回
		if(i>0) 
		i--;
	}
	printf("%s", arr);
	return 0;
}