 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//
//namespace ZYK
//{
//    int a = -1;//在命名空间的变量，就是命名空间域
//    namespace n
//    {
//        int a = 100;
//    }
//}
//int a = 1;
//
//int main()
//{
//    int a = 0;
//    printf("%d\n", ::a);
//    printf("%d\n", ZYK::a); 
//    printf("%d\n", a);
//
//    printf("%d\n", ZYK::n::a);
//
//    return 0;
//}

//namespace ZYK
//{
//    int a = -1;//在命名空间的变量，就是命名空间域
//
//}
//
//using namespace ZYK;
//
//int main()
//{
//    int a = 0;
//    printf("%d\n", ::a);
//    printf("%d\n", ZYK::a);
//    printf("%d\n", a);
//
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	cout << "hello world" << endl;
//	return 0;
//}


//#include<iostream>
//
//int main()
//{
//	std::cout << "hello world" << std::endl;
//	return 0;
//}

#include<iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int x = 10;
	double d = 11.11;
	cout << "hello world" << ' ' << endl;
	cin >> x >> d;
	cout << x << ' ' << d << endl;

	return 0;
}



