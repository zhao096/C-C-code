 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;
//	printf(" %d %d", a + b, c);
//	return 0;
//}

//int main()
//{
//	unsigned int a = 0x1234;
//	unsigned char b = *(unsigned char*)&a;
//	
//	return 0;
//}

int main()
{
    char a[1000] = { 0 };
    int i = 0;
    for (i = 0; i < 1000; i++)
    {
        a[i] = -1 - i;
    }
    printf("%d", strlen(a));//a的类型是char所以a的数值范围是在-128~127
    //a从-1开始 ... -128 127 ... 1 0  其中'\0'的ASCII值 == 0所以到0时就会停止即
    //strlen遇到\0就会停 ,所以从-1 ~ 1共有128+127 = 255长度
    return 0;
}