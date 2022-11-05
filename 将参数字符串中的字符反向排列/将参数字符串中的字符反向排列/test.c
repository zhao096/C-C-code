 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//char reverse_string(char arr[],int i,int b)//注意传数组时要用数组接否则无法在函数内部改变数组的内容
//{
//	if (i >= b)
//	{
//		return 0;
//	}
//	else
//	{
//		int tmp = arr[i];
//		arr[i] = arr[b];  //交换
//		arr[b] = tmp;
//		return reverse_string(arr, i + 1, b - 1);
//	}
//
//}
//int main()
//{
//	//char arr[] = "abcdef";
//	char arr[] = { 'a','b','c','d','e','f','\0'};
//	int i = 0;
//	int b = sizeof(arr) / sizeof(arr[0]) -2; //sizeof(arr)内有7个字符（\0）也就说arr的空间为70 / 10 = 7 ,故还需要-2才能确保为小标5
//	//int b = strlen(arr);
//	reverse_string(arr,i,b);
//	for (i = 0; i <= b; i++)
//	{
//		printf("%c", arr[i]);
//	}
//	return 0;
//}

int Strlen(char* string)
{
	int count = 0;
	while(*string != '\0')
	{
		count++;
		string++;
	}
	return count;

}


char reverse_string(char * string)//传来地址，用指针接收。注：实际上形参都是地址
{
	int num = Strlen(string);
	char tmp = *string;
	*string = *(string + num - 1);
	
	*(string + num - 1) = '\0';//为了下面递归可以继续正常进行，即使下一次的递归中Strlen为最后一个字符
	if (Strlen(string + 1) >= 2)
		reverse_string(string+1);


	*(string + num - 1) = tmp;//放在后面为了前面53行的代码改回来
}
int main()
{
	//char arr[] = "abcdef";
	char arr[] = { 'a','b','c','d','e','f','\0' };
	int i = 0;
	reverse_string(arr);
	for (i = 0; i <= 6; i++)
	{
		printf("%c", arr[i]);
	}
	return 0;
}