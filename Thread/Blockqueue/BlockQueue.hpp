#pragma once
#include<iostream>
#include<queue>
#include<ctime>
#include<unistd.h>
#include<pthread.h>
#include"LockGuard.hpp"

using namespace std;

const int defaultcap = 5;//

template<class T>
class Blockqueue
{
public:
    Blockqueue(int cap = defaultcap):_capacity(cap)
    {
        pthread_mutex_init(&_mutex,nullptr);
        pthread_cond_init(&_c_cond,nullptr);
        pthread_cond_init(&_p_cond,nullptr);
    }

    bool IsFull()
    {
        return _q.size() == _capacity;
    }

    bool IsEmpty()
    {
        return _q.size() == 0;
    }
//生产者
    void Push(const T &in)
    {
        LockGuard lockgaurd(&_mutex);
        // pthread_mutex_lock(&_mutex);
        while(IsFull())
        {
            // 生产线程，阻塞等待
            pthread_cond_wait(&_p_cond,&_mutex);
        }
        _q.push(in);
       
        pthread_cond_signal(&_c_cond); //放到里面被唤醒了会在锁处等待了，而非cond处，只要释放锁后就能立刻拿到锁
        // if(_q.size() > _productor_water_line) pthread_cond_signal(&_c_cond);
        // pthread_mutex_unlock(&_mutex);
    }

    void Pop(T *out)
    {
        LockGuard lockgaurd(&_mutex);
        // pthread_mutex_lock(&_mutex);
        while(IsEmpty())   
        {
            //阻塞等待
            pthread_cond_wait(&_c_cond,&_mutex);
        }
        *out = _q.front();

         pthread_cond_signal(&_p_cond);
        //(_q.size() > _consumer_water_line) pthread_cond_signal(&_p_cond);
        _q.pop();

        // pthread_mutex_unlock(&_mutex);
    }
    ~Blockqueue()
    {
        pthread_mutex_destroy(&_mutex);
        pthread_cond_destroy(&_c_cond);
        pthread_cond_destroy(&_p_cond);
    }

private:
    queue<T> _q;
    size_t _capacity;//q.size == capacity满

    pthread_mutex_t _mutex;
    pthread_cond_t _p_cond;//给生产者的
    pthread_cond_t _c_cond;//消费者

    // int _consumer_water_line;// capacity / 3 * 2
    // int _productor_water_line;//capacity / 3
};