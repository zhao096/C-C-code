#pragma once

#include "Socket.hpp"
#include <iostream>
#include <memory>
#include <functional>

using namespace std;

using fun_t = std::function<string(string &,bool* error_code)>;

class TcpServer;

class ThreadData
{
public:
    ThreadData(TcpServer* tcp_this,Socket* sockp):_this(tcp_this),_sockp(sockp)
    {}
    TcpServer* _this;
    Socket* _sockp;
};

class TcpServer
{
public:
    TcpServer(uint16_t port, fun_t request) : _port(port), _listensocket(new TcpSocket()), _handler_request(request)
    {
        _listensocket->BuildListenSocketMethod(port, backlog);
    }

    static void* PhreadRun(void*argv)//PthreadRun是个类的成员方法所以用static，不要this指针才能满足void* (*) (void*)
    {
        pthread_detach(pthread_self());
        ThreadData* td = static_cast<ThreadData*>(argv);
        string bufferin; 
        while(true)
        {
            bool ok = true;//用来确定是否出错
            //读取数据，不关心数据，只进行读
            //1.接收信息
            if(!td->_sockp->Recv(&bufferin,1024)) 
            {
                break;
            }
            //处理报文数据
            string send_string = td->_this->_handler_request(bufferin,&ok);//回调不仅会出去，还会回来！
            //读发送数据，不关心数据，只进行发送
            if(ok)
            {
                //发送数据
                if(!send_string.empty())
                {
                    td->_sockp->Send(send_string);
                }
            }
            else
            {
                break;
            }

        }
        td->_sockp->CloseFd();
        delete td->_sockp;
        delete td;
        return nullptr;
    }

    void loop()
    {
        for (;;)
        {
            string peerip;
            uint16_t peerport;
            Socket *newsock = _listensocket->AcceptConnection(&peerip, &peerport);//会返回Socket*
            if (newsock == nullptr)
            {
                cout << "AcceptConnection fail";
                continue;
            }
            cout << "获取一个新连接,sockfd:" << newsock->GetSockfd() << " client info:" << peerip << ":" << peerport;
            pthread_t tid;
            ThreadData* td = new ThreadData(this,newsock);
            pthread_create(&tid, nullptr, PhreadRun, td);
        }
    }
    ~TcpServer()
    {
        delete _listensocket;
    }

private:
    uint16_t _port;
    Socket *_listensocket;
public:
    fun_t _handler_request;
};