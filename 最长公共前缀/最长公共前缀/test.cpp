 #define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int number = strs.size();
        int len = strs[0].size();
        for (int i = 0; i < len; i++)
        {
            int j;
            for (j = 1; j < number; j++)
            {
                if (strs[j][i] != strs[0][i] || strs[j].size() == i)
                    break;
            }
            if (j != number)
                return strs[0].substr(0, i);
        }
        return strs[0];
    }
};