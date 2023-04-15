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

//int main()
//{
//	int x = 10;
//	double d = 11.11;
//	cout << "hello world" << ' ' << endl;
//	cin >> x >> d;
//	cout << x << ' ' << d << endl;
//
//	return 0;
//}
//
//void fun(int a = 0)
//{
//    cout << a << endl;
//}
//
//int main()
//{
//    fun();//当没穿参数的时候用的是缺省参数也就是此时的0
//    fun(10);//而当传了个参数时，那么a就等于了10
//    return 0;
//}



void fun(int a, int b = 20, int c = 10 )
{
    cout << a << endl;
    cout << b << endl;
    cout << c << endl << endl;
} 

int main()
{

    fun();
    fun(3);
    fun(3, 2, 1);
    //fun(3, , 1);

    return 0;
}




