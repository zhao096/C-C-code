 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>



//---------------------------------------------

void swap(char * e1 ,char * e2,size_t wdh)
{
	assert(e1&&e2);
	for (size_t i = 0; i < wdh; i++)
	{
		char tmp = *e1;
		*e1++ = *e2;
		*e2++ = tmp;
	}
}

void buble_qsort(void* base, size_t num, size_t width, int (*cmp)(const void* ele1, const void* ele2))
{
	//用冒泡排序模拟qsort的快拍
	for (size_t i = 0; i < num - 1; i++)
	{
		for (size_t j = 0; j < num - i - 1; j++)
		{
			if (cmp((char *)base + j * width, (char*)base  + (j+1) * width)> 0)//注意不用加i 因为每次都应该从第一个开始,i只是为了确定次数
			{
				swap((char*)base + j * width, (char*)base + (j + 1) * width,width);//注意此处你还应该不只是一个char * 而是width个char * ,所以还要传width过去
			}
		}
	}

}

typedef struct Stu {
	char name[20];
	int age;
} Stu;

int stru_name(const void* e1, const void* e2)
{
	return strcmp(((Stu *)e1)->name, ((Stu*)e2)->name);//强制类型转换的优先级小于->，对此我们还应该加上（）来先将void * 变成 Stu*
}
int stru_age(const void* e1, const void* e2)
{
	return ((Stu*)e1)->age - ((Stu*)e2)->age;
	
}

void str()
{

	Stu student[3] = { {"zhansang",18},{"lisi",55},{"wangwu",22} };
	//buble_qsort(student, 3, sizeof(Stu), stru_name);
	buble_qsort(student, 3, sizeof(Stu), stru_age);
}



//整形的比较函数，注意其类型要和qsort内所接收的函数指针类型相同即类型int (void *,void *)
int cmp_int(const void* e1,const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

void it()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	buble_qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmp_int);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	//void qsort( void *base, size_t num, size_t width, int (__cdecl *compare )(const void *elem1, const void *elem2 ) );
	it();
	str();

	return 0;
}