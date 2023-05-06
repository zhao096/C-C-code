 #define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"


int Date::GetMonthDay(int year, int month)
{

	int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		return 29;
	}
	else
	{
		return arr[month];
	}

}

// 2020 5 5 + 10
//2020 5 5 + 26
//31 - 30 == 1 

Date& Date::operator+=(int day)
{
	_day += day;
	while(_day > GetMonthDay(_year,_month))
	{
		_day -= GetMonthDay(_year, _month);

		//注意这些应该写在后面
		_month++;
		if (_month > 12)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}


Date Date::operator+(int day)
{

	//此处最后就是用 + 来调用+= 而不是用 += 来调用 +
	Date tmp(*this);
	tmp += day;
	return tmp;

	//下面其实是一些重复的动作我们可以通过再次调用+=
	 
	//tmp._day += day;
	//while (tmp._day > GetMonthDay(_year, _month))
	//{
	//	tmp._day -= GetMonthDay(_year, _month);

	//	//注意这些应该写在后面
	//	tmp._month++;
	//	if (tmp._month > 12)
	//	{
	//		tmp._month = 1;
	//		tmp._year++;
	//	}
	//}
	//return tmp;
}


//2020 5 5 -= 5  2020 4 30
//2020 5 5 -= 6  2020 4 29

Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0)
	{
		//注意这些应该写在后面

		_month--;
		if (_month < 1)
		{
			_month = 12;
			_year--;
		}
		_day += GetMonthDay(_year, _month);//加上前一个月的月份,接一位
	}
	return *this;

}

Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;
	return tmp;

}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}


Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

//2022 5 1
//2022 5 2
bool Date::operator>(const Date& d)
{
	if (_year <= d._year)
	{
		return false;
	}
	else if (_year == d._year && _month <= d._month)
	{
		return false;
	}
	else if (_year == d._year && _month == d._month && _day <= d._day)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Date::operator==(const Date& d)
{
	return (_year == d._year && _month == d._month && _day == d._day);
}

bool Date::operator>=(const Date& d)
{
	return *this > d || *this == d;


	//if (_year < d._year)
	//{
	//	return false;
	//}
	//else if (_year == d._year && _month < d._month)
	//{
	//	return false;
	//}
	//else if (_year == d._year && _month == d._month && _day < d._day)
	//{
	//	return false;
	//}
	//else
	//{
	//	return true;
	//}
}

bool Date::operator <= (const Date& d)
{
	return !(*this >= d);
}

bool Date::operator < (const Date& d)
{
	return !(*this > d);
}

bool Date::operator != (const Date& d)
{
	return !(*this == d);
}

int Date::operator-(const Date& d)
{
	int tag = 1;
	Date Max(*this);
	Date Min(d);
	if (Max < Min)
	{
		Min = *this;
		Max = d;
		tag = -1;
	}
	int count = 0;
	while (Min < Max)
	{
		count++;
		++Min;
	}

	return count * tag;
}





