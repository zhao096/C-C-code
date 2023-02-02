 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	//一维数组
	//int a[] = { 1,2,3,4 };
	//printf("%d\n", sizeof(a));
	//printf("%d\n", sizeof(a + 0));
	//printf("%d\n", sizeof(*a));
	//printf("%d\n", sizeof(a + 1));
	//printf("%d\n", sizeof(a[1]));
	//printf("%d\n", sizeof(&a));
	//printf("%d\n", sizeof(*&a));
	//printf("%d\n", sizeof(&a + 1));
	//printf("%d\n", sizeof(&a[0]));
	//printf("%d\n", sizeof(&a[0] + 1));
	
	
	//字符数组
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", sizeof(arr));
	//sizeof只看类型：sizeof(char [6]) --> 1 * 6 = 6 byte
	printf("%d\n", sizeof(arr + 0));
	//数组名+1 -> 首元素地址+1 -》第二个元素的地址  -》 4/8
	printf("%d\n", sizeof(*arr));
	//对首元素地址解应用得到首元素其类型是char -》 sizeof(char) --》 1byte
	printf("%d\n", sizeof(arr[1]));
	//同理得到下标为1的元素 -》 其类型是 char -》 1byte
	printf("%d\n", sizeof(&arr));
	//取到整个数组的地址，是地址大小为 4/8
	printf("%d\n", sizeof(&arr + 1));
	//地址+1 仍是地址 -》 4/8
	printf("%d\n", sizeof(&arr[0] + 1));
	//取到首元素的地址 再 + 1 就是第二个元素的地址 -》 4/8
	
	printf("%d\n", strlen(arr));
	//因为arr内没有\0所以并不会停止，所以最终将产生一个 随机值
	printf("%d\n", strlen(arr + 0));
	////同上arr + 0 首元素地址 + 0 仍然为首元素地址
	
	//printf("%d\n", strlen(*arr));
	////对首元素地址解应用得到首元素，但是strlen需要传进去一个地址，所以将会报错因为将
	////'a'的ASCII码值传进去系统认为你要访问地址为97的地址，这非法访问了 最终将会报错
	
	//printf("%d\n", strlen(arr[1]));
	// 
	//同理此处将要非法访问 'b'-> 98 处的地址 会报错
	
	printf("%d\n", strlen(&arr));
	//传进去整个数组的地址，同样无法找到\0而自动停止所以一样是随机值
	printf("%d\n", strlen(&arr + 1));
	//+1也是同理找不到\0
	printf("%d\n", strlen(&arr[0] + 1));
	//首元素地址+1 第二个元素的地址，同样的找不到


	//char arr[] = "abcdef";
	//printf("%d\n", sizeof(arr));
	//printf("%d\n", sizeof(arr + 0));
	//printf("%d\n", sizeof(*arr));
	//printf("%d\n", sizeof(arr[1]));
	//printf("%d\n", sizeof(&arr));
	//printf("%d\n", sizeof(&arr + 1));
	//printf("%d\n", sizeof(&arr[0] + 1));

	//printf("%d\n", strlen(arr));
	//printf("%d\n", strlen(arr + 0));
	//printf("%d\n", strlen(*arr));
	//printf("%d\n", strlen(arr[1]));
	//printf("%d\n", strlen(&arr));
	//printf("%d\n", strlen(&arr + 1));
	//printf("%d\n", strlen(&arr[0] + 1));

	//char* p = "abcdef";
	//printf("%d\n", sizeof(p));
	//printf("%d\n", sizeof(p + 1));
	//printf("%d\n", sizeof(*p));
	//printf("%d\n", sizeof(p[0]));
	//printf("%d\n", sizeof(&p));
	//printf("%d\n", sizeof(&p + 1));
	//printf("%d\n", sizeof(&p[0] + 1));


	//printf("%d\n", strlen(p));
	//printf("%d\n", strlen(p + 1));
	//printf("%d\n", strlen(*p));
	//printf("%d\n", strlen(p[0]));
	//printf("%d\n", strlen(&p));
	//printf("%d\n", strlen(&p + 1));
	//printf("%d\n", strlen(&p[0] + 1));

	////二维数组
	//int a[3][4] = { 0 };
	//printf("%d\n", sizeof(a));
	//printf("%d\n", sizeof(a[0][0]));
	//printf("%d\n", sizeof(a[0]));
	//printf("%d\n", sizeof(a[0] + 1));
	//printf("%d\n", sizeof(*(a[0] + 1)));
	//printf("%d\n", sizeof(a + 1));
	//printf("%d\n", sizeof(*(a + 1)));
	//printf("%d\n", sizeof(&a[0] + 1));
	//printf("%d\n", sizeof(*(&a[0] + 1)));
	//printf("%d\n", sizeof(*a));
	//printf("%d\n", sizeof(a[3]));
	//

	return 0;
}