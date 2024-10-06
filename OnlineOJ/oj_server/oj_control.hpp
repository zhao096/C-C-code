#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include "oj_model.hpp"
#include "oj_view.hpp"
#include "../comm/Log.hpp"
#include "../comm/util.hpp"

#include "../comm/httplib.h"//包上cpp-httplib头文件


#include <jsoncpp/json/json.h>

//c++的锁
#include <mutex>

namespace ns_contrl
{
    using namespace ns_model;
    using namespace ns_view;
    using namespace ns_log;
    using namespace ns_util;
    using namespace httplib;
    
    //定义机器的结构
    class Machine{
        public:
        std::string ip;
        int port;
        uint64_t load;//每台机器的负载情况
        std::mutex* mtx;//因为会将机器存进容器内部 就一定会有拷贝，而变量锁是不能被拷贝的，所以定义成指针
        
        public:
        Machine():ip(""),port(0),load(0),mtx(nullptr)
        {}
        ~Machine(){}

        void IncLoad()//increase
        {
            if(mtx) mtx->lock();
            ++load;
            if(mtx)  mtx->unlock();
        }
        
        void DecLoad()//decrease
        {
            if(mtx) mtx->lock();
            --load;
            if(mtx)  mtx->unlock();
        }
        void ClearLoad()
        {
            if(mtx) mtx->lock();
            load = 0 ;
            if(mtx)  mtx->unlock();
        }

        uint64_t Load()
        {
            uint64_t _load;
            if(mtx) mtx->lock();
            _load = load;
            if(mtx)  mtx->unlock();
            return _load;
        }
    };

    const std::string machine_path = "./conf/server_machine.conf"; 

    class LoadBlance{
        std::vector<Machine> machines;//能使用的主机

        std::vector<int> online;//在线的主机，对应着能使用主机内主机的下标

        std::vector<int> offline;//下线的主机

        std::mutex mtx;        
        public:

        LoadBlance(){
            LoadConf();//加载配置文件中存在的所有主机的信息到容器中

            LOG(INFO) << "加载"<< machine_path<<" 成功" << "\n";
        }

        ~LoadBlance(){}

        bool LoadConf()
        {
            std::ifstream in(machine_path);
            if(!in.is_open())//is_open查看是否打开
            {
                LOG(FATAL) << "加载" << machine_path << "失败" << "\n";
                return false;
            }
            std::string line;
            while(getline(in,line))
            {
                std::vector<std::string> tokens;
                StringUtil::SplitString(line,&tokens,":");
                Machine m;
                m.ip = tokens[0];
                m.port = std::stoi(tokens[1]);
                //m.port = atoi(tokens[1].c_str());
                //std::cout << "\"" << m.ip <<  "  " << tokens[1] << "\" :" << m.port << std::endl;
                
                m.load = 0;
                m.mtx = new std::mutex();

                online.push_back(machines.size());//在线机器的下标
                machines.push_back(m);
            }
            in.close();
            return true;

        }


//输出型参数
//id：该主机的下标
//m：该主机
//使用Machine** 是因为传递回去的是一个  Machine* (也就是Machine的地址！)
        void ShowMachine()
        {
            mtx.lock();
            std::cout << "在线主机列表：";
            for(auto iter : online)
            {
                std::cout << iter << " ";
            }
            std::cout << std::endl;

            std::cout << "离线主机列表：";
            for(auto iter : offline)
            {
                std::cout << iter << " ";
            }
            std::cout << std::endl;
            mtx.unlock();
        }
        
        bool SmartChoice(int* id,Machine** m)
        {
            mtx.lock();     
            int online_n = online.size();
            if(online_n == 0)
            {
                mtx.unlock();
                LOG(FATAL) << "所有后端的主机已经离线，请运维的同事尽快处理" << "\n";
                
                return false;
            }


            // LOG(DEBUG) << online[0] << "\n";
            //LOG(DEBUG) << machines.size() << "\n";
            uint64_t minload = machines[online[0]].load;
            //LOG(DEBUG) << machines.size() << "\n";
            *id = online[0];
            *m = &machines[online[0]];


            for(int i = 1; i <  online_n;i++)
            {
                uint64_t load =  machines[online[i]].load;

                if(minload > load)
                {
                    minload = load;
                    *id =  online[i];
                    *m = &machines[online[i]];
                }
            }
            LOG(DEBUG) << minload << "\n";
            LOG(INFO) << "智能选择成功" << "\n";
            mtx.unlock();
            return true;
        }

