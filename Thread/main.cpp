#include<iostream>
#include<thread>
#include<cstdlib>
#include"LockGuard.hpp"
#include"Thread.hpp"
#include<unistd.h>
#include<vector>
#include<string>
using namespace std;
// 应用方的视角

//为了能同时传递线程名和锁变量
//就构建ThreadData类，让其可以直接一起传递进去
class ThreadData
{
public:
    ThreadData(string& name,pthread_mutex_t* lock)
    :threadname(name),pmutex(lock)
    {}
public:
    string threadname;
    pthread_mutex_t * pmutex;
};

void Print(int num)
{
    while (num)
    {
        std::cout << "hello world: " << num-- << std::endl;
        sleep(1);
    }
}

int ticket = 10000; // 全局的共享资源

// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //全局锁，不用init初始化

void GetTicket(ThreadData *td)//抢票原理：
{
    while (true)
    {

        {   //通过花括号括其来的部分为一个代码块也就是确定了临界区

            //pthread_mutex_lock(mutex);//加锁
            LockGuard lockguard(td->pmutex);
            //LockGuard类会自动的申请锁，并且释放锁（因为当他构造和析构时就会执行加锁解锁操作！）
            if (ticket > 0) // 4. 一个线程在临界区中访问临界资源的时候，可不可能发生切换?可能，完全允许！！
            {
                // 充当抢票花费的时间
                usleep(1000);
                printf("%s get a ticket: %d\n",td->threadname.c_str(),ticket);
                ticket--;
                // pthread_mutex_unlock(mutex);//解锁
            }
            else
            {
                // pthread_mutex_unlock(mutex);//解锁
                break;
            }
        }

    }
}

string GetThreadName()
{
    static int number = 1;
    char name[64];
    snprintf(name, sizeof(name), "Thread-%d", number++);
    return name;
}

int main()
{
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex,nullptr);

    string name1 = GetThreadName();
    ThreadData *td1 = new ThreadData(name1,&mutex);//构造类

    Thread<ThreadData*> t1(td1, GetTicket,name1);
    //把ThreadData这个类做参数传递进去，在内部就能同时拿到

    string name2 = GetThreadName();
    ThreadData *td2 = new ThreadData(name2,&mutex);
    Thread<ThreadData*> t2(td2,GetTicket,name2);

    string name3 = GetThreadName();
    ThreadData *td3 = new ThreadData(name3,&mutex);
    Thread<ThreadData*> t3(td3, GetTicket, name3);

    string name4 = GetThreadName();
    ThreadData *td4 = new ThreadData(name4,&mutex);
    Thread<ThreadData*> t4(td4, GetTicket, name4);

    t1.Start();
    t2.Start();
    t3.Start();
    t4.Start();

    t1.Join();
    t2.Join();
    t3.Join();
    t4.Join();

    pthread_mutex_destroy(&mutex);

    delete td1;
    delete td2;
    delete td3;
    delete td4;

    return 0;
}

// string GetThreadname()
// {
//     static int number = 1;//本质就是全局变量
//     char name[64];
//     snprintf(name,sizeof(name),"thread-%d",number++);
//     return name;
// }

// void Print(int num)
// {
//     while(num)
//     {
//         cout << "hello Linux: " << num-- <<  endl;
//         sleep(1);
//     }

// }
// int main()
// {
//     Thread<int> t(10,Print,GetThreadname());

//     t.Start();

//     t.Join();

//     // const int num = 5;
//     // vector<Thread> threads;

//     // for(int i = 0 ; i < num ;i++)
//     // {
//     //     threads.push_back(Thread(Print,GetThreadname()));
//     // }

//     // for(auto &t : threads)
//     // {
//     //     cout << t.Threadname() << " is,running：" << t.Isrunning() <<endl;
//     // }


//     // sleep(5);
//     // for(auto &t:threads)
//     // {
//     //     t.Start();
//     // }

//     // for(auto &t : threads)
//     // {
//     //     cout << t.Threadname() << " is,running：" << t.Isrunning() <<endl;
//     // }

//     // for(auto &t : threads)
//     // {
//     //     t.Join();
//     // }

//     // Thread t(Print,GetThreadname());
//     // cout << "is thread running?: " << t.Isrunning() << endl;
//     // t.Start();

//     // cout << "is thread running?: " << t.Isrunning() << endl;

//     // t.Join();

//     return 0;
// }