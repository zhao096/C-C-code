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


//int numberof1_low(int n)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32;i++ )//当flag == 0 时说明已经左移动了32次测完了n的二进制序列
//	{
//		if(((n >> i) & 1 )== 1)//n & flag “&”一假则假,一位一位的测，若有1则为真进入，否则为0不进
//		count++;
//	}
//	return count;
//
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int k = numberof1_low(n);
//	printf("%d", k);
//	return 0;
//}
//
void print(int n)
{
	printf("偶数数位:");
	for (int i = 30; i >= 0 ; i-=2)
	{
		printf("%d", (n >> i) & 1);
	}
	printf("\n");
	printf("奇数数位:");
	for (int i = 31; i >= 1; i -= 2)
	{
		printf("%d", (n >> i) & 1);
	}
}


int main()
{
	int n = 0;
	scanf("%d", &n);
	print(n);
	
	return 0;
}

//int NumberOf1_low(unsigned int n)//把-1看成一个32个1的二进制
//{
//	int count = 0;
//	while (n)
//	{
//		if (n % 2 == 1)//
//			count++;
//		n = n / 2;
//	}
//	return count;
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
//int numberof1_low(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n & (n - 1);//取走末尾的一个1，当全部取完将变成0
//		count++;
//	}
//	return count;
//
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int k = numberof1_low(n);
//	printf("%d", k);
//	return 0;
//}






