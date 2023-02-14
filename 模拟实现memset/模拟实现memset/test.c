#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
void* my_memset(void* ptr, int a, size_t num)
{
	assert(ptr);
	void* ret = ptr;
	while (num--)
	{
		*(char*)ptr = (char)a;
		++(char*)ptr;
	}
	return ret;
}

int main()
{
	char arr[] = "hello world";


	//void *memset( void *dest, int c, size_t count );
	memset(arr, 'x', 5);//count的大小是byte，会一个个字节的改变
	printf("%s\n", arr);
	memset(arr + 6, 'y', 5);
	printf("%s\n", arr);
	memset(arr, 'a', 5);//count的大小是byte，会一个个字节的改变

	my_memset(arr+5, 'a', 1);//count的大小是byte，会一个个字节的改变
	printf("%s\n", arr);
	my_memset(arr+6, 'b', 5);
	printf("%s\n", arr);

	return 0;

}