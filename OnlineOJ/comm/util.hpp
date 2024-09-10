#pragma once 

#include<iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <sys/time.h>
//原子变量的头文件
#include <atomic>

//文件流头文件
#include <fstream>

namespace ns_util
{
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

        static std::string GetTimeMs()//获取时间戳
        {
            struct timeval _time;
            gettimeofday(&_time,nullptr);
            
            return std::to_string(_time.tv_sec * 1000 + _time.tv_usec / 1000);//1000ms = 1s(ms * 1000 -> s)、 1000us = 1ms
        }

    };
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

        static std::string UniqFileName()
        {
            //毫秒级时间戳 + 原子性递增唯一值 来保证唯一性
            static std::atomic_uint id(0);
            std::string ms = TimeUtil::GetTimeMs();
            std::string unique_id = std::to_string(id);
            return ms + "_" + unique_id;
        }

//将用户代码content写进指定文件filename中
        static bool WriteFile(const std::string& filename,const std::string& content)
        {
            //创建输出流ofstream，打开filename文件
            std::ofstream out(filename);
            if(!out.is_open()){
                return false;
            }

//将content内容写进filename文件中
            out.write(content.c_str(),content.size());
            out.close();//关闭文件 
            return true;
        }

        static bool ReadFile(const std::string& filename,std::string* content,bool keep = false)//将读取的内容通过content输出出去
        {
            std::ifstream in(filename);//打开 输入流 
            if(!in.is_open()){
                return false;
            }

            std::string line;
            //getline一次读取一行，但注意的时他会把\n给移除
            //getline 会强制类型转换 为 bool
            while(std::getline(in,line))//通过getline读取in中一行的内容，每读取一行后会往后移只到最后
            {
                (*content) += line;
                (*content) += (keep ? "\n" : "");//判断keep，是否要\n若想要就需要把getline移除的\n补上
            }
            in.close();
            return false;
        } 
    };


    class StringUtil
    {
        public:
        static void SplitString(const std::string& str,std::vector<std::string> *target,const std::string& sep)
        {
            int left = 0, r = 0;
            for(r = 1; r < str.size() ;r++){
                if(str[r] == *sep.c_str()){
                    target->push_back(str.substr(left,r-left));
                    left = r + 1;
                }
            }
            target->push_back(str.substr(left,r-left));
        }
    };


} // namespace ns_util



