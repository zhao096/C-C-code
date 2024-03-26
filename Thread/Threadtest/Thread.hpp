#pragma once
#include<iostream>
#include<string>
#include<functional>
#include<pthread.h>
using namespace std;

//typedef function<void()> func_t

//注意！！
//此处的修改，因为带有模板所以后面用该类型变成fun_t<T> 
template<class T>
using func_t = function<void(T)>;//返回值void 参数为;

//加上模板，这个类型是给传进来的参数数据data的！
template<class T>
class Thread
{
public:
    Thread(T data, func_t<T> func, const string& name)
    :_tid(0),_name(name),_isrunning(false),_func(func),_data(data)
    {}

//因为在类内的函数默认是有this指针的这样就会导致pthread_create的threadrotine的类型不匹配而导致的无法传参
//所以解决方法就是改成静态函数，但此时又不能使用成员变量了，所哟把参数args改成this传递进来！
    static void *ThreadRotine(void* args)
    {
        Thread *ts = static_cast<Thread*>(args);

        ts->_func(ts->_data);
        return nullptr;
    }

    bool Start()                                  
    {
        int n = pthread_create(&_tid,nullptr,ThreadRotine,this);
        if(n == 0)
        {
            _isrunning = true;
            return true;
        }
        else return false;
    }  

    string Threadname()
    {
        return _name;
    }


    bool Join()
    {
        if(!_isrunning) return true;
        int n = pthread_join(_tid,nullptr);
        if(n==0)
        {
            _isrunning = false;
            return true;
        }
        return false; 

    }

    bool Isrunning()
    {
        return _isrunning;
    }

    ~Thread()
    {}

private:
    string _name;
    func_t<T> _func;

    pthread_t _tid;//创建自动形成
    bool _isrunning;
    T _data;
    //pid_t tid;
};