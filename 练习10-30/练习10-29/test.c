// #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//int main()
//{
//	char arr1[] = "bit";
//	char arr2[] = { 'b','i','t' };
//	char arr3[] = { 'b','i','t','\0'};
//	printf("%s %s %s\n%d %d %d", arr1, arr2, arr3, strlen(arr1), strlen(arr2),strlen(arr3));
//	int arr4[] = { 0 ,1};
//	int i = 0;
//	for (i = 0; i < 2; i++)
//	{
//		arr4[i] = 1;
//		printf("%d", arr4[i]);
//	}
//
//
//	;
//
//	return 0;
//}

//test.c

//extern int a;//声明另一个文件内的变量
//#include<stdio.h>
//int main()
//{
//    printf("%d", a);
//    return 0;
//}

//int main()
//{
//    int i = 0;
//    while(i < 3)
//    {
//        int a = 0;
//        a++;
//        printf("%d ", a);//此时打印不出
//        i++;
//    }
//
//    return 0;
//}
//
//
//
////int main()
////{
////    int i = 0;
////    while( i < 3)
////    {
////        static int a = 0;
////        a++;
////        printf("%d ", a);//因为static改变了局部变量的生命周期（变成了静态变量）故可以打印
////        i++;       
////      }
////   
////   
////    return 0;
////}


////test.c
//extern int Add(int , int );
//int main()
//{
//    printf("%d\n", Add(2, 3));
//    return 0;
//
//}
//#define M 3   //此处将M定义成了一个常量3，它还可以用到任何需要一个常数的地方，如数组..
//int main()
//{
//    int a = 4;
//    if (a > M)
//        printf("%d\n", a);
//    return 0;
//}
#define Add(x,y) (x +y)//定义的宏，与函数也类似，一般用来解决一些简单易写的步骤
#include<stdio.h>
int main()
{
    int a = 2;
    int b = 3;
    int c = Add(a, b);
    printf("%d\n", c);
    return 0;
}



