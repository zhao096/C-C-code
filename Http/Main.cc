#include "Socket.hpp"
#include "TcpServer.hpp"
#include "HttpProtocol.hpp"

#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>

#include <memory>
#include <string.h>
#include <pthread.h>
#include <fstream>

using namespace std;


string SuffixToType(const string &suffix)
{
    if (suffix == ".html" || suffix == ".htm")
        return "text/html";
    else if (suffix == ".png")
        return "image/png";
    else if (suffix == ".jpg")
        return "image/jpg";
    else
    {
        return "text/html";
    }
}

string CodetoDesc(int code)
{
    switch(code)
    {
        case 200:
            return "OK";
        case 301:
            return "Move Permanently";
        case 307:
            return "Temporary Redirect";
        case 403:
            return "Forbidden";
        case 404:
            return "Not Found";
        case 500:
            return "Internal Server Error";
        default:
            return "Unknow";
    }
}

string HandlerRequest(string &request)
{
    HttpRequest req;
    req.DeSerialize(request);
    // req.DebugDeser();

    int code = 200;

    req.Parse(); // 处理报头将报头解析成 method url http_version
    // req.DebugParse();

    string content = req.GetFileContent();
    if (!content.empty())
    {
        code = 404;
        content = req.Get404();
    }

    // code = 307;//重定向到location网页
    
    HttpResponse resp;
    resp.SetCode(code);
    resp.SetDesc(CodetoDesc(code));
    resp.MakeStatusLine();
    string content_len_str = "Content-Length: " + to_string(content.size()) + "\r\n";
    resp.Addheader(content_len_str);
    string content_type_str = "Content-Type: " + SuffixToType(req.Suffix()) + "\r\n";
    resp.Addheader(content_type_str);
    
    string location = "Location: http://www.qq.com/\sr\n";
    resp.Addheader(location);

    resp.AddContent(content);
    return resp.Serialize();
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