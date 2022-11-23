 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int MeiWeiDe_n_Ci(int x ,int j)
{
	int t = x;
	for (; j > 1; j--)//该位数 的 总位数次,当j = 3，里面的x * x 只用成两次，即 x * x * x，所以大于1
	{
		x *= t;//注意不要x * x 这样将会导致 第一次 3 * 3 = 9 , 第二次 9*9 = 81 ,而不是所想的3*9=27
	}
	return x;
}
int weishu(int n)
{
	int count= 0;
	while(n)
	{ 
		count++;
		n = n / 10;
	}
	return count;
}
int GeGeWei(int n)
{
	return n % 10;
}
int main()
{
	int n = 0;
	for (n = 0; n < 100000; n++)
	{
		int tmp = n;//存n
		int j = weishu(tmp);//求出总共的位数
		int z = 1;
		int sum = 0;
		int t = j;

		while (t)
		{
			int x = GeGeWei(tmp);
			sum += MeiWeiDe_n_Ci(x, j);
			tmp /= 10;
			t--;
		}
		if (sum == n)
		{
			printf("%d ", sum);
		}
	}
	return 0;
}