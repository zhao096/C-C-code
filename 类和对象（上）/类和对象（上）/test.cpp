 #define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include"Person.h"


using namespace std;

//struct Stack
//{
//	//成员函数
//	//在类域中不管声明的位置都能找得到
//	void Init(int DefaultCapacity = 4)
//	{
//		a = (int*)malloc(sizeof(int) * DefaultCapacity);
//		if (a == nullptr)
//		{
//			perror("malloc");
//			return;
//		}
//		capacity = DefaultCapacity;
//		size = 0;
//	}
//	void Push(int x)
//	{	
//		if (size == capacity)
//		{
//			int* ptr = (int*)realloc(a, sizeof(int) * capacity * 2);
//			assert(ptr);
//			a = ptr;
//			capacity *= 2;
//		}	
//		a[size++] = x;
//	}
//
//	int Top()
//	{
//		assert(size);
//		return a[size - 1];
//	}
//
//
//	void Destroy()
//	{
//		free(a);
//		a = nullptr;
//		capacity = size = 0;
//	}
//	//成员变量
//	int* a;
//	int size;
//	int capacity;
//};
//
//int main()
//{
//	//Stack sk;
//	//sk.Init(20); 
//	//sk.Push(1);
//	//sk.Push(2);
//	//sk.Push(3);
//	//cout << sk.Top() << endl;
//	//sk.Destroy();
//
//	//Person p;
//	//p.PersonInit();
//	//char a[] = "LiHua";
//	//p.ShowInfo(a);
//	//return 0;
//}


//class A
//{
//	void fun()
//	{
//	}
//};
//class B
//{
//};
//
//int main()
//{
//
//
//	cout << sizeof(A) << endl;
//	cout << sizeof(B) << endl;
//	return 0;
//}



//写一个日期类的类
class Date
{
public:
	void Init(int year = 1970, int month = 1, int day = 1)
	{
		_day = day;
		_month = month;
		_year = year;
	}
	void Print()
	{
		cout << _year << ' ' << _month << ' ' << _day << endl;
	}
private:
	int _day;
	int _month;
	int _year;
};


int main()
{
	Date d1;
	Date d2;
	d1.Init(2004, 9, 7);
	d2.Init(2003, 7, 7);
	d1.Print();
	d2.Print();

	return 0;
}