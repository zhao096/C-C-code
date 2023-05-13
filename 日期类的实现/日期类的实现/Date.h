#pragma once
#include<iostream>
using namespace std;
#include<assert.h>
#include<math.h>


class Date

{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& out, Date& d);

		
public:

	// 获取某年某月的天数

	int GetMonthDay(int year, int month);

	// 全缺省的  构造函数

	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (month <= 12 && month > 0 && day <= GetMonthDay(year, month) && day > 0)
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "非法日期" << endl;
			assert(0);
		}
	}
	// 拷贝构造函数

  // d2(d1)

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	
	void Print()
	{
		cout << _year << "年" << _month << "月" << _day << "天" << endl;
	}

	// 赋值运算符重载

  // d2 = d3 -> d2.operator=(&d2, d3)

	Date& operator=(const Date& d)
	{
		if (this != &d)//比较地址（比较地址比较简单），减少 d1=d1 这种赋值情况
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}


	// 析构函数

	// 日期+=天数

	Date& operator+=(int day);

	// 日期+天数

	Date operator+(int day)const;

	// 日期-天数

	Date operator-(int day)const;

	// 日期-=天数

	Date& operator-=(int day);

	// 前置++

	Date& operator++();

	// 后置++

	Date operator++(int);

	// 后置--

	Date operator--(int);


	// 前置--

	Date& operator--();


	// >运算符重载

	bool operator>(const Date& d)const;

	// ==运算符重载

	bool operator==(const Date& d)const;



	// >=运算符重载

	bool operator >= (const Date& d)const;



	// <运算符重载

	bool operator < (const Date& d)const;



	// <=运算符重载

	bool operator <= (const Date& d)const;



	// !=运算符重载

	bool operator != (const Date& d)const;



	// 日期-日期 返回天数

	int operator-(const Date& d)const;

	Date* operator&()
	{
		cout << "Date* operator&()" << endl;

		return this;
	}
	const Date* operator&()const
	{
		cout << "const Date* operator&()const" << endl;

		return this;
	}
private:

	int _year;

	int _month;

	int _day;

};

ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);