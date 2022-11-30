#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int n = 2;
//	scanf("%d", &n);
//	int t = 1;
//	int count = 0;
//	while(t)
//	{
//		if ((n & t) != 0)
//		{
//			count++;
//		}
//		t <<= 1;
//	}
//	printf("%d", count);
//	return 0;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int count = 0;
//	while (n)
//	{
//		n = n & n - 1;
//			count++;
//	}
//	printf("%d", count);
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int count = 0;
//	while(n)
//	{
//		if (n % 2 == 1)
//		{
//			count++;
//		}
//		n /= 2;
//	}
//		printf("%d", count);
//
//	return 0;
//}
//#include <stdio.h>
//struct Stu
//{
//    char name[10];
//    int age;
//    char sex[5];
//    double score;
//};
//void set_age2(struct Stu* pStu)
//{
//    (*pStu).age = 18;//其简易方法如下 //此处用法不和数组一样要将*放外面*(arr+i),而是要放在里面
//    pStu->age = 18;//结构成员访问
//}
//int main()
//{
//    struct Stu stu;
///*    struct Stu* pStu = &stu;*///结构成员访问
//
//    stu.age = 20;//结构成员访问
//    //set_age1(stu);
//
///*    pStu->age = 20;*///结构成员访问
//    set_age2(&stu);
//    return 0;
//}

int main()
{
	int a = 0;
	int b = 10;
	int c = a + b;
	return 0;
}


