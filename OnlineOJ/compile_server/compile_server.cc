#include <iostream>

#include "compile.hpp"
#include "runner.hpp"
using namespace ns_compile;
using namespace ns_runner;
int main()
{
    std::string code = "code";
    compile::Compile(code);

    Runner::Run(code);
    return 0;
}