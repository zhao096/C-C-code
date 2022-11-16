 #define _CRT_SECURE_NO_WARNINGS 1
// //小乐乐上课需要走n阶台阶，因为他腿比较长，所以每次可以选择走一阶或者走两阶，有几种走法
#include<stdio.h>
// int star(int n)
// {
// 	if (n <= 2)
// 		return n;
// 	else
// 		return star(n - 1) + star(n - 2);//当n-1，n-2后剩下几个台阶，剩下的台阶再进行分析能不///能走一阶或两阶，若能则继续递归，
// 											//n <= 2不能则返回,当只剩0~2返回代表了0~3阶的走法
// }
int main()
{
        int i, j = 0, k = 1, n, temp;
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
        {
            temp = k;
            k = k + j;
            j = temp;//吧前面的两种走法加起来
        }
        printf("%d", k);
    return 0;
}