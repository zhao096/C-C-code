#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
    while(true)
    {
        cout << "running ..., pid = " << getpid() << endl;
        sleep(1);
    }
    return 0;
}