#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<assert.h>
using namespace std;
class Stack
{
public:
	//成员函数
	//在类域中不管声明的位置都能找得到
	void Init(int DefaultCapacity = 4)
	{
		a = (int*)malloc(sizeof(int)* DefaultCapacity);
		if (a == nullptr)
		{
			perror("malloc");
			return;
		}
		capacity = DefaultCapacity;
		size = 0;
	}
	void Push(int x)
	{
		if (size == capacity)
		{
			int* ptr = (int*)realloc(a, sizeof(int)* capacity * 2);
			assert(ptr);
			a = ptr;
			capacity *= 2;
		}
		a[size++] = x;
	}

	int Top()
	{
		assert(size);
		return a[size - 1];
	}



	~Stack()
	{
		cout << "~Stack()" << endl;
		if (a)
		{
			free(a);
			a = NULL;
			capacity = 0;
			size = 0;
		}
	}
	//成员变量
private:
	int* a;
	int size;
	int capacity;
};


//typedef int DataType;
//class Stack
//{
//public:
//
//	void Push(DataType data)
//	{
//		CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	void Pop()
//	{
//		if (Empty())
//			return;
//		_size--;
//	}
//
//	DataType Top() { return _array[_size - 1]; }
//	int Empty() { return 0 == _size; }
//	int Size() { return _size; }
//
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		if (_array)
//		{
//			free(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//
//private:
//	void CheckCapacity()
//	{
//		if (_size == _capacity)
//		{
//			int newcapacity = _capacity * 2;
//			DataType* temp = (DataType*)realloc(_array, newcapacity * sizeof(DataType));
//			if (temp == NULL)
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

////写一个日期类的类
class Date
{
public:

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;

	Stack _sk;
};
int main()
{

	Date d1;
	d1.Print();
	return 0;
}


//typedef int DataType;
//class Stack
//{
//public:
//
//	void Push(DataType data)
//	{
//		CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	void Pop()
//	{
//		if (Empty())
//			return;
//		_size--;
//	}
//
//	DataType Top() { return _array[_size - 1]; }
//	int Empty() { return 0 == _size; }
//	int Size() { return _size; }
//
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		if (_array)
//		{
//			free(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//
//private:
//	void CheckCapacity()
//	{
//		if (_size == _capacity)
//		{
//			int newcapacity = _capacity * 2;
//			DataType* temp = (DataType*)realloc(_array, newcapacity * sizeof(DataType));
//			if (temp == NULL)
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
//
//
//class Date
//{
//public:
//	void Print()
//	{
//		int a = 0;
//	}
//private:
//
//	Stack _st;
//};
//
//
//int main()
//{
//	// 构造函数的调用跟普通函数也不一样
//	Date d1;
//	d1.Print();
//
//	return 0;
//}