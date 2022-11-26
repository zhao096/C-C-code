 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	char str[100] = { 0 };
	scanf("%[^\n]", str);//这样写就可以%[^\n]让scanf读取空格
	char tmp = 0;
	int sz = strlen(str)-1;
	int l = 0;
	while( l++ < sz--)//abc def  共七个字符, 除以2再减1变成2，也就是说他只会改变前两个字符 0 1 当等于2时就会跳出
	{									//，就会使C d不交换，即sz-1后这个点是你需要的,而当你不减1，则表示这个点并不需要
	
		tmp = str[sz];
		str[sz] = str[l];
		str[l] = tmp;
	
	
	}
	printf("%s", str);
	return 0;
}
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char str[100] = { 0 };
//	char str1[100] = { 0 };
//	scanf("%[^\n]", str);
//	char tmp = 0;
//	int sz = strlen(str) - 1;
//	for (int i = 0; sz >= 0 ; i++)
//	{									
//		str1[i] = str[sz--];
//	}
//	printf("%s", str1);
//	return 0;
//}