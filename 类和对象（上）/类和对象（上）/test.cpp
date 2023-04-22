 #define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include"Person.h"


using namespace std;

struct Stack
{
	//成员函数
	//在类域中不管声明的位置都能找得到
	void Init(int DefaultCapacity = 4)
	{
		a = (int*)malloc(sizeof(int) * DefaultCapacity);
		if (a == nullptr)
		{
			perror("malloc");
			return;
		}
		capacity = DefaultCapacity;
		size = 0;
	}
	void Push(int x)
	{	
		if (size == capacity)
		{
			int* ptr = (int*)realloc(a, sizeof(int) * capacity * 2);
			assert(ptr);
			a = ptr;
			capacity *= 2;
		}	
		a[size++] = x;
	}

	int Top()
	{
		assert(size);
		return a[size - 1];
	}


	void Destroy()
	{
		free(a);
		a = nullptr;
		capacity = size = 0;
	}
	//成员变量
	int* a;
	int size;
	int capacity;
};

int main()
{
	//Stack sk;
	//sk.Init(20);
	//sk.Push(1);
	//sk.Push(2);
	//sk.Push(3);
	//cout << sk.Top() << endl;
	//sk.Destroy();

	Person p;
	p.PersonInit();
	char a[] = "LiHua";
	p.ShowInfo(a);
	return 0;
}