 #define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std; 
typedef int DataType;

//
//class B {
//public:
//	/*B()
//	{
//		_a = 1;
//	}*/
//
//	B(int a)
//		:_a(a)
//	{
//		_a = a;
//	}
//private:
//	int _a;
//};
//
//class A
//{
//public:
//	A(int& a, int i)
//		//而对于成员的初始化是在初始化列表处完成的
//		:_a(a)
//		, _i(1)
//		,bb(10)//此时因为没有默认构造，所以我们只能去调用构造函数，所以需要我们使用初始化列表来进行传参
//		,a()//内置类型
//	{
//	}
//private:
//	//对于引用和常变量来说他们必须在定义的时候进行初始化，否则就无法使用
//	int& _a;
//	const int _i;
//	//而对于自定义结构来说，也是通过初始化列表来进行初始化的
//	B bb;
//
//	//内置类型的缺省值，其实就是给初始化列表的
//	int a = 1;
//};
//
//
//class Stack
//{
//public:
//
//	void Push(DataType data)
//	{
//		checkcapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	void Pop()
//	{
//		if (empty())
//			return;
//		_size--;
//	}
//
//	DataType top() { return _array[_size - 1]; }
//	int empty() { return 0 == _size; }
//	int size() { return _size; }
//
//	Stack(int capacity = 4)
//	{
//		_array = (int*)malloc(sizeof(int*) * _capacity);
//		if (_array == nullptr)
//		{
//			strerror(errno);
//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//	Stack(const Stack& sk)
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * _size);
//		if (_array == nullptr)
//		{
//			strerror(errno);
//			return;
//		}
//		memcpy(_array, sk._array, sizeof(DataType) * sk._size);
//
//		_capacity = sk._capacity;
//		_size = sk._size;
//	}
//
//	~Stack()
//	{
//		cout << "~stack()" << endl;
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = _size = 0;
//		}
//	}
//
//private:
//	void checkcapacity()
//	{
//		if (_size == _capacity)
//		{
//			int newcapacity = _capacity * 2;
//			DataType* temp = (DataType*)realloc(_array, newcapacity * sizeof(DataType));
//			if (temp == nullptr)
//			{
//				perror("realloc申请空间失败!!!");
//				return;
//			}
//			_array = temp;
//			_capacity = newcapacity;
//		}
//	}
//private:
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//
//class MyQueue
//{
//public :
//	MyQueue()
//		:pushsk(10)
//		,popsk(4)
//	{}
//
//private:
//	Stack pushsk;
//	Stack popsk;
//};
//
//
//int main()
//{
//	int n = 0;
//	A(n,10);
//
//	return 0;
//}
//
//class A
//{
//public:
//	explicit A(int a)
//	{
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A a(3);//此处就是构造函数
//	A a = 3;//而此处本应该是先进行隐式类型转换把int -> A 生成一个临时变量再进行（拷贝）构造
//	//但其实编译器进行了优化，直接优化成了一步，只进行构造
//
//	//为证明是存在隐式类型转换的：
//	//A& a = 3;
//	//上面标红是因为，转换出来的临时变量时具有常性的，所以对于引用来说需要用成cont A& 才能接收 常性的引用对象
//	const A& a = 3;
//
//
//	return 0;
//}

//
//class A
//{
//public:
//	A(int a)
//	{
//		_a = a;
//	}
//	static int GetB()//一般我们会把这个定义成静态的函数，此时是没有this指针的，指定类域和访问限定符就能进行访问该函数
//	{
//		A();
//		return _b;
//	}
//private:
//	int _a;
//	static int _b;
//};
//int A::_b = 10;
//
//int main()
//{
//	A a(1);
//	cout << a.GetB() << endl;
//	cout << A::GetB() << endl;
//	return 0;
//}


//class A {
//public:
//	static A GetStack()
//	{
//		A a;
//		return a;//返回创建的对象
//	}
//	static A* GetHeap()
//	{
//		return new A;//new一个空间给A
//	}
//
//private:
//	A()
//	{}
//
//private:
//	int _a = 0;
//	int _b = 1;
//};
//
//int main()
//{
//	//此时没有别的办法就只能用静态函数
//	//因为构造函数也属于私有的,所以我们不能直接定义一个对象
//	A::GetStack();
//	A::GetHeap();
//	return 0;
//}




//class A {
//public:
//
//	class B {//此时的B就是A的一个内部类，并且内部类时外部类的友元，可以使用外部类的变量
//	public:
//		B()
//		{
//		}
//		void Print(const A& a)//注意也并不是直接就能使用其成员变量，还是需要先实例化一个对象的
//		{
//			cout << a._a << a._b << endl; 
//		}
//	private:
//
//	};
//
//private:
//	int _a;//
//	int _b;
//
//};
//
//int main()
//{
//	A a;
//	A::B b;//当是public 时就能在外部定义了
//	return 0;
//}	

//class A {
//public:
//
//	class B {//此时的B就是A的一个内部类，并且内部类时外部类的友元，可以使用外部类的变量
//	public:
//		B()
//		{
//		}
//		void Print()
//		{
//			cout << _a <<_b << endl;//此处对于静态成员来说直接通过A::xxx 就能访问，所以对在A类内的B就能直接使用静态的
//		}
//	private:
//
//	};
//
//private:
//	static int _a;
//	static int _b;
//};
//
//int main()
//{
//	A a;
//	A::B b;//当是public 时就能在外部定义了
//	return 0;
//}

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};
class Solution {
public:
	int Sum_Solution(int n) {
		cout << "Sum_Solution" << endl;
		return n;
	}
};
int main()
{
	//A aa1;//正常的构造
	//A();//匿名对象，生命周期在本行

	//A aa2(2);//正常的构造
	Solution().Sum_Solution(10);//匿名对象调用其函数，并且此处并不会调用构造函数

	//const A& ra = A();//注意匿名对象具有常性，所以需要在引用前面+const
	//A aa3(3);//正常的构造

	//A a;
	//a = 3;
	//cout << "--------" << endl;
	//A a1 = 4;
	
	return 0;
}