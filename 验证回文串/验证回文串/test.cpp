 #define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//class Solution {
//public:
//    bool isPalindrome(string s) {
//        int pre = 0;
//        int tail = s.size() - 1;
//        while (pre < tail)
//        {
//            char t1 = s[pre];
//            char t2 = s[tail];
//            if ((t2 > 57 && t2 < 65) || t2 < 48 || t2 > 122)
//            {
//                tail--;
//                continue;
//            }
//
//            if ((t1 > 57 && t1 < 65) || t1 < 48 || t1 > 122)
//            {
//                pre++;
//                continue;
//            }
//            if (isupper(t1))
//                t1 = tolower(t1);
//            if (isupper(t2))
//                t2 = tolower(t2);
//            if (t1 != t2)
//                return false;
//            tail--;
//            pre++;
//        }
//        return true;
//    }
//};
class Solution {
public:
    bool isPalindrome(string s) {
        string tmp;
        for (auto x : s)
        {
            if (isalnum(x)) {
                tmp += tolower(x);
            }
        }
        int prev = 0, tail = tmp.size() - 1;
        while (prev < tail)
        {
            if (tmp[prev++] != tmp[tail--])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    bool ret = s.isPalindrome("ab_a");

	return 0;
}

