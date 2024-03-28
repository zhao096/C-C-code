#pragma once

#include<iostream>
#include<cstdarg>
#include<string>
#include<ctime>
#include<unistd.h>

using namespace std;

enum{
    Debug = 0,
    Info,//常规信息
    Warning,//警告
    Error,//出现较小错误
    Fatal//重大错误
};

string LevelTostring(int level)
{
    switch(level)
    {
        case Debug:
            return "Debug";
        case Info:
            return "Info";
        case Warning:
            return "Waring";
        case Error:
             return "Error";
        case Fatal:
             return "Fatal";
        default:
            return "Unkown";
    }
}

class Log
{
public:
    Log()
    {}

    string TimeStampExlocalTime()
    {
        time_t currtime = time(nullptr);//time_t uint64

        struct tm* curr = localtime(&currtime);//成功返回struct tm结构体，失败则返回空

        char time_buffer[128];
        snprintf(time_buffer,sizeof(time_buffer),%d-%d-%d %d:%d:%daddr_t            
                    cur->tm_year,cur->tm_mon,cur->tm_mday,)

    }
//类c的一个日志接口
    void LogMessage(int level,const char* format,...)//可变参数列表，前面至少得有一个参数
    {
        va_list args;//相当于一个宏char*，得到可变参数
        va_start(args,format);
        //args就指向了可变参数列表 

        char content[1024];

    //直接获取可变参数列表中的所有数据并放到自己的缓冲区content中
        vsnprintf(content,sizeof(content),format,args);//int  vsnprintf(char  *str,  size_t size, const char *format,
        //va_list ap);
        uint64_t currtime = time(nullptr);//获取当前时间戳

        printf("[%s][%s]%s\n",LevelTostring(level).c_str(),
                        std::to_string(currtime).c_str(),content);

        



        va_end(args);//args = nullptr
    }
    ~Log()
    {}
    
};