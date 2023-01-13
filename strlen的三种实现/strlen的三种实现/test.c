 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
int my_strlen1(char * p)
{
	assert(p);
	int num = 0;
	while(*p++ != '\0')
	{
		num++;
	}
	return num;
}
int my_strlen2(char* p)
{
	assert(p);

	if (*p == '\0')
	{
		return 0;
	}
	return 1 + my_strlen2(p+1);
}
int my_strlen3(char* p)
{
	assert(p);

	char* p1 = p;
	while (*p++ != '\0');
	return p - p1 -1;
}// 当他指向0后就会退出但是他仍然会加加所以就导致p指向0字符的下1
int main()
{
	char arr[] = "abcdef";
	int ret = my_strlen1(arr);
	printf("%d\n", ret);
	ret =my_strlen2(arr);
	printf("%d\n", ret); 
	ret = my_strlen3(arr);
	printf("%d\n", ret);
	return 0;
}