        void OfflineMachine(int id)
        {
            mtx.lock();
            for(auto iter = online.begin();iter != online.end() ;iter++)
            {
                if(*iter == id)
                {
                    machines[id].ClearLoad();//将load清零，防止当下线主机后，保留原本机器的load

                    online.erase(iter);
                    offline.push_back(id);
                    break;//因为有break,所以就不考虑erase迭代器失效问题了
                }
            }

            mtx.unlock();   
        }

        void OnlineMachie()
        {
//上线所有主机，当全部主机都下线后 TODO
            mtx.lock();
            //将所有离线的主机上线（前提你要真的启动了服务器！！）
            online.insert(online.begin(),offline.begin(),offline.end());
            //移除所有下线主机列表内的主机
            offline.erase(offline.begin(),offline.end());
            mtx.unlock();
        }

//调试函数


    };

    class Contrl
    {
        private:
            Model _model;
            View view;
            LoadBlance _loadblance;

        public:
            Contrl(){}
            ~Contrl(){}

            bool AllQuestions(std::string* html)
            {
                std::vector<struct Question> qs; 
                if(_model.GetAllQuestions(&qs))
                {
                    //将获得的题目进行升序
                    sort(qs.begin(),qs.end(),[](const struct Question& q1,const struct Question& q2){
                        return atoi(q1.number.c_str()) < atoi(q2.number.c_str());
                    });
                    //将所有的题目数据构成网页（使用view的功能）
                    view.AllExpandHtml(qs,html);
                    return true;
                }
                else
                {
                    *html = "获取题目失败，形成题目列表失败";
                    return false;
                }
            }

            bool Questions(const std::string & number,std::string* html)
            {
                Question q; 
                if(_model.GetOneQuestion(number,&q))
                {
                    view.OneExpandHtml(q,html);
                    return true;
                }
                else
                {
                    *html =  "指定题目"+ number+ "不存在";
                    return false;
                }
            }


            void Judge(const std::string& number,const std::string& in_json,std::string* out_json)
            {
                //0. 根据题目编号拿到题目细节（model中的GetOneQuestion）
                Question q;
                _model.GetOneQuestion(number,&q);
                //1. in_json反序列化，得到用户的 提交的代码 input数据
                Json::Value in_value;
                Json::Reader reader;
                reader.parse(in_json,in_value);
                std::string code = in_value["code"].asString();

                //2. 重新拼接用户代码 + 测试用例代码，形成新的代码，以及编译运行逻辑所需要的json 中的必要 k值
                // input code cpu_limit mem_limit
                Json::Value compile_value;
                compile_value["code"] = code + "\n" + q.tail;
                compile_value["input"] = in_value["input"].asString();
                compile_value["cpu_limit"] = q.cpu_limit;
                compile_value["mem_limit"] = q.mem_limit;
                //反序列化：
                Json::FastWriter writer;
                std::string compile_string = writer.write(compile_value);

                LOG(INFO) << "编译运行逻辑所需要json创建成功" << "\n";  
                //3. 选择负载最低的主机
                while(true)
                {
                    int id;
                    Machine* m = nullptr;
                                            

                    if(!_loadblance.SmartChoice(&id,&m))
                    {
                        break;
                    }

                    Client cil(m->ip,m->port);
                    m->IncLoad();
                    LOG(INFO) << "选择主机成功" << "主机id->" << id << " 主机详情：" << m->ip <<":"<< m->port << "当前主机负载："<< m->Load() << "\n"; 
                    //调用compile_run方法，将compile_string字符串传递给该服务器
                    if(auto res = cil.Post("/compile_run",compile_string,"application/json;charset=utf-8"))
                    {
                        LOG(DEBUG) << "编译运行完成" << "\n";
                        if(res->status == 200)//查看响应报文的状态码是否正常
                        {
                            *out_json = res->body;
                            m->DecLoad();
                            LOG(INFO) << "请求编译和运行服务成功..." << "\n";
                            break;
                        }
                        m->DecLoad();
                    }
                    else
                    {
                        m->DecLoad();
                        LOG(ERROR) << "当前请求的主机id: " << id << " 主机详情："<<  m->ip <<":" << m->port << " 可能已经离线" << "\n";
                        
                        _loadblance.OfflineMachine(id);
                        _loadblance.ShowMachine();
                    }
                }
            }

            void RecoveryMachine()
            {
                _loadblance.OnlineMachie();
            }
    };

}