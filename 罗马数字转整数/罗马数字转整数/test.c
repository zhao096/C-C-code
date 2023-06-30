#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
int romanToInt1(char* s) {
    int len = strlen(s);
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'I')
            sum += (s[i + 1] == 'V') ? (i++, 4) : (s[i + 1] == 'X' ? (i++, 9) : 1);
        if (s[i] == 'V')
            sum += 5;
        if (s[i] == 'X')
            sum += (s[i + 1] == 'L') ? (i++, 40) : (s[i + 1] == 'C' ? (i++, 90) : 10);
        if (s[i] == 'L')
            sum += 50;
        if (s[i] == 'C')
            sum += (s[i + 1] == 'D') ? (i++, 400) : (s[i + 1] == 'M' ? (i++, 900) : 100);
        if (s[i] == 'D')
            sum += 500;
        if (s[i] == 'M')
            sum += 1000;
    }
    return sum;
}


int romanToInt2(char* s) {
    //哈希思想
    int romanToInt[26];//共有26个英文字母，开辟26个空间有罗马数字的地方放一个值
    romanToInt['I' - 'A'] = 1;
    romanToInt['V' - 'A'] = 5;
    romanToInt['X' - 'A'] = 10;
    romanToInt['L' - 'A'] = 50;
    romanToInt['C' - 'A'] = 100;
    romanToInt['D' - 'A'] = 500;
    romanToInt['M' - 'A'] = 1000;
    int len = strlen(s);
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        if (i + 1 < len && romanToInt[s[i] - 'A'] < romanToInt[s[i + 1] - 'A'])//s[i]进来的罗马字母 - 'A' 找到其对应的值
        {
            sum -= romanToInt[s[i] - 'A'];
        }
        else {
            sum += romanToInt[s[i] - 'A'];
        }
    }
    return sum;
}

int main()
{

    romanToInt("MCMXCIV");
    return 0;
}