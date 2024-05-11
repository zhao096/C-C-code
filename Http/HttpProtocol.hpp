#pragma once

#include <string>
#include <iostream>
#include <vector>

const string Dep = "\r\n";

using namespace std;
class HttpRequest
{
public:
    HttpRequest():_req_blank(Dep)
    {
    }

    bool Getline(string& request,string *out)
    {
        auto pos = request.find(Dep);
        if(pos == string::npos)
            return false;
        *out = request.substr(0,pos);
        request.erase(0,pos+Dep.size());
        return true;
    }
    void DeSerialize(string& request)
    {
        string line;
        bool ok = Getline(request,&line);
        if(!ok) return;
        _req_line = line;
        while(true)
        {
            bool ok = Getline(request,&line);
            if(ok && line.empty())//若ok 且 line为空则表示报头信息已读完
            {
                _req_content = request;
                return;
            }
            else if(ok && !line.empty())
            {
                _req_header.push_back(line);
            }
            else
            {
                break;
            }
        }
    }

    void DebugRequest()
    {
        cout << "_req_line: " << _req_line << endl;
        for(auto head : _req_header)
        {
            cout << "_req_header: " << head << endl;
        }
        cout << "_req_blank: " << _req_blank << endl;
        cout << "_req_content: "<< _req_content << endl;
    }

    ~HttpRequest()
    {}
private:
    string _req_line;
    vector<string> _req_header;
    string _req_blank;
    string _req_content;
};