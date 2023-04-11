typedef char datetype;
#include"stack.h"


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