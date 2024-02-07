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

int main()
{
    int i = 10;
    i /= 0;


    return 0;
}

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
