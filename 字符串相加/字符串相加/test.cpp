 #define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Solution {
public:

    void reverse(string& s)
    {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    string addStrings(string num1, string num2) {

        string max = num1;
        string min = num2;

        int l1 = max.size()-1;
        int l2 = min.size()-1;
        if (l1 < l2)
        {
            max = min;
            min = num1;
            l1 = l2;
            l2 = num1.size();
        }
        else if (l1 == l2 && max < min)
        {
            max = min;
            min = num1;
            l1 = l2;
            l2 = num1.size();
        }


        string num3;
        int tmp = 0;
        int digit = 0;//进位的数
        for (; l1 >= 0; l1--)
        {
            if (l2 >= 0)
                tmp =(min[l2--] - '0');
            tmp +=(max[l1] - '0' + digit);

            num3 += (tmp % 10) + '0';
            digit = tmp / 10;
            tmp = 0;
        }
        reverse(num3);

        return num3;
    }
};

int main()
{
    Solution s;
    s.addStrings("23", "127");

    return 0;
}