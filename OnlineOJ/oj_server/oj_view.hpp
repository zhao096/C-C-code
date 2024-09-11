#pragma once

#include <iostream>

#include "oj_model.hpp"
#include <ctemplate/template.h>

namespace ns_view
{
    //将获取的数据形成html网页
    using namespace ns_model;

    const std::string template_path = "./template/";
    class View
    {
        public:
        View();
        ~View();

        void AllExpandHtml(std::vector<Question>& questions,std::string* html)
        {
            std::string src_html = template_path + "all_questions";
            ctemplate::TemplateDictionary root(all_questions);

            for(auto& q : questions)
            {
                ctemplate::TemplateDictionary *sub = root.AddSectionDictionary("question_list");
                sub.SetValue("number",q.number);
                sub.SetValue("title",q.title);
                sub.SetValue("star",q.star);
            }
            //渲染
            ctemplate::Template *tpl =  ctemplate::Template::GetTemplate(html,ctemplate::DO_NOT_STRIP);

            tpl->Expand(html,&root);
        }

        void OneExpandHtml(Question& q,std::string* html)
        {

        }

    };

}