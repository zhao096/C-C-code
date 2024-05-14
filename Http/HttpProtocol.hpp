#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

const string Dep = "\r\n";
const string homepage = "index.html";
const string wwwroot = "./wwwroot";

using namespace std;
class HttpRequest
{
public:
    HttpRequest():_req_blank(Dep),_path(wwwroot)
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
    bool DeSerialize(string& request)
    {
        string line;
        bool ok = Getline(request,&line);
        if(!ok) return false;
        _req_line = line;
        while(true)
        {
            bool ok = Getline(request,&line);
            if(ok && line.empty())//若ok 且 line为空则表示报头信息已读完
            {
                _req_content = request;//剩下的就是正文部分
                break;
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
        return true;
    }

    void DebugDeser()
    {
        cout << _req_line << endl;

        for(auto head : _req_header)
        {
            cout << head << endl;
        }

        cout << _req_content << endl;
    }

    void ParseReqLine()
    {
        stringstream ss(_req_line);
        ss >> _method >> _url >> _http_version;//以空格为分隔符分别给到他们

        if(_url == "/")
        {
            _path += "/";
            _path += homepage;
        }
        else
        {
            _path += _url;
        }
    }

    void DebugParse()
    {
        cout << "_req_line:" <<_req_line << endl;

        cout << "_method:" <<_method << endl;
        cout << "_url:" <<_url << endl;
        cout << "_http_version:" <<_http_version << endl;
        cout << "_path:" <<_path << endl;
    }
    void ParseSuffix()
    {
        auto pos = _path.rfind(".");
        if(pos == string::npos) _suffix = ".html";
        _suffix = _path.substr(pos);
    }

    void Parse()
    {
        //1. 分析请求行
        ParseReqLine();

        //2.提前后缀
        ParseSuffix();
    }
    


string GetFileContentHelper(const string& path)
{
    // ifstream in(path, ios::binary);
    // if (!in.is_open())
    //     return "";

    // string content;
    // string line;
    // while (getline(in,line))//BUG   
    // {
    //     content += line;//二进制中可能有\0导致数据读取错误！
    // }
    
    // in.close();
    // return content;

    // ifstream in(path,ios::binary);

    std::ifstream in(path, std::ios::binary);
    if(!in.is_open()) return "";
    in.seekg(0,in.end);//将读取位置移动到末尾
    int filesize = in.tellg();//通过偏移量获取文件大小
    in.seekg(0,in.beg);//再将偏移量移回来


    string content;
    content.resize(filesize);
    in.read((char*)content.c_str(),filesize);


    in.close();
    return content;    
}

string GetFileContent()
{
    return GetFileContentHelper(_path);
}

string Get404()
{
    return GetFileContentHelper("./wwwroot/404.html");
}

    void DebugRequest()
    {
        cout << "_req_line: " << _req_line << endl;
        for(auto line : _req_header)
        {
            cout << "---->: " << line << endl;
        }
        cout << "_req_blank: " << _req_blank << endl;
        cout << "_req_content: "<< _req_content << endl;

        cout << "Method" << _method << endl;
        cout << "Url" << _url << endl;
        cout << "Http_version" << _http_version << endl;
    }
    string Url()
    {
        return _url;
    }
    string Path()
    {
        return _path;
    }

    string Suffix()
    {
        return _suffix;
    }

    ~HttpRequest()
    {}
private:
//报头字段
    string _req_line;
    vector<string> _req_header;
    string _req_blank;
    string _req_content;

//
    string _method;
    string _url;
    string _http_version;
    string _path;//默认为./wwwroor

    string _suffix;//请求资源的后缀
};

const string BlankSep = " ";
const string LineSep = "\r\n";

class HttpResponse
{
public:
    HttpResponse():_http_version("HTTP/1.0"),_status_code(200),_status_code_desc("OK")
    {}

    void SetCode(int code)
    {
        _status_code = code;
    }

    void SetDesc(const string& desc)
    {
        _status_code_desc = desc;
    }

    void MakeStatusLine()
    {
        _req_line += _http_version + BlankSep + to_string(_status_code) + BlankSep + _status_code_desc + LineSep;
    }

    void Addheader(const string& header)
    {
        _req_header.push_back(header);
    }

    void AddContent(const string& content)
    {
        _content = content;
    }


    string Serialize()
    {
        string response = _req_line;
        for(auto& head:_req_header)
        {
            response += head;
        }
        response += _req_blank;
        return response;
    }

    ~HttpResponse()
    {}
private:
    string _req_line;
    vector<string> _req_header;
    string _req_blank;

    string _content;

//http_version Statuscode statusCodeDesc
    string _http_version;
    int _status_code;
    string _status_code_desc;
};