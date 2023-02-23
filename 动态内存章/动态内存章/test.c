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


int main()
{
	int* p = (int*)malloc(sizeof(int) * 5);
	if (p == NULL)
	{
		perror("malloc");
		return 1;
	}
	for (int i = 0; i < 5; i++)
	{
		*(p + i) = i + 1;
		printf("%d ", *(p + i));
	}
	
	realloc(p, sizeof(int) * 10);

	for (int i = 5; i < 10; i++)
	{
		*(p + i) = i + 1;
		printf("%d ", *(p + i));
	}

	free(p);
	p = NULL;
	return 0;
}




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