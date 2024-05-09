#pragma once

#include <iostream>
#include <memory>
using namespace std;
namespace Protocol
{
    const string ProtSep = " ";

    const string LineBreakSep = "\n";

    string Encode(const string&message)//"len\nx op y\n"
    {
        string len = to_string(message.size());
        string package = len + LineBreakSep + message + LineBreakSep;
        return package;
    }

//其中注意的是package不一定是一个完整的报文，他可能长了也可能短了，对此我们要进行处理！
//短了："len"、"len\nx" 
//长了："len\nx op y\n""len"、...
    bool Decode(string&package,string *message)
    {
        auto pos = package.find(LineBreakSep);//首先找到\n来确定len,若\n找不到则表示短了！
        if(pos == string::npos) return false;//\n都找不到直接返回错误！

//到了此处至少能取出len了！
        string lens = package.substr(0,pos);//取出字符串len
        int len =  stoi(lens);//将len转换成整形

//取出len后，计算长度，判断传递进来的字符串package和实际字符串长度
        int total = lens.size() + len + 2 * LineBreakSep.size();//字符串实际长度
//若
        if(total > package.size()) return false;//如果传递进来的长度小于实际长度则一定未完全将字符串传递过来！

        //否则则直接取出len长度的实际信息的字符串即可！
        *message = package.substr(pos + LineBreakSep.size() , len);
        //最后把取出的删除！
        package.erase(0,total);
        return true;
    }

    class Request
    {
    public:
        Request():_data_x(0),_data_y(0),_oper(0)
        {}
        Request(int x, int y, char op) : _data_x(x), _data_y(y), _oper(op)
        {}
        void Debeg()
        {
            cout << "_data_x: " << _data_x << endl;
            cout << "_data_y: " << _data_y << endl;
            cout << "_oper: " << _oper << endl;
        }
        void Inc()
        {
            _data_x++;
            _data_y++;
        }

        // 结构化数据 -> 字符串
        bool Serialize(string *out)
        {
            *out = to_string(_data_x) + ProtSep + _oper + ProtSep + to_string(_data_y);
            return 0;
        }

        bool DeSerialize(string &in) //"x op y"
        {
            auto left = in.find(ProtSep);
            if (left == string::npos)
                return false; // 表示没找到！
            auto right = in.rfind(ProtSep);
            if (right == string::npos)
                return false; // 表示没找到！

            _data_x = stoi(in.substr(0, left));
            _data_y = stoi(in.substr(right + ProtSep.size()));
            string oper = in.substr(left + ProtSep.size(), right - (left + ProtSep.size()));
            if (oper.size() != 1)
                return false;

            _oper = oper[0];
            return true;
        }
        int GetX(){return _data_x;}
        int GetY(){return _data_y;}
        char GetOper(){return _oper;}

    private:
        //"x op y\n",以\n结尾，当读取到\n表示当前报文读完了
        // len是报文字描述字段
        //"len"\n"x op y"，其中len可以理解成报文、后面的x op y理解成有效载荷
        // 并且len 后面加\n进行分隔，len就表述了后面有效载荷的数据长度（也就是要读取的长度）
        //"len\nx op y"
        int _data_x;
        int _data_y;
        char _oper; // + - *
    };

    class Response
    {
    public:
        Response():_result(0),_code(0)
        {}
        Response(int result, int code) : _result(result), _code(code)
        {}
        bool Serialize(string *out)
        {
            *out = to_string(_result) + ProtSep + to_string(_code);
            return true;
        }

        bool DeSerialize(string &in)
        {
            auto pos = in.find(ProtSep);
            if (pos == string::npos)
                return false; // 表示没找到！

            _result = stoi(in.substr(0, pos));
            _code = stoi(in.substr(pos + ProtSep.size()));
            return true;
        }
        void SetResult(int result) {_result = result;}
        void SetCode(int code) {_code = code;}

        int GetResult(){ return _result; }
        int GetCode(){ return _code; }

    private:
        int _result; 
        int _code;
    };

    // 简单的工厂模式
    class Factory
    {
    public:
        shared_ptr<Request> BuildRequest()
        {
            shared_ptr<Request> req = make_shared<Request>();
            return req;
        }

        shared_ptr<Request> BuildRequest(int x, int y, char op)
        {
            shared_ptr<Request> req = make_shared<Request>(x, y, op);
            return req;
        }

        shared_ptr<Response> BuildResponse()
        {
            shared_ptr<Response> resp = make_shared<Response>();
            return resp;
        }

        shared_ptr<Response> BuildResponse(int result, int code)
        {
            shared_ptr<Response> resp = make_shared<Response>(result, code);
            return resp;
        }
    };
}