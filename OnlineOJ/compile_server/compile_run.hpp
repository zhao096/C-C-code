#pragma once 
#include <iostream>

//json的头文件
#include <jsoncpp/json/json.h>

#include "../comm/util.hpp"
#include "../comm/Log.hpp"
#include "./compile.hpp"
#include "./runner.hpp"

#include <signal.h>

#include <unistd.h>


namespace  ns_compile_and_run
{
    using namespace ns_util;
    using namespace ns_log;
    using namespace ns_compile;
    using namespace ns_runner;

    class CompileAndRun
    {
        private:
            CompileAndRun();
            ~CompileAndRun();

        public:

            static void CleanTempFile(const std::string& filename)
            {
                std::string _src = PathUtil::Src(filename);
                if(FileUtil::IfFileExists(_src)) unlink(_src.c_str());
                
                std::string _compile_err = PathUtil::CompileErrer(filename);
                if(FileUtil::IfFileExists(_compile_err)) unlink(_compile_err.c_str());
                
                std::string _execute = PathUtil::Exe(filename);
                if(FileUtil::IfFileExists(_execute)) unlink(_execute.c_str());
                
                std::string _stderr = PathUtil::Stderr(filename);
                if(FileUtil::IfFileExists(_stderr)) unlink(_stderr.c_str());

                std::string _stdout = PathUtil::Stdout(filename);
                if(FileUtil::IfFileExists(_stdout)) unlink(_stdout.c_str());

                std::string _stdin = PathUtil::Stdin(filename);
                if(FileUtil::IfFileExists(_stdin)) unlink(_stdin.c_str());
            }

            static std::string CodeToDesc(int code,const std::string& filename)
            {
                std::string desc;
                //code > 0 进程收到信号导致异常崩溃 
                //code < 0 非运行时报错(代码为空，编译错误)
                //code == 0  整过过程全部完成
                switch(code)
                {
                    case 0:
                        desc = "编译运行成功";
                    break;
                    case -1:
                        desc = "提交代码为空";
                    break;
                    case -2:
                        desc = "未知错误";
                    break;
                    case -3:
                    {
                        //编译错误，将编译错误信息写在desc上
                        FileUtil::ReadFile(PathUtil::CompileErrer(filename),&desc,true);
                    }
                    break;
                    case SIGABRT:
                        desc = "内存超过范围";
                    break;
                    case SIGXCPU:
                        desc = "CPU使用超时";
                    break;
                    case SIGFPE:
                        desc = "浮点数溢出（除零错误）";
                    break;
                    default://待完善
                        desc = "未知错误,info:" + std::to_string(code);
                    break;
                }
                return desc;
            }
            /*
            *
            *in_json：获取的数据 code / input / cpu_limit / mem_limit
            *out_json：输出的结果
            */
            static void Start(const std::string& in_json, std::string* out_json)//compile_server给到Start，json序列，并且输出给回到compile_server
            {
                //反序列化得到用户的代码
                
                Json::Reader reader;//用于解析某个json字符串串

                Json::Value in_value;//将解析的串放到Value中，得到多个KV值
                reader.parse(in_json,in_value);//解析complieServer传来的json字串到in_value中

                std::string code = in_value["code"].asString();//获取用户的代码
                //资源限制交给上层
                std::string input = in_value["input"].asString();//获取输入

                int cpu_limit = in_value["cpu_limit"].asInt();//cpu限制
                int mem_limit = in_value["mem_limit"].asInt();//mem限制

                int status_code = 0;
                Json::Value out_value;
                std::string filename;
                int run_result;
                if(!code.size())
                {
                    //最后处理差错问题
                    status_code = -1;
                    goto END;
                }

                //获取用户文件后要先生成一个唯一的文件，并存放该code
                //形成唯一文件获得的文件名 
                //毫秒级时间戳 + 原子性递增唯一值 来保证唯一性
                filename = FileUtil::UniqFileName();//在文件工具中写一个新函数 用于形成唯一文件名
                //将这个唯一的文件中 存进用户的代码
                if(!FileUtil::WriteFile(PathUtil::Src(filename),code))//filename仅仅只是文件名还需把他转换成路径 生成临时文件到temp中
                {
                    //如果返回false表示就会进来表示文件写入代码失败
                    status_code = -2;//发生未知错误（不用给用户按到内部出错所以表示为未知错误）
                    goto END; 
                }

                //编译文件
                if(!Compiler::Compile(filename))//这里 只用传文件名！
                {
                    //编译文件失败
                    status_code = -3;
                    goto END;
                }
                //运行文件
                run_result = Runner::Run(filename,cpu_limit,mem_limit);
                if(run_result > 0)//Run返回>0 表示出错了 返回的是错误信号！
                {
                    status_code = run_result;
                }
                else if(run_result < 0)//表示内部错误
                {
                    status_code = -2;//发生未知错误（不用给用户按到内部出错所以表示为未知错误）
                }
                else{//run_result == 其实运行正常，运算结果生成在了stdout中
                    //设置json中的stdout 和 stderr
                    status_code = 0;
                }
                END:
                //1.设置code
                out_value["status"] = status_code;
                out_value["reason"] = CodeToDesc(status_code,filename);//状态表述
                //写一个CodeToDesc函数通过status获得状态描述！
                
                if(status_code == 0)//才设置json 中的 stdout、stderr
                {
                    //整个过程 完成
                    std::string _stdout; 
                    FileUtil::ReadFile(PathUtil::Stdout(filename),&_stdout,true);
                    out_value["stdout"] = _stdout;//写一个函数获取stdout中的数据 
                    
                    std::string _stderr;
                    FileUtil::ReadFile(PathUtil::Stderr(filename),&_stderr,true);
                    out_value["sterr"] = _stderr;//写一个函数获取stderr中的数据 
                }

                //序列化：
                Json::StyledWriter writer;
                *out_json = writer.write(out_value);

                CleanTempFile(filename);//清理临时文件
            }


    };


}
