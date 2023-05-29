 #define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    void print_s();
    print_s();
    return 0;
}
void print_s()
{
    int i, a[12];
    printf("ÊäÈë×ÖÄ¸:\n");
    for (i = 0; i < 12; i++)
        scanf("%C", &a[i]);
    printf("\n");
    for (i = 11; i >= 0; i--)
    {
        printf("%C", a[i]);
    }
    printf("\n");
}