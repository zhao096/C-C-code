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
//
//struct Stu
//{
//	char name[20];
//	int age;
//	char sex[5];
//	struct Stu* a;
//};
//
//int main()
//{
//	struct Stu student1;
//	struct Stu student = { .a = &student1 , .age = 20 , .name= "lisi",.sex= "nan"};
//	//通过.a = ...  这种形式来乱序初始化
//	
//	printf("%s %d %s %p", student.name, student.age, student.sex,student.a);
//	return 0;
//}



#include<stdio.h>
#include<stddef.h>
//struct S1
//{
//    char c1;
//    int i;
//    char c2;
//};
//int main()
//{
//    printf("%d\n", sizeof(struct S1));
//    printf("%d\n", offsetof(struct S1,c1));
//    printf("%d\n", offsetof(struct S1,i));
//    printf("%d\n", offsetof(struct S1, c2));
//
//
//
//
//}

//struct S3
//{
//	double d;// 对齐数8
//	char c;// 1
//	int i;//4
//};//总大小为 8 -> 8 + 1 -> 12 + 4 -> 16
//
//struct S4
//{
//	char c1;// 1
//	struct S3 s3;// 16
//	double d;// 8
//};
////此处double类型的大小是8 默认也是8 所以最终对齐数就是8 ，其次注意嵌套结构体 放在外部的结构体时要对齐到
//		//嵌套结构体内部最大对齐数的整数倍即8的倍数，
////并且刚好32也是最大对齐数8的整数倍（包含嵌套内成员的对齐数）
//int main()
//{
//	printf("%d\n", sizeof(struct S4));//总大小为：1 - > 8(直接找倍数) + 16 - > 24 + 8 -> 32
//	return 0;
//}
#include<string.h>
struct Stu
{
	char name[20];
	int age;
	char sex[5];
}student;

int main()
{

	student.age = 25;
	//字符串数组的话，你要想赋值，你就必须要通过拷贝
	strcpy(student.name, "LiSi");
	strcpy(student.sex, "男");
	printf("%s %d %s", student.name,student.age,student.sex)//
	return 0;
}

