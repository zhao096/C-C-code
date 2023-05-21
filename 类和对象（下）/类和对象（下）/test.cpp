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

class A
{
public:
	explicit A(int a)
	{
	}
private:
	int _a;
};

int main()
{
	A a(3);//此处就是构造函数
	A a = 3;//而此处本应该是先进行隐式类型转换把int -> A 生成一个临时变量再进行（拷贝）构造
	//但其实编译器进行了优化，直接优化成了一步，只进行构造

	//为证明是存在隐式类型转换的：
	//A& a = 3;
	//上面标红是因为，转换出来的临时变量时具有常性的，所以对于引用来说需要用成cont A& 才能接收 常性的引用对象
	const A& a = 3;


	return 0;
}