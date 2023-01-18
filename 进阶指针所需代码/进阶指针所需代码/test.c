 #define _CRT_SECURE_NO_WARNINGS 1
//int main()
//{
//	char arr[] = "abcedf";
//	arr = "czdsfa";
//
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//    char arr1[] = "abcdef";
//    char arr2[] = "abcdef";
//
//    const char* arr3 = "abcdef";
//    const char* arr4 = "abcdef";
//
//    if (arr1 == arr2)
//        printf("same\n");
//    else
//        printf("no same\n");
//
//    if (arr3 == arr4)
//        printf("same\n");
//    else
//        printf("no same\n");
//
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char* arr[4] = { "abcd","hehe","blog","nb" };//常量字符串产生的是其首元素的地址
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%s ", arr[i]);
//	}
//
//	return 0;
//}



#include<stdio.h>
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6};
//	int arr3[] = { 3,4,5,6,7 };
//	int arr4[] = { 4,5,6,7,8 };
//
//	int* arr[4] = { arr1,arr2,arr3,arr4 };
//
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//
//	printf("%p\n", &arr[0]);//首元素的地址
//
//	printf("%p\n", arr);//数组名
//
//	printf("%p\n", &arr);//整个数组的地址
//
//
//	return 0;
//}
	//int main()
	//{
	//	int arr[10] = { 0 };

	//	printf("%p\n", &arr[0]);//首元素的地址
	//	printf("%p\n", &arr[0]+1);//首元素的地址

	//	printf("%p\n", arr);//数组名
	//	printf("%p\n", arr+1);//数组名


	//	printf("%p\n", &arr);//整个数组的地址
	//	printf("%p\n", &arr+1);//整个数组的地址



	//	return 0;
	//}


//对于一维数组时
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*p)[10] = &arr;
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", (*p)[i]);//通过(*p)找到整个数组再通过下标引用找到对应
//	}
//
//	return 0;
//}

//void test(int(*p)[4], int r, int c)
//{
//	int i = 0;
//	for (i = 0 ;i < r; i++)
//	{
//		int j = 0; 
//		for (j = 0; j < c; j++)
//		{
//			printf("%d", (*(p + i))[j]);
//		}
//		printf("\n");
//	}
//
//}
//int main()
//{
//	int arr[3][4] = { {1,2,3,4},{2,3,4,5},{3,4,5,6} };
//	test(arr, 3, 4);
//}

////一维数组情况
//void test1(int arr[])//括号内加不加数组大小都行
//{
//	;
//}
//
//void test1(int* parr)
//{
//	;
//}
//
//
//void test2(int* arr2[])
//{
//	;
//}
//
//void test2(int** arr2)
//{
//
//	;
//}
//
//int main()
//{
//	int arr1[10] = { 0 };
//	int* arr2[10] = { 0 };
//	test1(arr1);
//	test2(arr2);
//	return 0;
//}
//
//

//
//void test(int **arr)
//{
//	;
//}
////void test(int(*p)[4])
////{
////
////	;
////}
//int main()
//{
//	int arr[3][4] = {0};
//	test(arr);
//	return 0;
//}

//void test(int* p)
//{
//	;//code
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7 };
//	int* p = arr;
//	test(p);
//	return 0;
//}

//void test(int** ptr)
//{
//	;//code
//} 
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7 };
//	int* p = arr;
//	int** pa = &p;
//	test(pa);
//	test(&p);
//	return 0;
//}

int Add(int x, int y)
{
	return x + y;
}

int main()
{
	int a = 3;
	int b = 2;
	Add(a, b);
	//函数指针 类型+ * + 变量名 = 函数的地址
	//此处Add的类型为 int (int , int)
	int (*ptr)(int, int) = &Add;
	//上下一样  即：&Add == Add
	int (*ptr)(int, int) = Add;//此处函数名和数组名类似都可以表示其地址

	
	
	int ret = Add(a, b);
	// 等于
	int ret1 = (*ptr)(a, b);
	// 等于 
	int ret2 = ptr(a, b);
	//即 Add(a,b) == (*ptr)(a,b) == ptr(a,b)


	return 0;
}




