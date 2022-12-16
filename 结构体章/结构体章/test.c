 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
////struct score
////{
////	int M;
////	int E;
////};
////struct Stu1
////{
////	char name[15];
////	int number;//变量
////	char sex[3];//数组
////	struct score s;//嵌套结构体
////	int* Null;//指针
////	//struct Node* next;
////}student = { "李华",12345,"女" };//直接在类型后创建的结构体变量
////
////struct Stu1 student1 = { "李化" ,54321,"男"};//全局结构体变量
////
////int main()
////{
////	struct Stu1 n = { "李",321,"男",{90,60} ,NULL};//局部结构体变量
////
////	n.number = 5;
////	printf("%d\n", n.number);
////	printf("%s %d %s %d %d %d", n.name, student1.number, student.sex,n.s.E,n.s.M,n.Null);//结构体的访问
////	
////	return 0;
////}
struct score
{
	int M;
	int E;
};
void add(struct score a)
{
	a.M = 60;
	a.E= 90;
}
int main()
{
	struct score s = { 90 , 60 };
	printf("%d %d\n", s.E, s.M);
	add(s);
	printf("%d %d\n", s.E, s.M);

	return 0;
}


struct score
{
	int M;
	int E;
};
void add(struct score *a)
{
	//(*a).M = 60;
	a->M = 60;
	//(*a).E = 90;
	a->E = 90;

}
int main()
{
	struct score s = { 90 , 60 };
	printf("%d %d\n", s.E, s.M);
	add(&s);
	printf("%d %d\n", s.E, s.M);

	return 0;
}
//struct score
//{
//	int M;
//	int E;
//};
//void add(struct score a)
//{
//	printf("%d %d", a.E, a.M);
//}
//int main()
//{
//	struct score s = { 90 , 60 };
//	add(s);
//	return 0;
//}


//struct score
//{
//	int M;
//	int E;
//};
//void add(struct score* a)
//{
//	printf("%d %d", a->E, a->M);
//}
//int main()
//{
//	struct score s = { 90 , 60 };
//	add(&s);
//	return 0;
//}