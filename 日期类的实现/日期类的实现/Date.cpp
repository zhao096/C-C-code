 #define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"


int Date::GetMonthDay(int year, int month)
{

	static int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//因为该数组会被经常的调用所以可以直接放到静态区
	if (month == 2 && year % 4 == 0 && year % 100 != 0 || year % 400 == 0)//对2月闰年单独讨论
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
	if (day < 0)//为了当传进来是-的天数也能使用
	{
		*this -= (-day);//-= 在后面实现
		return *this;
	}
	_day += day;//用进位的方法来算，先加上天数
	while(_day > GetMonthDay(_year,_month))//如果天数大于该月的月数就进位
	{
		_day -= GetMonthDay(_year, _month);//在进位后就需要把上月的天数剪掉

		//注意这些应该写在后面
		_month++;
		if (_month > 12)//当月到了12时也要进位
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}

//此处最后就是用 + 来调用+= 而不是用 += 来调用 +

Date Date::operator+(int day)
{
	//我们在使用 + 时有时是不需要去改变值的 如  a + 2 ; a 并没有改变
	Date tmp(*this);//创建一个临时变量
	//if (day < 0)
	//{
	//	tmp -= abs(day);
	//	return tmp;
	//}
	tmp += day;//对临时变量 += 
	return tmp;//返回临时变量即可

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
	if (day < 0)//同理当day < 0 时就相当于 += 
	{
		*this += (-day);
		return *this;
	}
	_day -= day;//先减去一定的天数
	while (_day <= 0)//不断的借位，只到借到正常的天数
	{
		_month--;
		if (_month < 1)
		{
			_month = 12;
			_year--;
		}
		//注意此时day += 应该写在后面 因为是要向前借位
		_day += GetMonthDay(_year, _month);//加上前一个月的月份,接一位
	}
	return *this;
}

Date Date::operator-(int day)
{

	Date tmp(*this);
	// -= 行了 就不用再 写下面的了
	//if (day < 0)
	//{	
	//	tmp += (-day);
	//	return tmp;
	//}
	tmp -= day;

	return tmp;

}

Date& Date::operator++()//前置 ++ 
{
	*this += 1;//直接++即可
	return *this;
}


Date Date::operator++(int) // 后置 ++ 通过一个参数来占位 构成函数重载来区分
{
	Date tmp(*this);// 因为是后置 ++ 所以用临时变量传回去++前的值
	*this += 1;
	return tmp;
}

Date& Date::operator--()//前置
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)//后置
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

//2022 5 1
//2022 5 2
bool Date::operator>(const Date& d)
{
	if (_year < d._year)//先判断是否小于，若否则是  等于（继续判断）或 大于（直接结束）
	{
		return false;
	}
	else if (_year == d._year && _month < d._month)//同理
	{
		return false;
	}
	else if (_year == d._year && _month == d._month && _day < d._day)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Date::operator==(const Date& d)//简单的判断
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
	return !(*this > d);
}

bool Date::operator < (const Date& d)
{
	return !(*this >= d);
}

bool Date::operator != (const Date& d)
{
	return !(*this == d);
}

int Date::operator-(const Date& d)
{
	int tag = 1;
	Date Max(*this);//先确立大的为*this
	Date Min(d);//把 d 看成小的
	if (Max < Min)//如果 Max < Min 就交换
	{
		Min = *this;
		Max = d;
		tag = -1;// 交换后表示前面的值要小于后面的值 ， 所以把 tag 置为负的
	}
	int count = 0;
	while (Min < Max)//看看相差多少 ，逐一相加
	{
		count++;
		++Min;
	}
	return count * tag;
}







