 #define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
    int* a;
    int front;
    int rear;
    int k;
} MyCircularQueue;
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    assert(obj);
    return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    assert(obj);
    return (obj->rear + 1)  % (obj->k + 1) == obj->front;
}

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (obj == NULL)
    {
        perror("obj :: malloc");
        return NULL;
    }
    obj->a = (int*)malloc(sizeof(int) * (k + 1));
    obj->front = obj->rear = 1;
    obj->k = k;
    return obj;
}




//循环队列的插入数据，从rear尾插入,注意下标问题
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
        return false;

    obj->a[(obj->rear +obj-> k) % (obj->k + 1)] = value;

    obj->rear++;
    obj->rear %= obj->k + 1;
    return true;
}






bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return false;

    obj->front++;
    obj->front %= obj->k + 1;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    else {
        return obj->a[(obj->front + obj->k) % (obj->k + 1) - 1];
    }
}




int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    else if(obj->rear == 0 || obj->rear == 1)
    {
        return obj->a[(obj->rear + obj->k) % (obj->k + 1 )-1];
    }
    else
    {
        return obj->a[obj->rear - 2];
    }
}






void myCircularQueueFree(MyCircularQueue* obj) {
    assert(obj);
    free(obj->a);
    free(obj);
}


int main()
{
    MyCircularQueue* obj = myCircularQueueCreate(3);
    bool param_1 = myCircularQueueEnQueue(obj, 1);
    bool param_2 = myCircularQueueEnQueue(obj, 2);
    bool param_3 = myCircularQueueEnQueue(obj, 3);
    bool param_4 = myCircularQueueEnQueue(obj, 4);

    int param_5 = myCircularQueueRear(obj);

    bool param_6 = myCircularQueueIsFull(obj);


    bool param_7 = myCircularQueueDeQueue(obj);

    bool param_8 = myCircularQueueEnQueue(obj, 4);

    int param_9 = myCircularQueueRear(obj);




    myCircularQueueFree(obj);

    return 0;
}

