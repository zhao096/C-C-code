 #define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()
//{
//	int a, b, c;
//	a = 5;
//	c = ++a;//6,    注意:++a会改变a
//	b = (++c, c++, ++a, a++);//b = 7,c = 8,a = 8,  
//	b += a++ + c; //a = 9,b = 7 + 7 + 9 = 23
//	printf("a = %d b = %d c = %d\n:", a, b, c);//9 ,23 ,8
//	return 0;
//}

//int main()
//{
//	int a = 3;
//	int b = 5;
//	printf("%d %d\n", a, b);
//
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("%d %d", a, b);
//	return 0;
//}

////int main()
//{
//	int a = 3;
//	int b = 5;
//	printf("%d %d\n", a, b);
//
//	a = a ^ b;
//	b = a ^ b;//b = a ^ b ^ b ,而b ^ b == 0 , a ^ 0 == a;故 b == a;
//	a = a ^ b;// a = a ^ b ^ a  ,同理相同的按位异或为0，自己和0按位异或为本身
//
//	printf("%d %d", a, b);
//	return 0;
//}

//
//int NumberOf1_low(int n)
//{
//	int count = 0;
//	int flag = 1;
//	while (flag != 0)//当flag == 0 时说明已经左移动了32次测完了n的二进制序列
//	{
//		if(n & flag)//n & flag “&”一假则假,一位一位的测，若有1则为真进入，否则为0不进
//		count++;
//		flag <<= 1; //测每一位
//	}
//	return count;
//
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int k = NumberOf1_low(n);
//	printf("%d", k);
//	return 0;
//}
//int NumberOf1_low(int n)
//{
//	int count = 0;
//	int flag = 1;
//	while (flag != 0)
//	{
//		if ((n & flag) != 0)//注这里后面可不是1，他会越来愈大
//		{
//			count++;
//		}
//		flag <<= 1;
//	}
//	return count;
//}
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int k = NumberOf1_low(n);
//	n = 32 - k;
//	for (; k > 0; k--)
//	{
//		printf("%d", 1);
//
//	}
//	printf("\n");
//	for (; n > 0; n--)
//	{
//		printf("%d", 0);
//
//	}
//	return 0;
//}


N




