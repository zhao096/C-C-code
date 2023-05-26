// #define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//
//class Sum
//{
//public:
//    Sum()
//    {
//        _i += 1;
//        _sum += _i;
//    }
//    class Solution {
//    public:
//        static int Sum_Solution(int n) {
//            Sum* ptr = new Sum[n]; 
//            delete[] ptr;
//            return _sum;
//        }
//    };
//        
//private:
//    static int _i;
//    static int _sum;
//};
//int Sum::_i = 0;
//int Sum::_sum = 0;
//
//int main()
//{
//   int number =  Sum::Solution::Sum_Solution(100);
//   cout << number << endl;
//}
//

//#include <iostream>
//using namespace std;
//
//int GetMonthDay(int year, int month) {
//    int monthday[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//    if (month == 2 &&((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))) {
//        return 29;
//    }
//    else {
//        return monthday[month];
//    }
//}
//int GetYearDay(int year, int month, int day)
//{
//    int t_m = 0;
//    int t_d = 0;
//    int YearDay = 0;
//    for (t_m = 1; t_m < month; t_m++)
//    {
//        YearDay += GetMonthDay(year, t_m);
//    }
//    for (t_d = 1; t_d <= day; t_d++)
//    {
//        YearDay++;
//    }
//    return YearDay;
//}
//
//
//
//
//int main() {
//    int year, day, month;
//    cin >> year >> month >> day;
//    int ret = GetYearDay(year, month, day);
//    cout << ret << endl;
//}
// 64 位输出请用 printf("%lld")

#include <iostream>
using namespace std;

int GetmonthDay(int year, int month, int day) {
    int monthday[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))) {
        return 29;
    }
    else {
        return monthday[month];
    }
}

int dim_dd(int date1, int date2) {
    int max = date1;
    int min = date2;
    if (max < min) {
        max = date2;
        min = date1;
    }//得到
    int tmp = 1;//本身这天也要算所以从1开始

    int day1 = min % 100;
    int day2 = max % 100;//模得到后两位 
    int month1 = min % 10000 / 100;//先取狗4位再除去最后两位得到就是月份
    int month2 = max % 10000 / 100;
    int year1 = min / 10000;//直接除去后4位得到年
    int year2 = max / 10000;

    while ((year1 != year2) || (month1 != month2) || (day1 != day2))
    {
        if (day1 == GetmonthDay(year1, month1, day1))
        {
            month1++;
            if (month1 == 13)
            {
                year1++;
                month1 = 1;
            }
        }
        day1++;
        tmp++;
    }

    return tmp;
}


int main() {
    int date1, date2;
    cin >> date1;
    cin >> date2;
    int tmp = dim_dd(date1, date2);
    cout << tmp << endl;
}
// 64 位输出请用 printf("%lld")