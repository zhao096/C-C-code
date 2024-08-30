#pragma once 
#include <iostream>

#include "../comm/Log.hpp"
#include "../comm/util.hpp"

//open 的头文件：
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//waitpid的头文件
// #include <sys/types.h>
#include <sys/wait.h>

namespace ns_runner{


    using namespace ns_log;
    using namespace ns_util;


    class Runner{
        private:
            Runner(){}
            ~Runner(){}
        public:
            static int Run(const std::string& file_name)
            {
                std::string _execute = PathUtil::Exe(file_name);//获取之前生成的可执行程序，来用来运行
                
                //将标准输入、输出、错误打开创建，用于存储运行后的结果
                //标准输入；暂不使用
                //标准输出： 将生成的结果输出到此处
                //标准错误：存储运行后的错误（所以我们需要把compile处使用的stderr改成complie_stderr）
                std::string _stdin = PathUtil::Stdin(file_name);
                std::string _stdout = PathUtil::Stdout(file_name);
                std::string _stderr = PathUtil::Stderr(file_name);

                //打开文件
                umask(0);//先重置掩码
                int _stdin_fd = open(_stdin.c_str(),O_CREAT | O_RDONLY , 0664);
                int _stdout_fd = open(_stdout.c_str(),O_CREAT | O_WRONLY , 0664);
                int _stderr_fd = open(_stderr.c_str(),O_CREAT | O_WRONLY , 0664);

                if(_stdin_fd < 0 || _stdout_fd < 0 || _stderr_fd < 0)//open返回<0表示错误
                {
                    LOG(ERROR) << "打开标准文件失败!" << "\n";
                    return -1;//表示打开文件错误！
                }

                //创建进程
                //其中当结束后要记住关文件
                int pid = fork();
                if(pid < 0)//创建失败
                {
                    close(_stdin_fd);
                    close(_stdout_fd);
                    close(_stderr_fd);
                    LOG(ERROR) << "创建子进程失败!" << "\n";
                    return -2;//创建子进程失败
                }
                else if(pid == 0)//子进程
                {
                    //注意要 dup2重定向文件
                    dup2(_stdin_fd,0);
                    dup2(_stdout_fd,1);
                    dup2(_stderr_fd,2);

                    //执行可执行程序
                    execl(_execute.c_str(),_execute.c_str(),nullptr);//execl(path,参数)
                    exit(1);//若执行失败直接终止程序
                }
                else{
                    close(_stdin_fd);
                    close(_stdout_fd);
                    close(_stderr_fd);

                    int status = 0;
                    waitpid(pid,&status,0);

                    LOG(INFO) << "运行完毕,info:" << (status & 0x7F) << "\n"; 
                    return status & 0x7F;
                }
            }

    };


}