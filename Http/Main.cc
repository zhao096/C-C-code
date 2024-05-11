#include "Socket.hpp"
#include "TcpServer.hpp"
#include "HttpProtocol.hpp"

#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>

#include <memory> 
#include <string.h>
#include <pthread.h>

using namespace std;


string HandlerRequest(string& request)
{
    HttpRequest req;
    req.DeSerialize(request);
    req.DebugRequest();


    string content = "<html><h1>hello bit<h1><html>";
    string httpstatusline = "Http/1.0 200 OK\r\n";
    string httpheader = "Content-Length: " + to_string(content.size()) + "\r\n";
    httpheader = "\r\n";

    string httpresponse = httpstatusline + httpheader + content;
    return httpresponse;
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