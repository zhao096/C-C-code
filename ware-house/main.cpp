#include<iostream>
#include<thread>
#include<cstdlib>
#include"Thread.hpp"
#include<unistd.h>
#include<vector>
using namespace std;

string GetThreadname()
{
    static int number = 1;//本质就是全局变量
    char name[64];
    snprintf(name,sizeof(name),"thread-%d",number++);
    return name;
}

void Print(int num)
{
    while(num)
    {
        cout << "hello Linux: " << num-- <<  endl;
        sleep(1);
    }

}
int main()
{
    Thread<int> t(10,Print,GetThreadname());

    t.Start();

    t.Join();

    // const int num = 5;
    // vector<Thread> threads;

    // for(int i = 0 ; i < num ;i++)
    // {
    //     threads.push_back(Thread(Print,GetThreadname()));
    // }

    // for(auto &t : threads)
    // {
    //     cout << t.Threadname() << " is,running：" << t.Isrunning() <<endl;
    // }


    // sleep(5);
    // for(auto &t:threads)
    // {
    //     t.Start();
    // }

    // for(auto &t : threads)
    // {
    //     cout << t.Threadname() << " is,running：" << t.Isrunning() <<endl;
    // }

    // for(auto &t : threads)
    // {
    //     t.Join();
    // }

    // Thread t(Print,GetThreadname());
    // cout << "is thread running?: " << t.Isrunning() << endl;
    // t.Start();

    // cout << "is thread running?: " << t.Isrunning() << endl;

    // t.Join();

    return 0;
}