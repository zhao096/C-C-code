#pragma once

#include <iostream>
#include <cstdarg>
#include <string>
#include <ctime>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

enum
{
    Debug = 0,
    Info,    // 常规信息
    Warning, // 警告
    Error,   // 出现较小错误
    Fatal    // 重大错误
};

string LevelTostring(int level)
{
    switch (level)
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

enum
{
    Screen = 10,
    OneFile,
    ClassFile
};

const int defaultstyle = Screen;
const string default_filename = "log.";
const string logdir = "log";
class Log
{
public:
    Log() : style(defaultstyle), filename(default_filename)
    {
        mkdir(logdir.c_str(),0775);//
    }

    string TimeStampExlocalTime()
    {
        time_t currtime = time(nullptr);        // time_t uint64
        struct tm *curr = localtime(&currtime); // 成功返回struct tm结构体，失败则返回空

        char time_buffer[128];
        snprintf(time_buffer, sizeof(time_buffer), "%d-%d-%d %d:%d:%d",
                 curr->tm_year + 1900, curr->tm_mon + 1, curr->tm_mday,
                 curr->tm_hour, curr->tm_min, curr->tm_sec);

        return time_buffer;
    }

    void Enable(int sty) // 设置打印风格
    {
        style = sty;
    }

    void WriteLogToOneFile(const string &logname, const string &message)
    {
        umask(0);
        int fd = open(logname.c_str(), O_CREAT | O_APPEND | O_WRONLY, 0666);
        if (fd < 0)
            return;

        write(fd, message.c_str(), message.size());
        close(fd);
        // ofstream out(logname);
        // if(!out.is_open())
        //     return;

        // out.write(message.c_str(),message.size());

        // out.close();
    }

    void WriteLogToClassFile(const string &levelstr, const string &message)
    {
        string logname = logdir;
        logname += "/";
        logname += filename;
        logname += levelstr; 

        WriteLogToOneFile(logname, message);
    }

    void WriteLog(const string &levelstr, const string &message)
    {
        switch (style)
        {
        case Screen:
            cout << message;
            break;
        case OneFile:
        {
            WriteLogToClassFile("all", message); // 所有的日志
            break;
        }
        case ClassFile:
            WriteLogToClassFile(levelstr, message); // 指定日志
            break;
        default:
            break;
        }
    }

    // 类c的一个日志接口
    void LogMessage(int level, const char *format, ...) // 可变参数列表，前面至少得有一个参数
    {
        va_list args; // 相当于一个宏char*，得到可变参数
        va_start(args, format);
        // args就指向了可变参数列表
        char rightbuff[1024];
        // 直接获取可变参数列表中的所有数据并放到自己的缓冲区rightbuff中
        vsnprintf(rightbuff, sizeof(rightbuff), format, args); // int  vsnprintf(char  *str,  size_t size, const char *format,
        // va_list ap);

        char leftbuff[1024];
        string Currtime = TimeStampExlocalTime(); // 获取当前时间戳
        string Level = LevelTostring(level);
        string Pid = to_string(getpid());
        snprintf(leftbuff, sizeof(leftbuff), "[%s][%s][%s] ",
                 Currtime.c_str(), Level.c_str(), Pid.c_str()); // int  vsnprintf(char  *str,  size_t size, const char *format,

        string loginfo = leftbuff;
        loginfo += rightbuff;

        //写一个日志！！
        WriteLog(Level, loginfo);
        // printf("%s%s\n",leftbuff,rightbuff);

        va_end(args); // args = nullptr
    }
    ~Log()
    {
    }

private:
    int style;
    string filename; // 文件名
};


Log lg;

class Conf
{
public:
    Conf()
    {
        lg.Enable(Screen);
    }
    ~Conf()
    {

    }

};

Conf conf;