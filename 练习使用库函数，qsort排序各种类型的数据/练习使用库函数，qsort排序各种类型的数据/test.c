 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int int_sort(const void* e1, const void* e2)
{
	return *((int*)e1) - *((int*)e2);//大于0则e1 > e2 ，当大于0就会交换
}


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

int sort_name (const void* e1, const void* e2)
{
	
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);//e1 < e2 返回负数 ...
}


void str(void)
{
	struct Stu student[2] = { {18,"zihua"},{19,"lhansan"} };

	qsort(student, sizeof(student) / sizeof(student[0]), sizeof(student[0]), sort_year);
	qsort(student, sizeof(student) / sizeof(student[0]), sizeof(student[0]), sort_name);

}
void it(void)
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), int_sort);
 }

int main()
{
	it();
	str();

	
	
	return 0;
}
