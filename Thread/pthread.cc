#include<iostream>
#include<string>
#include<pthread.h>
#include<unistd.h>
#include<vector>
#include<functional>
using namespace std;

using func_t = function<void()>;


//创建一个对象，其中包含了线程名，线程创建的时间，该线程所要执行的函数
class ThreadData
{
public:
    ThreadData(const string& name,const uint64_t & ctime,func_t f)
    :threadname(name),createtime(ctime),func(f)
    {}

public:
    string threadname;
    uint64_t createtime;
    func_t func;
};


void* ThreadRountine(void*arg)//创建一个线程后调用的函数，其中arg是参数，通过第四个参数传递进来
{ 
    ThreadData* td = static_cast<ThreadData*>(arg);//进行类型的强转成，对象
    while(true)
    {
        td->func();//对象中存着，真的调用的函数！

        cout << "threadname: "<< td->threadname << " create time: "<< td->createtime  <<endl;//通过对象访问成员变量
        sleep(1);

        if(td->threadname == "thread-4")//在4号进处出产生信号，观察情况
        {
            cout << td->threadname << " create exeption" << endl;
            int i = 1;
            i /= 0;
        }
    }
}

void Print()
{
    cout << "I am Thread of part: ";
}
const int cnt = 5;
int main()
{
    cout << "main thread" << endl;

    for(int i = 0; i < cnt ;i++)
    {
        sleep(1);
        char tname[64];
        snprintf(tname,sizeof(tname),"%s-%d","thread",i);//让每个下标对应一个进程名tname

        ThreadData* td = new ThreadData(tname,(uint64_t)time(nullptr),Print);//创建一个对象，并初始化
        pthread_t tid;
        pthread_create(&tid,nullptr,ThreadRountine,td);//创建进程
    }    

    while(true)
    {
        sleep(10);
    }

    return 0;
}


// void* ThreadRountine(void*arg)
// { 
//     string threadname = (const char*)arg;
//     while(true)
//     {
//         cout << "new thread" << "arg:"<< arg <<endl;
//         sleep(1);
//     }
// }

// int main()
// {
//     pthread_t tid;
//     pthread_create(&tid,nullptr,ThreadRountine,nullptr);

//     while(true)
//     {
//         cout << "main thread" << endl;
//         sleep(1);
//     }
//     return 0;
// }
