#include "Protocol.hpp"
#include "Socket.hpp"

#include <sys/types.h>
#include <sys/socket.h>

#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <memory>
#include <iostream>
using namespace std;
using namespace Protocol;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Usage:" << argv[0] << "serverip serverport" << endl;
        return 0;
    }

    string serverip = argv[1];
    uint16_t serverport = stoi(argv[2]);

    Socket *conn = new TcpSocket();
    if (!conn->BuildConnectSocketMethod(serverip, serverport)) // BuildConnectSocketMethod ： GreateSocket、
    {
        cerr << "connect" << serverip << ":" << serverport << " failed" << endl;
        return 0;
    }
    cout << "connect" << serverip << ":" << serverport << " success" << endl;

    // unique_ptr<Factory> factory = make_unique<Factory>();
    unique_ptr<Protocol::Factory> factory(new Protocol::Factory());

    // while(true)
    // {
    //     // send(s->GetSockfd(), &(*rep), sizeof(*req), 0);
    //     send(conn->GetSockfd(), req.get(), sizeof(*req), 0);
    //     req->Inc();
    //     sleep(1);
    // }

    srand(time(nullptr) ^ getpid());
    string opers = "+-*/%^=!";
    while (true)
    {
        int x = rand() % 100;
        usleep(rand() % 7777);
        int y = rand() % 100;
        char oper = opers[rand() % opers.size()];

        shared_ptr<Protocol::Request> req = factory->BuildRequest(x, y, oper);

        // 1. 对req进行序列化
        string req_str;
        req->Serialize(&req_str);
        // for print
        string testptring = req_str;
        testptring += " ";
        testptring += "= ";

        // 2. 拼接报头
        req_str = Encode(req_str);

        // 3. 发送
        conn->Send(req_str);

        string resp_str;
        while (true)//当
        {
            // 4. 接收响应
            if(!conn->Recv(&resp_str, 1024)) break;

            // 5. 除去报头
            string message;
            if (!Decode(resp_str, &message)) continue;//错误说明短了所以继续再读
                

            cout << "Decode: " << message << endl;

            // 6. 得到了数据"result code"，将数据结构化
            auto resp = factory->BuildResponse();
            resp->DeSerialize(message);

            //7. 打印结果:
            cout << testptring << resp->GetResult() << "[" << resp->GetCode() << "]" << endl;
            break;
        }
        sleep(1);
    }
    conn->CloseFd();

    return 0;
}