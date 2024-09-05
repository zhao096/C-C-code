#include <iostream>

#include "compile_run.hpp"
using namespace ns_compile_and_run;
int main()
{
    // std::string code = "code";
    // compile::Compile(code);

    // Runner::Run(code,1,1024*1024);
    // return 0;

    //我们的目的是调用 compile_run 的 Strat
    //我们需要传参进去in_json
    //json中需要 code 、input（给上层预留的输入空间）、cpu_limit、mem_limit
    //变成string传进去
    std::string in_json;

    //模拟用户网络上传递进来json串
    Json::Value in_value;
    in_value["code"] = R"(
    #include<iostream>
    using namespace std;
    int main(){
        cout << "我的测试代码"<<endl;
        // while(1);
        // int *arr = new int[ 1024 * 1024 * 50];
        int a = 10;
        a /= 0;
        return 0;
    })";
    in_value["input"] = "";
    in_value["cpu_limit"] = 1;
    in_value["mem_limit"] = 10240 * 3;//输入的是 kb 存的是 Mb （所以超时1kb 就需要大于 1MB(1kb * 1024)）这里是限制的是30MB

    Json::StyledWriter writer;
    in_json = writer.write(in_value);

    std::string out_json;
    CompileAndRun::Start(in_json,&out_json); 

    std::cout << out_json << std::endl;
    return 0;
}