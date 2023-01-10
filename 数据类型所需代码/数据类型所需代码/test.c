#define _CRT_SECURE_NO_WARNINGS 1
////int main()
////{
////	int a = 20;
////	int b = -10;
////	return 0;
////}
#include<stdio.h>
////int check_sys()
////{
////	int a = 1;//其在补码(十六进制)为:00 00 00 01 、此时我们只要判断他在内存中的低地址处存的是高位(0)还是低位(1)即可
////	char* pa = (char*)&a;//通过字符指针访问整形在内存中的第一个字节的值是什么
////	if (*pa == 1)
////	{
////		return 1;
////	}
////	else
////		return 0;
////}
//int check_sys()
//{
//	int a = 1;//其在补码(十六进制)为:00 00 00 01 、此时我们只要判断他在内存中的低地址处存的是高位(0)还是低位(1)即可
//	//通过字符指针访问整形在内存中的第一个字节的值是什么
//	
//	return *(char*)&a;
//	
//}
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端");
//	}
//	return 0;
//
//}
//int main()
//{
//	char a = -1;
//	unsigned char b = -1;
//	signed char c = -1;
//	printf("%d %d %d", a, b, c);
//	return 0;
//}
int main()
{
    float a = 5.5f;
    //  101.1
    // s = 0 ; m = 1.011 ; e = 2
    // s直接存 ； e加上127(2+127 == 129) ；先去掉1. 再将011存进后面剩余的补0
    // 0 1000 0001 011 0000000000 0000000000
    // 0100 0000 1011 0000 0000 0000 0000 0000
    // 40     b0   00    00
    //vs是小端即为 00 00 b0 40
    return 0;
}