#include<stdio.h>
#include<unistd.h>
#include<string.h>

#define BODY '='

#define RIGHT '>'

typedef void (*processbar)(int);//将函数指针类型重命名为processbar 然后利用函数指针来实现一个回调函数的过程

void processBar(int rata);

//extern void processBar(); extern 可写可不写因为对于函数来说这样写就表示这是一个声明

//但注意的是假如是一个变量的话就需要加上extern了因为分不清到底是不是编译器声明
