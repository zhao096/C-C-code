 #define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//union Un
//{
//	short s[7];
//	int n;
//};
//int main()
//{
//	printf("%d\n", sizeof(union Un));
//	return 0;
//}
//#include<stdio.h>
//int main()
//
//{
//	enum ENUM_A
//{
//	X1,
//	Y1,
//	Z1 = 255,
//	A1,
//	B1,
//};
//enum ENUM_A enumA = Y1;
//enum ENUM_A enumB = B1;
//printf("%d %d\n", enumA, enumB);
//return 0;
//}




//int main()
//{
//	void GetMemory(char* p)
//	{
//		p = (char*)malloc(100);
//	}
//	void Test(void)
//	{
//		char* str = NULL;
//		GetMemory(str);
//		strcpy(str, "hello world");
//		printf(str);
//	}
//}

//B.上面代码存在内存泄露
//C.上面代码可能会崩溃，即使GetMemory函数返回，str依然为NULL
//D.GetMemory函数无法把malloc开辟的100个字节带回来
#include<stdio.h>
int main()
{
    union
    {
        short k;
        char i[2];
    }*s, a;
    s = &a;
    s->i[0] = 0x39;
    s->i[1] = 0x38;
    printf(" % x\n", a.k);
    return 0;
}