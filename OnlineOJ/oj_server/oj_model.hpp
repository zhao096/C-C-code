#pragma once

#include <iostream>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <cassert>
#include "../comm/util.hpp"
#include "../comm/Log.hpp"
namespace ns_model
{
    using namespace ns_util;
    using namespace ns_log;

    struct  Question
    {
        std::string number;//提号
        std::string title;//题目名
        std::string star;//难易
        int cpu_limit;//时间限制
        int mem_limit;//空间限制
        std::string desc;//题目描述
        std::string header;//预制代码
        std::string tail;//测试代码
    };
    
    const std::string& question_list_path = "./questions/questions.list";
    const std::string& question_path = "./questions";

    class Model
    {
    private:
        std::unordered_map<std::string,Question> questions;//题号 ： 题目信息
    public:
        Model(){
            assert(LoadQuestionList(question_list_path));
        }
        ~Model()
        {

        }
        bool LoadQuestionList(const std::string& question_list)
        {
            std::ifstream in(question_list);//从question_list中 通过题号得知共用多少题，
            //并且将每一题的信息填进map中，通过文件获取 基础信息 和 desc题目描述，header默认代码，tail测试用例
            //基础信息 直接在question_list中得到 
            //desc题目描述，header默认代码，tail测试用例 在各自文件中获取
            if(!in.is_open())
            {
                return false;
                LOG(FATAL) << "加载题库失败，请检查是否存在题库文件" << "\n";
            }

            std::string line;
            while(getline(in,line))
            {
                Question q;
                std::vector<std::string> target;
                StringUtil::SplitString(line,&target," ");
                if(target.size() != 5)//属性一定是5个
                {
                    LOG(WARNING) << "加载部分题目失败，请检查questions文件内储存格式" <<  "\n";
                    continue;
                }
                //1 回文数 简单  1 30000
                q.number = target[0];
                q.title = target[1];
                q.star = target[2];
                q.cpu_limit = std::stoi(target[3]);
                q.mem_limit = std::stoi(target[4]);

                //desc题目描述，header默认代码，tail测试用例
                FileUtil::ReadFile(question_path+"/"+q.number+ "/desc.txt",&q.desc,true);
                FileUtil::ReadFile(question_path+"/"+q.number+ "/header.cpp",&q.header,true);
                FileUtil::ReadFile(question_path+"/"+q.number+ "/tail.cpp",&q.tail,true);

                questions.insert({q.number,q});
            }
            in.close();
            LOG(INFN) << "加载题库成功" <<  "\n";
            return true;
        }

        //获取所有题目
        bool GetAllQuestions(std::vector<Question>* out)
        {
            if(questions.size())
            {
                for(auto& k:questions)
                {
                    out->push_back(k.second);
                }
                return true;
            }
            LOG(ERROR) <<  "获取所有题目失败" << "\n";
            return false;
        }

        //获得某一题
        bool GetOneQuestion(const std::string& number,Question* q)
        {
            auto k = questions.find(number);
            if(k != questions.end()){
                (*q) = (k->second);
                return true;
            }
            LOG(ERROR) << "获取部分题目失败，题号为:" << number << "\n";
            return false;
        }
    };
}