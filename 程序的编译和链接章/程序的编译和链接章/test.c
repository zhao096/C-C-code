 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//#define MAX 100
//
//int main() {
//	//printf("%s\n", __FILE__);
//	//printf("%s\n", __DATE__);
//	//printf("%s\n", __TIME__);
//	//printf("%d\n", __LINE__);
//	////printf("%s\n", __STDC__);
//
//
//	printf("%d", MAX);
//	return 0;
//}
#define ADD(a) a + a
//
//int main()
//{
//	int a = 5;
//	printf("%d\n", ADD(a));
//
//	return 0;
//}


//int main()
//{
//    printf("%d", ADD(3) * ADD(2));
//    return 0;
//}

//#define PRINT(format,x) printf("the value of "#x" is "format"\n",x)
//
//
//int main()
//{
//	int a = 10;
//	PRINT("%d", a);
//
//	float f = 20.22f; //加上f是因为20.22一般会被默认成double类型的加上了就会看成float类型)
//	PRINT("%f", f);
//	return 0;
//}


//int main()
//{
//	printf("abcdef\n");
//	printf("abc""def\n");
//	return 0;
//}
//
//

//#define joint(a,b) a##b
//
//int main()
//{
//	int AB = 100;
//	
//	printf("%s\n", joint(A, B));//最终传进去的参数会通过##拼接在一起
//	return 0;
//}

#define MAX(a,b) ((a)>(b)?(a):(b))

int main()
{
	int a = 3, b = 4;
#undef MAX
	int m = MAX(a++, b++);
	//((a++) > (b++) ? (a++) : (b++))
	//因为是a++ 、 b++ 所以先比较后++ 所以较大值4 ，然后：a = 4 b = 5；
	//(b++)再因为还要到后面的b++ b = 6
	printf("%d\n", m);
	printf("%d %d", a, b);

	return 0;
}




