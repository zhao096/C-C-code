#pragma once
#include<iostream>
enum 
{
    ok = 0,
    div_zero,
    mod_zero,
    unknow
};


class Task
{
public:
    Task()
    {}

    Task(int x, int y ,char op)
    :_x(x),_y(y),_oper(op)
    {}

    void Run()
    {
        switch (_oper)
        {
            case '+':
                result = _x + _y;
                break;
            case '-':
                result = _x - _y;
                break;
            case '*':
                result = _x * _y;

                break;
            case '/':
            {
                if(_y == 0) {
                    code = div_zero; 
                    break;
                }
                result = _x / _y;
            }
            break;
            case '%':
            {
                if(_y == 0)  {
                    code = mod_zero; 
                    break;
                }
                result = _x % _y;
            }
            break;
            default:
                code = unknow;
                break;
        }
    }

    string PrintTask()
    {
        string s;
        s += to_string(_x);
        s += _oper;
        s += to_string(_y);
        s += "=?";

        return s;
    }
    void operator()()
    {
        Run();
    }
    string PrintResult()
    {
        string s;

        s += to_string(_x);
        s += _oper;
        s += to_string(_y);
        s += " =";
        s += to_string(result);
        s+= " [";
        s+= to_string(code);
        s+= "]";
       
        return s;
    }

    ~Task()
    {}

private:
    int _x;
    int _y;
    char _oper;

    int result;
    int code;//任务退出码，0结果可信，!0结果不可信
};