#pragma once
#include <iostream>

//网络常用的四个头文件
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> 

#include <unistd.h>
#include <string.h>
#include <string>

using namespace std;
#define CONV(addrptr) ((struct sockaddr*)addrptr)


const static int sockdefault = -1;
const static int backlog = 5;

enum{
    SocketError = 1,
    BindError,
    ListenError 
};
//封装一个基类，socket接口类
//模板方法，设计模型
class Socket
{
public:
    virtual ~Socket(){}
    virtual void GreateSocket() = 0;
    virtual void BindSocketOrDie(uint16_t port) = 0;
    virtual void ListenSocketOrDie(int backlog) = 0;//       int listen(int sockfd, int backlog);
    virtual Socket* AcceptConnection(std::string* sockip,std::uint16_t* sockport) = 0;//输出型参数
    virtual bool ConnectServer(std::string& sockip,std::uint16_t sockport) = 0;
    virtual int GetSockfd() = 0;
    virtual void SetSockfd(int sockfd) = 0;
    virtual void CloseFd() = 0;
    virtual bool Recv(string* buffer, int size) = 0;
    virtual bool Send(string& buffer) = 0;
public:

    void BuildListenSocketMethod(uint16_t port,int backlog)
    {
        GreateSocket();
        BindSocketOrDie(port);  
        ListenSocketOrDie(backlog);
    }    
    bool BuildConnectSocketMethod(std::string& sockip,std::uint16_t& sockport)
    {
        GreateSocket();
        return ConnectServer(sockip,sockport);
    }
    void BuildNormalSocketMethod(int sockfd)
    {
        SetSockfd(sockfd);
    }
};

class TcpSocket : public Socket
{
public:
    TcpSocket(int sockfd = sockdefault):_sockfd(sockfd)
    {} 
    ~TcpSocket()
    {}

    void GreateSocket() override
    {   
        _sockfd = ::socket(AF_INET,SOCK_STREAM,0);
        if(_sockfd < 0) 
        {
            exit(SocketError);
            cout << "GreateSocket failed" << endl;
        }
    }

    void BindSocketOrDie(uint16_t port) override
    {
        struct sockaddr_in local;
        memset(&local,0,sizeof(local));
        local.sin_family = AF_INET;
        local.sin_addr.s_addr = INADDR_ANY;//不指定ip
        local.sin_port = htons(port);

        int n = ::bind(_sockfd,CONV(&local),sizeof(local));
        if(n < 0)
        {
            exit(BindError);
            cout << "BindError failed" << endl;
        } 
    }
    //int listen(int sockfd, int backlog);
    void ListenSocketOrDie(int backlog) override   
    {
        int n = ::listen(_sockfd,backlog);
        if(n < 0)
        {
            exit(ListenError);
            cout << "ListenError failed" << endl;
        } 
    }

    Socket* AcceptConnection(std::string* sockip,std::uint16_t* sockport) override
    {
        struct sockaddr_in addr;
        socklen_t len = sizeof(addr);
        int newsocket = accept(_sockfd,CONV(&addr),&len);
        if(newsocket < 0) return nullptr;

        Socket* s = new TcpSocket(newsocket);

        *sockport = ntohs(addr.sin_port); 
        *sockip = inet_ntoa(addr.sin_addr); 
        return s;
    }
    
    bool ConnectServer(std::string& sockip,std::uint16_t sockport) override
    {
        struct sockaddr_in server;
        memset(&server,0,sizeof(server));
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr(sockip.c_str());
        server.sin_port = htons(sockport);

        socklen_t len = sizeof(server);

        int n = connect(_sockfd,CONV(&server),len);//你这是啥？？
        //你是一个客户端，你为什么要accept？可能是写错了
        //改下为connect，应该就没啥问题了   还有什么问题吗？我先试下 好的，我先下了啊哈
        if(n == 0) return true;
        else return false;
    }

    int GetSockfd()
    {
        return _sockfd;
    }
    void SetSockfd(int sockfd)
    {
        _sockfd = sockfd;
    }

    void CloseFd() override
    {
        if(_sockfd > sockdefault) ::close(_sockfd);
    }

    bool Recv(string* buffer ,int size) override
    {
        char bufferin[size];
        size_t n = recv(_sockfd,bufferin,size-1,0);
        if(n > 0)
        {
            bufferin[n] =0;
            *buffer += bufferin;//此处是+=故意让其拼接！
            return true;
        }
        return false;
    }

    bool Send(string& buffer)override
    {
        send(_sockfd,buffer.c_str(),buffer.size(),0);
        return true;
    }
    
private:
    int _sockfd;
};