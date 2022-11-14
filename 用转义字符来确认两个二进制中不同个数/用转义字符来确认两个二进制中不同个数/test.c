 #define _CRT_SECURE_NO_WARNINGS 1
int diferent_num(int x, int y)
{
	int n = x ^ y;
	int count = 0;
	int flag = 1;
	while (flag)
	{
		if ((n & flag) != 0)
		{
			count++;

		}
		flag <<= 1;
	}
	return count;

}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int k = diferent_num(a, b);
	printf("%d", k);
	return 0;
}
