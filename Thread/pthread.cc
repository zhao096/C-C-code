#include<iostream>
#include<pthread.h>
#include<unistd.h>
using namespace std;

void* ThreadRountine(void*)
{

}

int main()
{
    pthread_t tid;
    pthread_create(&tid,nullptr,ThreadRountine,nullptr);

while(true)
{
    cout << "main thread" << endl;
    sleep(1);

}
    return 0;
}