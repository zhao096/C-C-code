#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>
using namespace std;

//argc表示字符串的数量 argc = 1 + 用户输入的字符串数目
//argv表示一个二维数组
//argv[0]存的是可执行文件名称，剩下的就是直接输入的字符串

// int n , cnt = 0;

// void handler(int signo)
// {
    
// }


// int main()
// {
//     signal(14,handler);

//     alarm(30);


//     while(true)
//     {
//         sleep(1);
//     }

//     return 0;
// }

// int main()
// {
//     int i = 10;
//     i /= 0;

//     return 0;
// }

// void handler(int signo)
// {
//     cout << "捕获到信号第: "<< signo << "号信号"<< endl;
//     sleep(1);
//     exit(1);
// }

// int main(int argc,char* argv[])
// {
//     signal(2,handler);

//     raise(2);//给自己发送2号信号

//     sleep(10);//若没有被终止则会休眠10s
// }



// int main(int argc,char* argv[])
// {
//     if(argc != 3)
//     {
//         cout << "格式错误，因为为：./process signal processpid" << endl;
//         exit(0);
//     }
//     int signum = stoi(argv[1]+1);//传进来的是-9
//     int processpid= stoi(argv[2]);

//     kill(processpid,signum);//+1跳过-得到数字
//     return 0;
// }

// void handler(int signo)
// {
//     cout << "signo："<<signo << endl;
// }
// int main()
// {
//     cout << "getpid：" << getpid() << endl;
//     signal(2,handler);
//     sigset_t block,oblock;

//     sigemptyset(&block);
//     sigemptyset(&oblock);

//     for(int signo = 1; signo < 32 ;signo++)
//     {
//         sigaddset(&block,signo);
//     }

//     sigprocmask(SIG_SETMASK,&block,&oblock);//此处才修改了系统的信号屏蔽字

//     cout << "已经屏蔽所有信号" << endl;

//     while(true)
//     {
//         sleep(1);
//     }

//     return 0;
// }
// void PrintPending(const sigset_t& pending)
// {
//     for(int signo = 31; signo > 0  ;signo--)
//     {
//         if(sigismember(&pending,signo))//检查signo信号是否在pending位图中
//         {
//             cout << "1";
//         }
//         else
//         {
//             cout << "0";
//         }
//     }
//     cout << endl;
// }

// int main()
// {
//     signal(2,handler);

//     cout << "getpid：" << getpid() << endl;
//     sigset_t set,oset;
//     sigemptyset(&set);
//     sigemptyset(&oset);

//     sigaddset(&set,2);

//     sigprocmask(SIG_BLOCK,&set,&oset);

//     sigset_t pending;
//     int cnt = 0;
//     while(true)
//     {
//         sigpending(&pending);
//         PrintPending(pending);

//         sleep(1);

//         if(cnt == 5)
//         {
//             cout<< "解除屏蔽" <<endl;
//             sigprocmask(SIG_SETMASK,&oset,nullptr);
//         }
//         cnt++;
//     }

//     return 0;
// }



// int main()
// {
//     struct sigaction act,oact;

//     act.sa_handler = handler;//修改act的sa_handler

//     sigaction(2,&act,&oact);//对对应signum信号通过act修改handler表
//     while(true)
//     {
//         sleep(1);
//     }
//     return 0;
// }

// void Print(const sigset_t& pending)
// {
//     for(int signo = 31 ; signo > 0 ;signo--)
//     {
//         if(sigismember(&pending,signo))
//         {
//             cout << "1";
//         }
//         else
//         {
//             cout << "0";
//         }
//     }
//     cout << endl;
// }

// void handler(int signo)
// {
//     cout << "signo:" << signo << endl;
//     while(true)
//     {
//         sigset_t pending;
//         sigpending(&pending);//返回得到pending位图
//         Print(pending);
//         sleep(1);
//     }
// }


// int main()
// {
//     cout << "getpid：" << getpid() << endl;

//     struct sigaction act,oact;

//     sigemptyset(&act.sa_mask);
//     sigaddset(&act.sa_mask,3);//对3号信号进行了屏蔽
    
//     act.sa_handler = handler;//修改act的sa_handler


//     sigaction(2,&act,&oact);//对对应signum信号通过act修改handler表
    
//     while(true) sleep(1);
//     return 0;
// }

volatile int flag = 0;

void handler(int signo)
{
    cout << "signo:" << signo << endl;
    flag = 1;
    cout << "change flag to:" << flag << endl;
}

int main()
{
    signal(2,handler);
    cout << "getpid：" <<getpid()<< endl;
    while(!flag);
    cout << "success quit" << endl;
    return 0;
}

