#include "Protocol.hpp"
#include "Socket.hpp"
#include "TcpServer.hpp"
#include "Calculate.hpp"

#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>

#include <memory> 

#include <pthread.h>

using namespace std;
using namespace CalCulateNS;
using namespace Protocol;


// int main(int argc,char* argv[])
// {
//     if(argc != 2)
//     {
//         cout << "Usage:" << argv[0] << " port" << endl;
//         return 0;
//     }

//     uint16_t localport = stoi(argv[1]);

//     Socket* listensocket = new TcpSocket();
//     listensocket->BuildListenSocketMethod(localport,backlog);

//     for(;;)
//     {
//         string peerip;
//         uint16_t peerport;
//         Socket* newsock = listensocket->AcceptConnection(&peerip,&peerport);
//         cout << "获取一个新连接,sockfd:" << newsock->GetSockfd() << " client info:" << peerip << ":" <<peerport;
//         sleep(5);
//         newsock->CloseFd();
//     }
//     return 0;
// }

// bool HandlerRequest(Socket *sockp)
// {
//     // while (true)
//     // {
//     //     struct Protocol::Request req;
//     //     recv(sockp->GetSockfd(), &req, sizeof(req), 0);
//     //     req.Debeg();
//     // }
//     Calculate calculate;
//     string bufferin; 
//     unique_ptr<Protocol::Factory> fact;
//     auto req = fact->BuildRequest();
//     // while(true)
//     // {
//     //     //1.接收信息
//     //     if(!sockp->Recv(&bufferin,1024)) return false;
//     //     //2.分析字节流，查看是否为一个完整的报文
//     //     string message;
//     //     if(!Protocol::Decode(bufferin,&message)) continue;//若提取不成功则继续再次提取
//     //     //3.读取到一个报文后进行反序列化
//     //     if(!req->DeSerialize(message)) return false;//若反序列不成功则表示数据不正常直接退出
//     //     //到达这里后，表示着以及成功的把字符串转换成了一个结构化数据放到结构体中
//     //     //4.数据以及拿到了，所以就能进行 业务处理了！
//     //     auto resq = calculate.Cal(req);
//     //     //5. 得到resq,序列化
//     //     string send_str;
//     //     resq->Serialize(&send_str);
//     //     //序列化后得到字符串 "result code"
//     //     //6. 拼接len\n，形成字符串级别的相应报文
//     //     send_str = Encode(send_str);
//     //     // 7. 发送
//     // }

// }

string HandlerRequest(string & inbufferstream,bool* error_code)
{
    *error_code = true;//数据没问题，只是读取不够，所以返回true
    //计算机对象
    Calculate calculate;
    //构建相应对象
    unique_ptr<Factory> fact(new Factory());
    auto req = fact->BuildRequest();

    string message;
    // if(!Protocol::Decode(inbufferstream,&message))//若提取不成功则继续再次提取
    // {
    //     *error_code = true;//数据没问题，只是读取不够，所以返回true
    //     return string();
    // }
    // //3.读取到一个报文后进行反序列化
    // if(!req->DeSerialize(message))
    // {
    //     *error_code = false;//不可容忍的错误！
    //     return string();
    // }
    // //4.数据拿到了，所以就能进行 业务处理了！
    // auto resq = calculate.Cal(req);
    // //5. 得到resq,序列化
    // string send_str;
    // resq->Serialize(&send_str);
    // //序列化后得到字符串 "result code"
    // //6. 拼接len\n，形成字符串级别的相应报文
    // send_str = Encode(send_str);
    // // 7. 发送
    // return send_str;

    string total_resp_string;
    while(Decode(inbufferstream,&message))//只有解析成功才往后
    {
        if(!req->DeSerialize(message))
        {
            *error_code = false;//不可容忍的错误！
            return string();
        }
        auto resq = calculate.Cal(req);
        //5. 得到resq,序列化
        string send_str;
        resq->Serialize(&send_str);
        //序列化后得到字符串 "result code"
        //6. 拼接len\n，形成字符串级别的相应报文
        send_str = Encode(send_str);

        // 7. 发送
        total_resp_string += send_str;
    }
    cout << "total_resp_string: " <<total_resp_string << endl;
    return total_resp_string;
}
 
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Usage:" << argv[0] << " port" << endl;
        return 0;
    }

    uint16_t localport = stoi(argv[1]);
    unique_ptr<TcpServer> svr(new TcpServer(localport, HandlerRequest));
    svr->loop();

    return 0;
}