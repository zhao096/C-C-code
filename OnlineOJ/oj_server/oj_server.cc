#include <iostream>

#include <signal.h>

#include "../comm/httplib.h"
#include "../comm/util.hpp"
#include "oj_control.hpp"

using namespace httplib;
using namespace ns_contrl;

static Contrl *ctrl_ptr = nullptr;

void Recovery(int id)
{
    ctrl_ptr->RecoveryMachine();//重启所有主机
}

int main()
{
    signal(SIGQUIT,Recovery);// Ctrl + \ ： 生成SIGQUIT信号，进行重启所有主机
    //oj_server用户的服务路由功能
    //1. 获取所有题目列表
    Server svr;

    Contrl ctrl;

    ctrl_ptr = &ctrl;//给信号用

    svr.Get("/all_questions",[&ctrl](const Request& req,Response& resp){
        std::string html;
        ctrl.AllQuestions(&html);
        resp.set_content(html,"text/html;charset=utf-8");
        
        // resp.set_content("所有题目列表","text/plaint;charset=utf-8");
    });
    //2. 用户根据题目编号 获取题目内容
    svr.Get(R"(/question/(\d+))",[&ctrl](const Request& req,Response& resp){
        std::string html;
        std::string number = req.matches[1];//会把正则表达式的内容存进matches 1中
        ctrl.Questions(number,&html);
        resp.set_content(html,"text/html;charset=utf-8");
    });
    //3. 用户提交代码，使用判题功能(1.每道题的测试用例 2.compile_run)
    //Get、Post请求方法
    svr.Post(R"(/judge/(\d+))",[&ctrl](const Request& req,Response& resp){
        std::string number = req.matches[1];//会把正则表达式的内容存进matches 1中
        std::string result_json; 
        ctrl.Judge(number,req.body,&result_json);
        resp.set_content(result_json,"application/json;charset=utf-8");
    });

    svr.set_base_dir("./wwwroot");

    svr.listen("0.0.0.0",8080);

    return 0;
}   
// using namespace ns_util;
// int main()
// {
//     std::vector<std::string> v;
//     StringUtil::SplitString(std::string("aasdas   basd c d"),&v," ");
//     for(auto&s : v)
//      std::cout << s << std::endl;
//     return 0;
// }