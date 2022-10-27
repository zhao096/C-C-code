 #define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
    int r = 0;
    double a = 0;
    scanf("%d", &r);
    a = (r * r * r) * 3.14 * 4 / 3;
    printf("%.2lf", a);
    return 0;
}