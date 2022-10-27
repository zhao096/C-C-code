 #define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 1; i * 3 < 100; i++)
//	{
//		printf("%d ", i * 3);
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int k = 0;
//
//	scanf("%d %d", &a, &b);
//	while (k = a % b)
//	{
//		a = b;
//		b = k;
//
//	}
//	printf("%d\n", b);
//
//
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//void play()
//{
//	int i = 0;
//	int k = rand() % 100 + 1;
//	printf("输入你要猜的数字：");
//
//	while (1)
//	{
//		scanf("%d", &i);
//		if (i < k)
//		{
//			printf("猜小了\n");
//		}
//		else if (i > k)
//		{
//			printf("猜大了\n");
//		}
//		else
//		{
//			printf("恭喜你猜对了\n");
//			break;
//		}
//		printf("输入你要猜的数字：");
//
//	}
//
//}
//
//void mune()
//{
//	printf("*******************\n");
//	printf("****   1.play  ****\n");
//	printf("****   0.exit  ****\n");
//	printf("*******************\n");
//
//}
//
//int main()
//{
//	int input = 0;
//	srand ((unsigned int)time(NULL));
//	do
//	{
//		mune();
//		printf("是否玩猜数字游戏:");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("猜数字游戏\n");
//			play();
//			break;
//		case 0:
//			printf("退出游戏");
//			break;
//		default:
//			printf("输入错误，请重新输入\n");
//		}
//	} while (input);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int k = n / 12;
//    int i = 0;
//    while (k)
//    {
//        i += 4;
//        k--;
//    }
//    printf("%d", i + 2);
//    return 0;
//}

#include <stdio.h>

int main()
{
    long a = 0;
    long n = 0;
    scanf("%ld", &n);
    long sum = 0;
    for (a = 1; a <= n; a++)
    {
        sum = sum + a;
    }
    printf("%ld\n", sum);
    return 0;
}
