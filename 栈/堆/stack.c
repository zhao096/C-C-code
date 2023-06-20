#include"stack.h"


bool StackEmpty(stack* ps)
{
    assert(ps);
    return ps->size == 0;//等于0返回真，反之则为假
}



void StackInit(stack* ps)
{
    //初始化两个变量
    ps->capacity = 3;//容量初始为3
    ps->size = 0;//注意size指向的是下一个堆顶的位置

    ps->date = malloc(sizeof(datetype) * ps->capacity);//用malloc给数组开辟datetype类型的容量个大小的空间
    //此处就是开辟了 4(int) * 3（capacity） = 12 byte 大小的空间
    if (ps->date == NULL)//判断是否申请成功
    {
        perror("malloc");
        return;
    }
}

void StackDestroy(stack* ps)
{
    assert(ps);//判空
    ps->capacity = ps->size = 0;//置为0
    free(ps->date);//释放所借的空间
    ps->date = NULL;//将用完的指针置为NULL
}


void StackPush(stack* ps, datetype x)
{
    assert(ps);//判空
    if (ps->size == ps->capacity)//检查空间是否足够
    {
        datetype* tmp = (datetype*)realloc(ps->date, sizeof(datetype) * ps->capacity * 2);//扩容扩大比原容量大两倍的空间大小
        if (tmp == NULL)//检查是否扩容成功
        {
            perror("realloc");
            return;
        }
        ps->date = tmp;//把tmp扩容好的空间，给到date
        ps->capacity *= 2;//注意别忘把capacity增加
    }
    ps->date[ps->size] = x;//在date的top下标位置处插入数据x
    ps->size++;//元素个数增加
}

void StackPop(stack* ps)
{
    assert(ps);//为假就会报错
    assert(!StackEmpty(ps));//判断一下栈是不是空的
    ps->size--;//元素个数减一个
}

datetype StackTop(stack* ps)
{
    assert(ps);
    return ps->date[ps->size - 1];
}

int StackSize(stack* ps)
{
    assert(ps);
    return ps->size;
}