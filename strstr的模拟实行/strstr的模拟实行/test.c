 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//const char* my_strstr(const char* string, const char* sour)
//{
//	assert(string && sour);
//	if (*sour == '\0')//
//	{
//		return string;
//	}
//	char* tagg = (char*)string;
//	char* tagr = (char*)sour;//用两个指针记录string和sour的地址
//
//	while (*string)//遍历的寻找方法,注意此处要用*string
//	{
//
//		tagg = (char*)string;//通过记录的位置返回
//		tagr = (char*)sour;
//
//		while (*tagg++ == *tagr++ && *tagg != '\0')
//		{
//			if (*tagr == '\0')
//			{
//				return string;
//			}
//		}
//		string++;//放到后面来++是因为在前面会导致返回值被++也就是上面这里的return string
//	}	
//	return NULL;//当string的长度为0时无法进入循环即找不到相同的时候就会返回0
//}
const char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	const char* tmp1 = str1;
	const char* tmp2 = str2;
	int ret = strlen(str2);//当str2为0时直接返回str1的地址
	if (ret == 0)
		return str1;
	while (*str1)//当找不到时*str1++到了\0
	{
		tmp1 = str1;//str不断的向前走  如 abcedf  -> 先将a的地址创给了tmp1 后指向下一个 
							//当里面的循环不成立有进行外面的循环时就可以继续一个个查
		tmp2 = str2;//str2记录str2的位置
		ret = strlen(str2);//防止ret--使ret改变，所以要初始化
		while (*tmp1 == *tmp2)
		{
			ret--;
			tmp2++;
			tmp1++;
			if (!ret)
			{
				return str1;
			}
		}
		str1++;
	}
	return NULL;
}
int main()
{
	char arr1[] = "cbcbcbcaaaaaaaaaaaaaaaaacd";
	char arr2[] = "bcd";
	//printf("%s",strstr(arr1, arr2));
	const char* ret = my_strstr(arr1, arr2);

	if (ret == NULL)
	{
		printf("找不到\n");
	}
	else
	{
		printf("%s", ret);

	}
	return 0;
}


//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	char* tmp1 = str1;
//	char* tmp2 = str2;
//	int ret = strlen(str2);//当str2为0时直接返回str1的地址
//	if (ret == 0)
//		return str1;
//	while (1)
//	{
//		tmp1 = str1++;//str不断的向前走  如 abcedf  -> 先将a的地址创给了tmp1 后指向下一个 
//							//当里面的循环不成立有进行外面的循环时就可以继续一个个查
//		tmp2 = str2;//str2记录str2的位置
//		while(*tmp1 == *tmp2)
//		{
//			ret--;
//			tmp2++;
//			tmp1++;
//			if (!ret)
//			{
//				return str1;
//			}
//		}
//	
//	}
//
//}