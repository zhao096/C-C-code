 #define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


class Solution {
public:

    string addStrings(string num1, string num2) {
        int l1 = num1.size() - 1;
        int l2 = num2.size() - 1;
        string num3;
        int digit = 0;//进位的数
        while (l1 >= 0 || l2 >= 0 || digit != 0)
        {
            int tmp = l2 >= 0 ? (num2[l2--] - '0') : 0;
            tmp += l1 >= 0 ? (num1[l1--] - '0') : 0;
            tmp += digit;


            num3 += tmp % 10 + '0';
            digit = tmp / 10;
        }
        reverse(num3.begin(), num3.end());
        return num3;
    }
    string multiply(string num1, string num2) {
        int l1 = num1.length();
        int l2 = num2.length();
        int a = 0, tag = 1;
        string ret = "0";
        cout << num2 << endl;

        while(l2)
        {
            l2--;
            string l1_tmp = "0";
            int tmp = num2[l2] - '0';
            while (tmp--)
            {
                l1_tmp = addStrings(l1_tmp, num1);
            }
            tmp = tag++;
            while (--tmp)
            {
                l1_tmp += '0';
            }
            ret = addStrings(ret, l1_tmp);
        }
        return ret;
    }
};




int main()
{
    Solution s;
    s.multiply("2", "3");
    return 0;
}