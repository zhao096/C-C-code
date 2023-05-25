 #define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//template<class T>和下面的是效果一样的，并且内部的Ty是和变量名一样可以自行diy的
//template<typename T>
//void Swap(T& x, T& y) {
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//
//template<class T1,typename T2>
//void Func(T1& x, T2& y)//此处定义了两个模板参数，就能对应对当两个类型不同的情况
//{
//	cout << x << ' ' << y << endl;
//}
//
//int main()
//{
//	int a = 0 , b = 1;
//	double c = 1.1, d = 2.2;
//	Swap(a, b);
//	Swap(c, d);
//
//
//	int e = 10;
//	double f = 10.4;
//	Func(e, f);
//
//	return 0;
//}

//template<typename T>
//T* Alloc(int n)
//{
//	return new T[n];
//}
//
//int main()
//{
//	int* ptr = Alloc<int>(10);//此时的<int>就是一个显示的实例化，直接给这个函数的模板参数定义了类型int
//	return 0;
//}
template<typename T>
class Stack
{
public:
	Stack(int capacity = 4)
	{
		_arr = new T[capacity];
		int _size = 0;
		int _capacity = capacity;
	}

	void Push(const T& x);


	~Stack()
	{
		delete _arr;
		_size = 0;
		_capacity = 0;
	}

private:
	T* _arr;
	int _size;
	int _capacity;
};

template<typename T>
void Stack<T>::Push(const T& x)//此时我们定义全局函数时，需要我们指定类域才能使用其内部的成员
//而对于函数模板来说，此时的类型也该变成 Stack<模板参数>
{
	//CheckCapacity()
	_arr[_size] = x;
	_size++;
}

int main()
{
	Stack<int> st1;//显示实例化，此处必须加上这个显示...
	Stack<double> st2;//double

	//这样写我们就不用像cyy那样需要去改变 TypeDate 了
	//并且，可以同时使用多种类型的栈
	//C语言不能同时拥有，因为C语言的TypeDate只能在一处使用，就导致定死后不能用于
	//另外一处新的类型的对象中，而模板就能突破这个界限，创建多个类型不同功能一样的函数
	return 0;
}