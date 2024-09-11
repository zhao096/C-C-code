#pragma once
#include <iostream>
#include <string>
#include "oj_model.hpp"
#include "oj_view.hpp"

namespace ns_contrl
{
    using namespace ns_model;
    using namespace ns_view;
    class Contrl
    {
        private:
            Model _model;
            View view;
        public:
            Contrl();
            ~Contrl();

            bool AllQuestions(std::string* html)
            {
                std::vector<struct Question> qs; 
                if(_model.GetAllQuestions(&qs))
                {
                    //将所有的题目数据构成网页（使用view的功能）
                    view.AllExpandHtml(qs,html);
                }
                else
                {
                    *html = "获取题目失败，形成题目列表失败";
                }
            }

             bool Questions(const std::string & number,std::string* html)
            {
                Question q; 
                if(_model.GetOneQuestion(number,&q))
                {
                    view.OneExpandHtml(q,html);
                }
                else
                {
                    *html =  "指定题目"+ number+ "不存在";
                }
            }
    };


}