 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//方法1
size_t my_strlen1(const char* string)
{
    assert(string);
    size_t count = 0;
    while (*string++)
    {
        count++;
    }
    return count;
}

//方法2
size_t my_strlen2(const char* string)
{
    assert(string);
    const char* tmp = string;
    while (*++string);
    return string - tmp;
}

//方法3
size_t my_strlen3(const char* string)
{
    assert(string);
    if (!(*string))
        return 0;
    else
    {
        return 1 + my_strlen3(string+1);
    }
}
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