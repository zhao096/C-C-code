 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//struct Stu
////{
////	char name[20];
////	int age;
////	char sex[5];
////	struct Stu *Node;
////};
//
//typedef struct
//{
//	int a;
//}a;
//
//
//int main()
//{
//	//struct Stu student1;
//	//struct Stu student2;
//	//student1.Node = &student2;
//
//	a b = { 20 };
//	printf("%d", b.a);	 
//
//	////student = { "lisi",18,"nan" };
//	//student.age = 25;
//	//
//
//	//printf("%s %d %s", student.name, student.age, student.sex);
//	
//	return 0;
//}

struct Stu
{
	char name[20];
	int age;
	char sex[5];
}student;

int main()
{

	student.age = 25;
	printf("%s %d %s", student.name, student.age, student.sex);
	return 0;
}