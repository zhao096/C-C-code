#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<assert.h>
using namespace std;
typedef int DataType;
class Stack
{
public:

	void Push(DataType data)
	{
		CheckCapacity();
		_array[_size] = data;
		_size++;
	}

	void Pop()
	{
		if (Empty())
			return;
		_size--;
	}

	DataType Top() { return _array[_size - 1]; }
	int Empty() { return 0 == _size; }
	int Size() { return _size; }


	~Stack()
	{
		cout << "~Stack()" << endl;
		if (_array)
		{
			free(_array);
			_array = NULL;
			_capacity = 0;
			_size = 0;
		}
	}

private:
	void CheckCapacity()
	{
		if (_size == _capacity)
		{
			int newcapacity = _capacity * 2;
			DataType* temp = (DataType*)realloc(_array, newcapacity * sizeof(DataType));
			if (temp == NULL)
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

//写一个日期类的类
class Date
{
public:
	//Date()
	//{
	//	_year = 1970;
	//	_month = 1;
	//	_day = 1;
	//}
	//对于上面这个构造函数来说，他其实可以直接写成，下面这种带缺省值的就行了
	Date(int year = 1970, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year = 0;
	int _month = 0;
	int _day = 0;

	//Stack _sk;
};
int main()
{
	//Date d1();这种是错误的写法，会和函数声明其冲突
	Date d1;//当不加括号是调用 Date()
	Date d2(2023,4,25);
	d1.Print();
	d2.Print();
	return 0;
}


Date& Date::operator+=(int day)
{
	*this= *this + 100;
	return *this;
}
