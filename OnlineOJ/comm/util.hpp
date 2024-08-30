#pragma once 

#include<iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <sys/time.h>

namespace ns_util
{
    const std::string path_name = "./temp/";

    class PathUtil
    {
        static std::string AddSuffix(const std::string& filename,const std::string& suffix) 
        {
            std::string ret = path_name;
            ret += filename;
            ret += suffix;
            return ret;
        }
        public:
        //编译时用：
        static std::string Src(const std::string& filename)
        {
            return AddSuffix(filename,".cpp");
        }
        static std::string Exe(const std::string& filename)
        {
            return AddSuffix(filename,".exe");
        }
        static std::string CompileErrer(const std::string& filename)
        {
            return AddSuffix(filename,".compile_error");
        }


        //运行时用：
        static std::string Stdin(const std::string& filename)
        {
            return AddSuffix(filename,".stdin");
        }
        static std::string Stdout(const std::string& filename)
        {
            return AddSuffix(filename,".stdout");
        }
        static std::string Stderr(const std::string& filename)
        {
            return AddSuffix(filename,".stderr");
        }
    };

    class FileUtil{
        public:
        static bool IfFileExists(const std::string& pathname)
        {
            //使用stat函数
            //int stat(const char *path, struct stat *buf);
            //On success, zero is returned.  On error, -1 is returned, and  errno is set appropriately.
            struct stat st;
            // return stat(PathUtil::Stderr(filename).c_str(),&st) == 0 ? true : false;
            if(stat(pathname.c_str(),&st) == 0)
            {
                //获取属性成功,就表示文件存在了
                return true;
            }
            return false;
        }
    };

    class TimeUtil{
        public:
        static std::string GetTimeStamp()//获取时间戳
        {
            //int gettimeofday(struct timeval *restrict tp, void *restrict tzp);
            // struct timeval* _time;
            // gettimeofday(_time,nullptr);  
            //不行的会野指针！！
            struct timeval _time;
            gettimeofday(&_time,nullptr);
            
            return std::to_string(_time.tv_sec);
        }

    };

} // namespace ns_util
