 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    int i = 0;
    int j = 1;
    for (i = 0; i < 10; i++)
    {
        for(; j <= i; j++  )
        {
          printf("%d * %d",i , j);
        }
        printf("\n");
    }

    return 0;
}?