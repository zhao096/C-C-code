 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char* b1, char* b2, size_t width)
{
	size_t i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *b1;
		*b1++ = *b2;
		*b2++ = tmp;
	}
}
void buble_sort(void* base, size_t num, size_t width, int cmp(const void* elem1, const void* elem2))
{
	size_t i = 0, j = 0;
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num - i - 1; j++)//sz - 1 只需要完成总的个数再减1次
		{
			int ret = 0;
			if (ret = cmp((char*)base + j * width, (char*)base + (j + 1) * width)>0)
			{
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}

//---------------------------------------------------------------------------------------------------------------------------------


int char_sort(const void* e1, const void* e2)
{
	return *((char*)e1) - *((char*)e2);//在内存以ASCII码值存直接和整形一样的算法即可
}

void cha(void)
{
	char arr[] = { 'd','c','b','a' };
	//qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), char_sort);
	buble_sort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), char_sort);

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%c ", arr[i]);
	}
	printf("\n");
}

//---------------------------------------------------------------------------------------------------------------------------------


int float_sort(const void* e1, const void* e2)
{
	return (*((double*)e1) - *((double*)e2) > 0) ? 1 : -1;//因为浮点数有存储时总存在误差（相同的数在每台机子都可能存的不一样）,所以相减时不为0
}
void flt(void)
{
	double arr[] = { 19.8,21.4,35.6,11.3,8.7,0.0 };
	//qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), float_sort);
	buble_sort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), float_sort);

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%lf ", arr[i]);
	}
	printf("\n");
}


//---------------------------------------------------------------------------------------------------------------------------------

struct Stu
{
	int age;
	char name[20];
};
int sort_year(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
	//e1 表示这个结构体的地址 (*((struct stu*)e2)).year ==((struct stu*)e1)->year
}
int sort_name(const void* e1, const void* e2)
{

	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);//e1 < e2 返回负数 ...
}
void str(void)
{
	struct Stu student[2] = { {18,"zihua"},{19,"lhansan"} };/*
	qsort(student, sizeof(student) / sizeof(student[0]), sizeof(student[0]), sort_year);
	qsort(student, sizeof(student) / sizeof(student[0]), sizeof(student[0]), sort_name);*/
	buble_sort(student, sizeof(student) / sizeof(student[0]), sizeof(student[0]), sort_year);
	buble_sort(student, sizeof(student) / sizeof(student[0]), sizeof(student[0]), sort_name); 



}


//----------------------------------------------------------------------------------------------------------

int int_sort(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;//大于0则e1 > e2 ，当大于0就会交换
}
void it(void)
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	//qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), int_sort);
	buble_sort(arr, 10, 4, int_sort);

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//---------------------------------------------------------------------------------------------------------------------------------
//通过冒泡排序实现qsort函数

//void buble_sort(int arr[], int sz)
//{
//	int i = 0, j = 0;
//	for (i = 0; i < sz; i++)
//	{
//		for (j = 0; j < sz - i - 1; j++)//sz - 1 只需要完成总的个数再减1次
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}



//---------------------------------------------------------------------------------------------------------------------------------

int main()
{
	it();
	str();
	flt();
	cha();

	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };

	buble_sort(arr,10,4, int_sort);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}







