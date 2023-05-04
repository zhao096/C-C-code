#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include<errno.h>
using namespace std;
typedef int DataType;

//
////写一个日期类的类
//	class Date 
//public:
//	//Date()
//	//{
//	//	_year = 1970;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//	//对于上面这个构造函数来说，他其实可以直接写成，下面这种带缺省值的就行了
//	Date(int year = 1970, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year = 0;
//	int _month = 0;
//	int _day = 0;
//
//	//Stack _sk;
//};
//

//
//
//
//int main()
//{
//	//Date d1();这种是错误的写法，会和函数声明其冲突
//	Date d1;//当不加括号是调用 Date()
//	Date d2(2023,4,25);
//	//d1.Print();
//	//d2.Print();
//
//
//	MyQueue queue;
//
//
//
//
//	return 0;
//}

//
//Date& Date::operator+=(int day)
//{
//	*this= *this + 100;
//	return *this;
//}

class Stack
{
public:

	void Push(DataType data)
	{
		checkcapacity();
		_array[_size] = data;
		_size++;
	}

	void Pop()
	{
		if (empty())
			return;
		_size--;
	}

	DataType top() { return _array[_size - 1]; }
	int empty() { return 0 == _size; }
	int size() { return _size; }

	Stack(int capacity = 4)
	{
		_array =(int *) malloc(sizeof(int*) * _capacity);
		if (_array == nullptr)
		{
			strerror(errno);
			return;
		}
		_capacity = capacity;
		_size = 0;
	}
	Stack(Stack& sk)
	{
		_array = (DataType*)malloc(sizeof(DataType) * _size);
		if (_array == nullptr)
		{
			strerror(errno);
			return;
		}
		memcpy(_array, sk._array, sizeof(DataType) * sk._size);

		_capacity = sk._capacity;
		_size = sk._size;
	}

	~Stack()
	{
		cout << "~stack()" << endl;
		if (_array)
		{
			free(_array);
			_array = nullptr;
			_capacity = _size = 0;
		}
	}

private:
	void checkcapacity()
	{
		if (_size == _capacity)
		{
			int newcapacity = _capacity * 2;
			DataType* temp = (DataType*)realloc(_array, newcapacity * sizeof(DataType));
			if (temp == nullptr)
			{
				perror("realloc申请空间失败!!!");
				return;
			}
			_array = temp;
			_capacity = newcapacity;
		}
	}
private:
	DataType* _array;
	int _capacity;
	int _size;
};

class MyQueue
{
	Stack pushsk;
	Stack popsk;
};

class Date 
{
public:
	Date()
	{
		_year = 1970;
		_month = 1;
		_day = 1;
	}
	//对于上面这个构造函数来说，他其实可以直接写成，下面这种带缺省值的就行了
	Date(int year = 1970, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//拷贝构造 、 构造函数的重载
	Date(const Date & d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year = 0;
	int _month = 0;
	int _day = 0;
};



int main()
{
	Date d1(2023, 5, 4);
	Date d2(d1);

	MyQueue q1;
	//若对Stack不写成深拷贝就会导致，他们申请的空间被重复释放两次而报错
	MyQueue q2(q1);



	return 0;
}



