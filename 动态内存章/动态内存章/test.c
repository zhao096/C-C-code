 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

//int main()
//{
//    //当你要开辟多个以整型大小为基础的空间时
//
//    int* ptr = (int*)malloc(sizeof(int) * 10);//当然你也可以直接在（）内写成“40”byte
//
//    //对于上面因为你需要开辟的是整形个大小的空间所以最后将返回的指针强转成整形指针类型
//    //并且ptr也要是整形指针这是你所要用的，你甚至可以把它想像成开辟了一个大小为10的整形数组
//    if (ptr == NULL)
//    {
//        printf("%s\n", strerror(errno));//打印错误
//        //perror("ptr");//打印错误
//        return 0;
//    }
//	return 0;
//}


//int main()
//{
//    //当你要开辟多个以整型大小为基础的空间时
//
//    int* ptr = (int*)malloc(40);
//    if (ptr == NULL)
//    {
//        perror("ptr");//打印错误
//        return 0;
//    }
//    for (int i = 0; i < 10; i++)
//    {
//        //*(ptr + i) = i + 1;
//        printf("%d\n", *(ptr + i));
//
//    }
//    free(ptr);
//    ptr = NULL;
//    return 0;
//}

//
//int main()
//{
//	int* p = (int*)malloc(sizeof(int) * 5);
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		*(p + i) = i + 1;
//		printf("%d ", *(p + i));
//	}
//	
//	int* ptr = (int *)realloc(p, sizeof(int) * 10);
//	if(ptr != NULL)
//	{
//		p = ptr;
//		ptr = NULL;//后面的ptr不在用了，避免野指针 
//	}
//
//	for (int i = 5; i < 10; i++)
//	{
//		*(p + i) = i + 1;
//		printf("%d ", *(p + i));
//	}
//
//	free(p);
//	p = NULL;
//	return 0;
//}




//int main()
//{
//    int* p = (int*)calloc(10, sizeof(int));
//    if (p == NULL)
//    {
//        perror("p");
//        return 0;
//    }
//
//    for (int i = 0; i < 10; i++)
//    {
//        printf("%d ", *(p + i));
//
//    }
//
//    free(p);
//    p = NULL;
//    return 0;
//}


//int main()
//{
//	int* ptr = (int*)malloc(40);
//	if (ptr == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		*(ptr + i) = i + 1;
//		printf("%d ", *(ptr + i));
//	}
//	return 0;
//}

//int main()
//{
//	int* ptr = (int*)malloc(100);
//	if (ptr == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//
//	for (int i = 0; i < 100; i++)
//	{
//		ptr[i] = 0;
//	}
//	return 0;
//}

//
//int main()
//{
//	int* p = (int*)malloc(100);
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	for (int i = 0; i < 25; i++)
//	{
//		*p = i;
//		printf("%d ", *p);
//		p++;
//
//	}
//	free(p);
//	p = NULL;
//
//	return 0;
//}

//int main()
//{
//    int a = 0;//正常开辟的变量存在栈区上 
//    int* p = &a;
//
//    free(p);
//    p = NULL;
//    return 0;
//}

//int main()
//{
//	int* p = (int*)malloc(100);
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	// 使用...
//	 
//	//释放
//	free(p);
//
//	// ...
//
//	free(p);
//	return 0;
//}
//
//void test()
//{
//	int* p = (int*)malloc(100);
//			
//}
//
//int main()
//{
//	test();
//
//	return 0;
//}


////该函数进行了malloc开辟空间，返回开辟空间的起始地址
////记得后面要释放
//int * test()
//{
//	int* p = (int*)malloc(100);
//	if (p == NULL)
//	{
//		perror("malloc");
//		return;
//	}
//	return p;
//}
//
//int main()
//{
//	int * ptr = test();
//	free(ptr);
//	ptr = NULL;
//	return 0;
//}

//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);//此处为传值调用，就会导致p起始只是str的零时拷贝并不会改变str，所以并没有开辟好空间，仍然为NULL
//	strcpy(str, "hello world");//因为str仍然为NULL所以就会有非法访问问题(访问了NULL地址)
//	printf(str);
//}
////并且因为p开辟了一个空间且后面也并没有free，也会导致内存泄漏
//int main()
//{
//	Test();
//	return 0;
//}

struct s
{
	int a;
	char b;
	char arr[];//柔性数组成员
	//char arr[0];写0或者不写0是一样的，数组的大小是未知的，

};


struct s1
{
	int a;
	char b;
	char *p;
};

int main()
{
	struct s *ptr = (struct s*)malloc(sizeof(struct s) + sizeof(char) * 10);//后面开辟的10个char的空间是柔性数组所需的空间
	//再通过ptr来访问结构体
	printf("%d\n", sizeof(struct s));

	free(ptr);
	ptr = NULL;

	struct s1* ps = (struct s1*)malloc(sizeof(struct  s1));
	ps->a = 100;
	ps->b = 'a';

	ps->p = malloc(10 * sizeof(char));
	if (ps->p == NULL)
	{
		perror("malloc");
		return 1;
	}
	
	//使用  ....
	//释放
	free(ps->p);
	ps->p = NULL;


	return 0;
}