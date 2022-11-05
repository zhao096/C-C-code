 #define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    char str[] = "hello bit";
    printf("%d %d\n", sizeof(str), strlen(str));
    return 0;
}