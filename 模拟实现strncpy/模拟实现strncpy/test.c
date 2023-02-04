 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

char* my_strncpy(char* strDest, const char* strSource, size_t count)
{
	assert(strDest && strSource);
	char *ret = strDest;
	


	while (count--)
	{
		*strDest = *strSource ;
		if(*strSource != '\0')
		{
			strDest++;
			strSource++;
		}
	}

	return ret;
}
//char* my_strncpy(char* des, const char* sour, size_t count)
//{
//    assert(des && sour);
//    char* tmp = des;
//    while (count--)
//    {
//        if (*sour == '\0')
//        {
//            *des++ = '\0';
//            continue;
//        }
//        else
//        {
//            *des++ = *sour++;
//        }
//
//    }
//
//    return tmp;
//}

int main()
{
	//模拟实现strncpy   char *strncpy( char *strDest, const char *strSource, size_t count );
	
	char arr1[] = "xxxxxxxxx";//注意要给\0留个位置所以arr大小为10只能输9个进去
	char arr2[] = "abcd";

	
	//printf("%s\n", strncpy(arr1, arr2,4 ));

	printf("%s\n", my_strncpy(arr1, arr2, 5));

    //printf("%s\n", my_strncpy(arr1, arr2, 4));


	
	return 0;
}