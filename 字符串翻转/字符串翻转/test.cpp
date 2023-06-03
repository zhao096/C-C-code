 #define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            swap(s[left++], s[right--]);
        }
    }
};

class Solution {
public:
    int Ifsame(string& tmp, char& a)
    {
        int ret = 1;
        for (auto ch : tmp)
        {
            ret = (a == ch) ? 0 : 1;
            if (!ret)
                break;
        }
        return ret;
    }

    int firstUniqChar(string s) {
        int ret = -1;
        int move = 0, tag = 0;
        string tmp;
        for (move = 0; move < s.size(); move++)
        {
            if (Ifsame(tmp, s[move])) {
                ret = move;
                for (tag = move + 1; tag < s.size(); tag++)
                {
                    if (s[move] == s[tag])
                    {
                        tmp += s[move];
                        ret = -1;
                        break;
                    }
                }
            }
            if (ret != -1)
                break;
        }
        return ret;
    }
};