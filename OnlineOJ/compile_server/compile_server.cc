#include <iostream>

#include "compile.hpp"
using namespace ns_compile;
int main()
{
    std::string code = "code";
    compile::Compile(code);

    return 0;
}