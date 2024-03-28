#include<iostream>

#include"Log.hpp"

using namespace std;

int main()
{
    Log log;
    log.LogMessage(Debug,"%s %f %d","bite",3.14,0);

    return 0;
}