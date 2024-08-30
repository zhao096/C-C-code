// 负责主要的编译逻辑
#pragma once 

#include <iostream>
#include <unistd.h>
#include "../comm/util.hpp"
#include "../comm/Log.hpp"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/wait.h>

using namespace ns_util;
using namespace ns_log;

namespace ns_compile
{
    class compile
    {
    public:
        static bool Compile(const std::string& filename)
        {
            int pid = fork();
            if(pid < 0)//出错
            {
                LOG(ERROR) << "内部错误，子进程创建失败" << "\n";  
                return false;
            }
            else if(pid == 0)
            {
                //子进程
                //将错误信息存储到自己的错误文件中，使用dp2将标准错误 重定向到自己的文件
                //1. 打开一个自己的文件

                umask(0);//将掩码设置为0，这样设置 出来的权限是相对准确的不会受平台的影响
                int _stderr = open(PathUtil::CompileErrer(filename).c_str(),O_CREAT | O_WRONLY,0644);
                //O_CREAT 若欲打开的文件不存在则自动建立该文件.
                //O_WRONLY 以只写方式打开文件
                //默认权限0644
                if(_stderr < 0)//打开失败
                {
                    LOG(WARNING) << "没有成功形成CompileErrer文件 " << "\n";
                    exit(1);
                }
                //2. 使用dp2将标准错误 重定向到自己的文件
                dup2(_stderr,2);
                //需要完成的任务是：
                //1. 实现编译功能 通过调用 excel 函数！
                        //g++      g++ -o target src -std==c++11 （target ： ./temp/1234.exe）
                        //用的工具 参数
                //2. 在excelp中前还需要先把文件名进行处理！ 
                //      对此就需要新在comm中写一个utile库！并创建对路径处理的类 把给的文件名 变成 加路径和后缀的！
                execlp("g++","g++","-o",PathUtil::Exe(filename).c_str(),\
                PathUtil::Src(filename).c_str(),"-std=c++11",nullptr);

                LOG(ERROR) << "启动编译器g++失败，可能是参数错误" << "\n";
                exit(2);
            }
            else{//父进程
                //1. 等待子进程
                waitpid(pid,nullptr,0);
                if(FileUtil::IfFileExists(PathUtil::Exe(filename)))//检查是否生成可执行程序
                {
                    LOG(INFO) <<  PathUtil::Src(filename) << "编译成功" << "\n";
                    return true;
                }

                LOG(ERROR) <<  "编译失败，没有形成可执行程序" << "\n";
                return false;
            }
        }
    };
    

    



}