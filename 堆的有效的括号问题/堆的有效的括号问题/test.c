 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef char datetype;

typedef struct stack
{
    datetype* date;
    int top;
    int capacity;
}stack;

bool StackEmpty(stack* ps)
{
    assert(ps);
    //if (ps->top == 0)
    //{
    //	return true;
    //}
    //return false;

    return ps->top == 0;//等于0返回真，反之则为假
}



void StackInit(stack* ps)
{
    assert(ps);
    ps->capacity = 3;

    ps->date = malloc(sizeof(datetype) * ps->capacity);//注意初始化要开辟空间给指针否则无法放
    if (ps->date == NULL)
    {
        perror("malloc");
        return;
    }
    ps->top = 0;//注意top指向的是下一个堆顶的位置
}

void StackDestroy(stack* ps)
{
    assert(ps);
    ps->capacity = 0;
    ps->top = 0;
    free(ps->date);
    ps->date = NULL;

}


void StackPush(stack* ps, datetype x)
{
    assert(ps);
    if (ps->top == ps->capacity)
    {
        datetype* tmp = (datetype*)realloc(ps->date, sizeof(stack) * ps->capacity * 2);//应该对数据的类型进行扩容，因为数据存在的是该指针中
        if (tmp == NULL)
        {
            perror("realloc");
            return;
        }
        ps->date = tmp;
        ps->capacity *= 2;
    }
    ps->date[ps->top] = x;
    ps->top++;
}

void StackPop(stack* ps)
{
    assert(ps);//为假就会报错
    assert(!StackEmpty(ps));
    ps->top--;
}

datetype StackTop(stack* ps)
{
    assert(ps);
    return ps->date[ps->top - 1];
}

int StackSize(stack* ps)
{
    assert(ps);
    return ps->top;
}

//
//bool isValid(char* s) {
//    stack p;
//    StackInit(&p);
//    char* tmp = s;
//    char arr[10000] = { 0 };
//
//    int i = 0;
//    for (; *tmp; tmp++)
//    {
//        if (*tmp == '(' || *tmp == '{' || *tmp == '[')
//        {
//            StackPush(&p, *tmp);
//        }
//        else
//        {
//            arr[i] = *tmp;
//            i++;
//            if (!StackEmpty)
//            {
//                char tmp1 = StackTop(&p);
//
//                if (tmp1 == '(')
//                {
//                    if (arr[i - 1] == ')')
//                    {
//                        StackPop(&p);
//                    }
//                }
//                else if (tmp1 == '{')
//                {
//                    if (arr[i - 1] == '}')
//                    {
//                        StackPop(&p);
//                    }
//                }
//                else {
//                    if (arr[i - 1] == ']')
//                    {
//                        StackPop(&p);
//                    }
//                }
//
//            }
//
//
//        }
//    }
//    if (StackEmpty(&p))
//    {
//        return true;
//    }
//    else {
//        return false;
//    }
//}
bool isValid(char* s) {
    char a[10000] = " ", t = 0;
    int i = 0, top = 0;
    while (s[i] != '\0') {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            if (s[i] == '(') 
                t = ')';
            if (s[i] == '{') 
                t = '}';
            if (s[i] == '[') 
                t = ']';
            top++;
            a[top] = t;//存左括号对应的右括号
        }
        else {
            if (a[top] != s[i])//比较存好的右括号和第一次的右括号，并且满足后进先出
                return false;
            else
                top--;
        }
        i++;
    }
    if (top == 0)
        return true;
    else
        return false;
}



    

int main()
{
    char arr[] = "()";
    bool ret= isValid(arr);
 
    return 0;
}