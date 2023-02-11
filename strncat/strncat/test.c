 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
char* my_strncat(char* des, const char* sour, size_t count)
{
    assert(des && sour);
    char* tmp = des;
    while (*des)
    {
        des++;
    }
    while (count--)
    {
        if (*sour == '\0')
            *des = '\0';

        *des++ = *sour++;
    }

    return tmp;
}

int main()
{
	//char *strncat( char *strDest, const char *strSource, size_t count );//×·¼Ó¸öÊý

	char arr1[12] = "x\0xxxxxx";
	char arr2[] = "acde";

	//printf("%s", strncat(arr1, arr2, 4));
	printf("%s", my_strncat(arr1, arr2, 4));

	return 0;
}