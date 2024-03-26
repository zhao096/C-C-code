#pragma once
#include<iostream>
#include<vector>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#include"LockGuard.hpp"
using namespace std;

const int deaultsize = 5;

template<class T>
class RingQueue
{
private:
    void P(sem_t &sem)
    {
        sem_wait(&sem);//--
    }

    void V(sem_t &sem)
    {
        sem_post(&sem);//++
    }
public:
    RingQueue(int size = deaultsize)
    :_ringqueue(size),_size(size),_p_step(0),_c_step(0)
    {
        sem_init(&_space_sem,0,size);//对于空间来说空间信号量默认为size
        sem_init(&_data_sem,0,0);

        pthread_mutex_init(&_p_mutex,nullptr);
        pthread_mutex_init(&_c_mutex,nullptr);
    }



    void Push(const T &in)
    {
        P(_space_sem);
        //生产
        {
            LockGuard lockguard(&_c_mutex);
            _ringqueue[_p_step++] = in;
             _p_step %= _size;
        }
        V(_data_sem);

    }

    void Pop(T *out)
    {
        //先申请信号量
        P(_data_sem);
        //再加锁
        //这样就能让线程先把信号量都预定好自己的资源，后就能直接的使用了
        //否则只能申请到锁的才能申请信号量
        //相当于在申请锁之前，把所有的信号量分配完
        //当进入临界区后就能直接使用了

        //可以想象成电影院先把票都买好后直接排队进去
        {
            LockGuard lockguard(&_c_mutex);
            //消费
            *out = _ringqueue[_c_step++];
            _c_step %= _size;

        }
        V(_space_sem);


    }

    ~RingQueue()
    {

        sem_destroy(&_space_sem);//对于空间来说空间信号量默认为size
        sem_destroy(&_data_sem);


        pthread_mutex_destroy(&_p_mutex);
        pthread_mutex_destroy(&_c_mutex);
    }

private:
    vector<T> _ringqueue;
    int _size;

    int _p_step;//生产者的生产位置
    int _c_step;//消费位置

    sem_t _space_sem;//生产者
    sem_t _data_sem;//消费者

    pthread_mutex_t _p_mutex;
    pthread_mutex_t _c_mutex;

};