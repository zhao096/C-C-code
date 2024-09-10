#include <iostream>
#include <unistd.h>
#include <string>
#include "compile_run.hpp"

#include "../comm/httplib.h"//包上cpp-httplib头文件
using namespace ns_compile_and_run;
using namespace httplib;//使用命名空间



// #include <iostream>
// #include <cstdio>
// #include <string>
// #include <unistd.h>
// #include <arpa/inet.h>
// #include <netinet/in.h>
// #include <sys/socket.h>

// int main()
// {
//     int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//     if (sockfd < 0) {
//         perror("socket error");
//         return -1;
//     }

//     struct sockaddr_in addr;
//     addr.sin_family = AF_INET;
//     addr.sin_port = htons(8080);
//     addr.sin_addr.s_addr = inet_addr("0.0.0.0");
//     socklen_t len = sizeof(struct sockaddr_in);
//     int ret = bind(sockfd, (struct sockaddr*)&addr, len);
//     if (ret < 0) {
//         perror("bind error");
//         return -1;
//     }

//     ret = listen(sockfd, 5);
//     if (ret < 0) {
//         perror("listen error");
//         return -1;
//     }

//     while(1) {
//         int newfd = accept(sockfd, NULL, 0);
//         if (newfd < 0) {
//             perror("accept error");
//             return -1;
//         }

//         char buf[1024] = {0};
//         int ret = recv(newfd, buf, 1024, 0);
//         if (ret < 0) {
//             perror("recv error");
//             close(newfd);
//             continue;
//         }else if (ret == 0) {
//             perror("peer shutdown!");
//             close(newfd);
//             continue;
//         }

//         std::string body = "<html><body><h1>Hello World</h1></body></html>";
//         std::string rsp = "HTTP/1.1 200 OK\r\n";
//         rsp += "Content-Length: " + std::to_string(body.size()) + "\r\n";
//         rsp += "Content-Type: text/html\r\n";
//         rsp += "\r\n";
//         rsp += body;

//         ret = send(newfd, rsp.c_str(), rsp.size(), 0);
//         if (ret < 0) {
//             perror("send error!");
//             close(newfd);
//             continue;
//         }
//         close(newfd);
//     }
//     close(sockfd);
//     return 0;
// }

void Usage(const std::string& s1)
{
    std::cout << std::endl;
    std::cout << "\t" <<s1 << " port" << std::endl;
    std::cout << std::endl;

}


int main(int argc,char* argv[])
{
    if(argc != 2)
    {
        Usage(argv[0]);
        return 1;
    }

    //使用cpp-httplib
    Server svr;

    // svr.Get("/hello",[](const Request &req, Response &resp){
    //     // 用来进行基本测试
    //     std::cout << "正确接受请求" << std::endl;
    //     resp.set_content("hello httplib,你好 httplib!", "text/plain;charset=utf-8");
    // });

    svr.Post("/compile_server",[](const Request& req,Response& resp){
        std::string out_json;
        std::string in_json = req.body;
        if(!in_json.empty()){
            CompileAndRun::Start(in_json,&out_json);
            resp.set_content(out_json,"application/json;charset=utf-8");
        }
    });

    svr.listen("0.0.0.0",atoi(argv[1]));//启动

    // std::string code = "code";
    // compile::Compile(code);

    // Runner::Run(code,1,1024*1024);
    // return 0;

    //我们的目的是调用 compile_run 的 Strat
    //我们需要传参进去in_json
    //json中需要 code 、input（给上层预留的输入空间）、cpu_limit、mem_limit
    //变成string传进去
    // std::string in_json;

    //模拟用户网络上传递进来json串
    // Json::Value in_value;
    // in_value["code"] = R"(
    // #include<iostream>
    // using namespace std;
    // int main(){
    //     cout << "我的测试代码"<<endl;
    //     // while(1);
    //     // int *arr = new int[ 1024 * 1024 * 50];
    //     // int a = 10;
    //     // a /= 0;
    //     return 0;
    // })";
    // in_value["input"] = "";
    // in_value["cpu_limit"] = 1;
    // in_value["mem_limit"] = 10240 * 3;//输入的是 kb 存的是 Mb （所以超时1kb 就需要大于 1MB(1kb * 1024)）这里是限制的是30MB

    // Json::StyledWriter writer;
    // in_json = writer.write(in_value);

    // std::string out_json;
    // CompileAndRun::Start(in_json,&out_json);

    // std::cout << out_json << std::endl;
    return 0;
}

