// #define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int* p = &a;
//	printf("%p\n", p);//p指针指向a变量的地址
//	printf("%p\n", &a);
//	printf("%d\n", *p);//通过*解引用找到a，并且可以改变a
//	printf("%d\n", a);
//	*p = 20;
//	printf("%d\n", a);
//
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int* p = &a;
//	//printf("%u",sizeof(p));
//	printf("%zd", sizeof(p));
//
//
//	return 0;
//}


//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int a = 0x11223344;
//	char* p = (char*)&a;
//	for(int i = 0; i < 4 ; i++)
//	*p++ = 0;//同过后++让指针往前走
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int* p;//局部变量指针未初始化
//    *p = 20;
//    return 0;
//}

#include <stdio.h>
//int main()
//{
//    int arr[10] = { 0 };//范围0~9
//    int* p = arr;
//    int i = 0;
//    for (i = 0; i <= 12; i++)//此处已经指向了10 11
//    {
//        *p = i;
//        p++;
//    }
//    return 0;
//}
//int *  test()
//{
//	int a = 10;
//	return &a;
//}
//int main()
//{
//	int* p = test();
//	for(int i = 0; i < 2 ;i++)
//	printf("%d\n", *p);
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//    int* p = NULL;
//    //....
//    int a = 10;
//    p = &a;
//    if (p != NULL)
//    {
//        *p = 20;
//    }
//    return 0;
//}


//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	for (int i = 0; p < arr + 10; i++)
//	{
//		*p++ = i;
//		printf("%d", arr[i]);
//	}
//	return 0;
//}

//
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr + 9;
//	for (int i = 0; p >= arr; i++)
//	{
//		*p-- = i;
//		printf("%d", arr[i]);
//	}
//	return 0;
//}


//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%2d == %2d  ==  %2d\n", arr[i], *(p + i),*(arr+i));
//	}
//
//	return 0;
//}
int main()
{
	int a = 0;
	int* p = &a;//p中存放a的地址
	int** p1 = &p;//p1中存放p的地址
	//其用法也相同，*p找到a的地址空间，*p1找到p的地址空间也就是真正的p
	//而不是p的地址，再一次解应用即 * *p1 =  * p 就可以找到a
	return 0;
}