#define _CRT_SECURE_NO_WARNINGS 1
////////int main()
////////{
////////	int a = 10;
////////
////////	{
////////		
////////		printf("%d", a);
////////	}
////////	
////////
////////	return 0;
////////}
//////
//////#include<stdio.h>
//////int b = 20;
//////int main()
//////{
//////
//////	{
//////		int a = 0;
//////		printf("%d\n", a);//可打印出a
//////		printf("%d\n", b);// 在b的作用域内故可以打印
//////	}
//////	//printf("%d\n", a);//因为不在a变量所在的作用域内则无法打出a
//////	printf("%d\n", b); //在b的作用域内故可以打印
//////
//////		return 0;
//////}
#include<stdio.h>
int str(int x, int y)
{
	return(x > y ? x : y);
}

int main()

{

	int a = 10;

	int b = 20;

	printf("%d",str(a, b));

	return 0;

}
//#include<stdio.h>
//int main()
//{
//    int i = 0;
//    int b = 0;
//    int c = 0;
//
//    while (1)
//    {
//        if (c < 3)
//        {
//            scanf("%d %d", &i, &b);
//            break;
//        }
//        else
//        {
//            if (i > b)
//            {
//                printf("%d>%d\n", i, b);
//            }
//
//            else if (i == b)
//            {
//                printf("%d=%d\n", i, b);
//            }
//
//            else
//            {
//                printf("%d<%d\n", i, b);
//            }
//        }
//
//    }
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int a = 10;
//    int b = 20;
//    str(a,b)
//    return 0;
//}