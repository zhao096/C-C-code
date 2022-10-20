 #define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//    int a = 0;
//    int b = 0;
//    while (scanf("%d\n", &a) == 1)
//    {
//        if (a % 2 == 0)
//            printf("Even\n");
//        else
//            printf("Odd\n");
//
//
//    }
//
//    return 0;
//}
//#include<stdio.h>
//int main() {
//    int a = 0;
//    while (scanf("%d", &a) == 1) {
//        while (a) {
//            printf("*");
//            a--;
//        }
//        printf("\n");
//
//    }
//
//    return 0;
//}
//#include<stdio.h>
//int main() {
//    int a = 0;
//    scanf("%d", &a);
//    printf("0.5\n");
//
//    return 0;
//}
#include <stdio.h>
 
 
int main()
{
    int i = 0;
 
 
    //5¸öÑ§Éú
    for(i=0; i<5; i++)
    {
        float sum = 0;
        int j = 0;
        double score = 0; 
        for(j=0; j<5; j++)
        {
            scanf("%f", &score);
            sum += score;
            printf("%.2f ", score);
        }
        printf("%.2f\n", sum);
    }
    return 0;
}

