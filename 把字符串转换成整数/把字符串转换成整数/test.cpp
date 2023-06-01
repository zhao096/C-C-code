 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<iostream>
using namespace std;


class Solution {
public:
    void reverse(string& str, int n) {
        int left = 0;
        int right = n - 1;
        while (left < right) {
            swap(str[left], str[right]);
            left++;
            right--;
        }
    }
    int StrToInt(string str) {
        int i = str.size();
        int sum = 0;
        int digit = 1;

        for (int j = 0; j < i; j++) {

            if (!isdigit(str[j]))
            {
                if (j == 0)
                {
                    if (str[j] == '+')
                    {
                        reverse(str, i);
                        i--;
                        j--;
                        continue;
                    }
                    if (str[j] == '-')
                    {
                        cout << '-';
                        reverse(str, i);
                        i--;
                        j--;
                        continue;
                    }
                }
                else if (!isgraph(str[0]))
                {
                    sum += str[j] * digit;
                    digit *= 10;
                }
                else
                {
                    return 0;
                }

            }

            else
            { //isdigit检查该字符是不是十进制数字
                if(j == 0)
                    reverse(str, i);
                if (str[j] - '0')
                {
                    sum += (str[j] - '0') * digit;
                    digit *= 10;
                }
                else
                {
                    return 0;
                }
            }

        }

        return sum;
    }

};

int main()
{
    Solution s;

    int ret = s.StrToInt("123");

    cout << ret << endl;

    return 0;
}