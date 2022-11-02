 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 0;
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		printf("星期一\n");
	case 2:
		printf("星期二\n");
	case 3:
		printf("星期三\n");
	case 4:
		printf("星期四\n");
	case 5:
		printf("星期五\n");
	case 6:
		printf("星期六\n");
	case 7:
		printf("星期日\n");
	default:
		printf(",");
	}
	return 0;
}

//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	switch (a)
//	{
//	default:
//		printf("输入错误\n");
//		break;
//	case 1:
//		printf("星期一\n");
//		break;
//	case 2:
//		printf("星期二\n");
//		break;
//	case 3:
//		printf("星期三\n");
//		break;
//	case 4:
//		printf("星期四\n");
//		break;
//	case 5:
//		printf("星期五\n");
//		break;
//	case 6:
//		printf("星期六\n");
//		break;
//	case 7:
//		printf("星期日\n");
//		break;
//	}
//	return 0;
//}