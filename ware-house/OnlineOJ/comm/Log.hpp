#pragma once
#include <iostream>
#include <string>
#include "util.hpp"


namespace ns_log{
    using namespace ns_util;
    enum {
        INFO,//常规
        DEBUG,
        WARNING,
        ERROR,
        FATAL//系统级错误
    };

    inline std::ostream& Log(const std::string& level,const std::string& filename, int line)
    {
        //[level] [filename] [line][time]
        std::string ret;
        ret += "[";
        ret += level;
        ret += "]";

        ret += "[";
        ret += filename;
        ret += "]";

        ret += "[";
        ret += std::to_string(line);
        ret += "]";

        ret += "[";
        ret += TimeUtil::GetTimeStamp();
        ret += "]";

//cout 本质是一个缓冲区 当没遇到\n是就不会刷星
        std::cout << ret;//将为还未刷新的缓冲区返回
        return std::cout;
    }

    #define LOG(level) Log(#level,__FILE__,__LINE__)
}
