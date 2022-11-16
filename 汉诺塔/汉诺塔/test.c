 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void Tower(char a, char b, char c, int n)
{
	if (n == 0)
		return;
	Tower(a, c, b, n - 1);
	printf("%c -> %c", a, c);
	Tower(b, a, c, n - 1);
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	Tower('A','B','C', num);
	//A B为辅助柱，A也是起始柱
	//C为目标柱
	return 0;
}