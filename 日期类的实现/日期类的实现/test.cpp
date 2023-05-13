 #define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

void Test1()
{
	Date d1(2020, 5, 5);
	d1.Print();
	Date d2(d1);
	d2.Print();
}

void Test2()
{
	Date d1(2020, 5, 5);
	Date d2(d1);
	d2.Print();
	d1.Print();

	Date d3(2023, 5, 6);
	d1 = d3;
	d1.Print();
	d3.Print();

}

void Test3()
{
	Date d1(2020, 5, 5);
	d1 += 27;
	
	//d1.operator+=(27);
	d1.Print();
	

	Date d3(2023, 5, 6);
	d3 -= 27;
	d3.Print();

}
void Test4()
{
	Date d1(2020, 5, 5);
	(d1 + 27).Print();
	d1.Print();
}

void Test5()
{
	Date d1(2020, 5, 5);
	(d1 - 5719).Print();

	d1.Print();
	
	d1 -= 5719;
	
	d1.Print();

	Date d2(2020, 5, 5);
	(d2 - 6147).Print();

	d2.Print();

	d2 -= 6147;
	//   428
	d2.Print();
}



void Test6()
{
	Date d1(2020, 5, 31);
	(++d1).Print();
	(d1++).Print();
	(d1).Print();

}

void Test7()
{
	Date d1(2003, 7, 7);
	Date d2(2004, 9, 7);
	cout << (d2 - d1) << endl;
}


void Test8()
{
	Date d1(2003, 17, 7);
	(d1 - (100) + (-100) ).Print();
}

void Test9()
{
	Date d1(2003, 7, 7);
	//cout << d1;
	cin >> d1;
	cout << d1;


}

void Test10()
{
	Date d1(2003, 7, 7);
	

}
void Test11()
{
	Date d1(2003, 7, 7);
	//cout << d1;
	d1.Print();

	const Date d2(2004, 9, 7);
	//d2.Print();

}

void Test12()
{
	Date d1(2003, 7, 7);

	const Date d2(2004, 9, 7);

	cout << &d1 << endl;
	cout << &d2 << endl;

}

int main()
{
	Test12();
	return 0;
}