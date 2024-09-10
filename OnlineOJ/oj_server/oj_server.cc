// #include <iostream>
#include "../comm/httplib.h"
#include "../comm/util.hpp"

// using namespace httplib;
// int main()
// {
//     //oj_server用户的服务路由功能
//     //1. 获取所有题目列表
//     Server svr;

//     svr.Get("/all_question",[](const Request& req,Response& resp){
//         resp.set_content("所有题目列表","text/plaint;charset=utf-8");
//     });
//     //2. 用户根据题目编号 获取题目内容
//     svr.Get(R"(/question/(\d+))",[](const Request& req,Response& resp){
//         std::string number = req.matches[1];//会把正则表达式的内容存进matches 1中
//         resp.set_content("选择的题号：" + number,"text/plaint;charset=utf-8");
//     });
//     //3. 用户提交代码，使用判题功能
//     svr.Get(R"(/judge/(\d+))",[](const Request& req,Response& resp){
//         std::string number = req.matches[1];//会把正则表达式的内容存进matches 1中
//         resp.set_content("判断的题号：" + number,"text/plaint;charset=utf-8");
//     });

//     svr.set_base_dir("./wwwroot");

//     svr.listen("0.0.0.0",8080);

//     return 0;
// }   
using namespace ns_util;
int main()
{
    std::vector<std::string> v;
    StringUtil::SplitString(std::string("aasdas   basd c d"),&v," ");
    for(auto&s : v)
     std::cout << s << std::endl;
    return 0;
}