 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<iostream>
using namespace std;
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	//c:
//	int* ptr1 = (int*)malloc(sizeof(int));
//	free(ptr1);
//
//	//c++:
//	int* ptr2 = new int;//此时和上面的申请的空间是一样的其大小也是一个整形的大小
//	delete ptr2;//释放也是一样
//
//	//c:
//	int* ptr3 = (int*)malloc(sizeof(int) * 10);
//	free(ptr3);
//
//	//c++:
//	int* ptr4 = new int[10];//此时和上面的申请的空间是一样的其大小也是一个整形的大小
//	delete[] ptr4;//释放也是一样
//
//	//c:
//	//malloc不会进行初始化，我们只能另写一个程序进行初始化
//
//	//c++:
//	//c++就能直接在申请空间的同时进行初始化工作
//	//具体如：
//	int* ptr5 = new int(10);//注意这里时圆括号 ， 和创建多个对象的方括号不一样
//	delete ptr5;
//
//	//对申请多个空间的也能进行初始化
//	int* ptr6 = new int[10]{};//用中括号进行初始化，什么都不写时表示申请的空间初始化为0
//	delete[] ptr6;
//
//	int* ptr7 = new int[10]{1,2,3};//部分初始化，剩下没写的初始化为0
//	delete[] ptr7;
//	return 0;
//
//	A* ptr8 = new A[3];//此处假如A类型没有默认构造的话是不行的，反之则可以
//	delete[] ptr8;
//
//	A* ptr9 = new A[3]{1,2,3};//支持隐式类型转换拷贝构造后在构造
//	delete[] ptr9;
//
//	A* ptr10 = new A[3]{ A(1),A(2),A(3) };//此时就没有隐式类型转换了，直接进行构造
//	delete[] ptr10;

//}
//
//class ListCode
//{
//public:
//	ListCode(int val = 0)
//		:val(val)
//		,next(nullptr)
//	{
//	}
//private:
//	int val;
//	struct ListCode* next;
//};
//int main()
//{
//	//在C语言数据结构中我们可能还需要去写一个ListCode()的创建节点的函数
//	//但此时我们可以直接写成如下模样
//
//	ListCode* n1 = new ListCode(1);//还进行了构造
//	ListCode* n2 = new ListCode(2);
//
//	return 0;
//}


//
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A()" << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* ptr1 = new A[3]{ 1,2,3 };
//	delete[] ptr1;
//	return 0;
//}



int main()
{
	int* ptr = nullptr;
	try
	{
		do
		{
			ptr = new int[1024 * 1024];
			cout << ptr << endl;
		} while (ptr);
	}
	catch (const exception& e )
	{
		cout << e.what() << endl;
	}
	return 0;
}