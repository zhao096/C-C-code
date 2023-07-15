 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//#include<unistd.h>
#include<windows.h>
//#include<stdlib.h>
int main()
{
    int count = 10;

    while (count >= 0)
    {
        printf("%-2d\r", count--);//%-2d 对打印的整形进行右对齐并且每次打印两个字符
        fflush(stdout);//因为没有\n所以需要自行刷新缓冲区
        Sleep(1000);//休眠1s
    }
    return 0;
}

