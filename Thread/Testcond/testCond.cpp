#include<iostream>
#include<pthread.h>
#include<unistd.h>
using namespace std;

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int tickets = 10000;

void* threadRontine(void* args)
{
    string name = static_cast<const char*>(args);

    while(true)
    {
        // sleep(1);
        pthread_mutex_lock(&mutex);//加锁和解锁之间往往要访问临界资源

        if(tickets > 0)
        {
            cout <<  name << " , get a ickets" << tickets-- <<endl;
            usleep(1000);
        }
        else{
            //当票用完了每隔一段时间会补些票
            cout << name <<" , 没票了" << endl;
            pthread_cond_wait(&cond,&mutex);//没票了就应该等待！！
        }
        
        pthread_mutex_unlock(&mutex);
    }
}

//主线程
int main()
{
    pthread_t t1,t2,t3;

    pthread_create(&t1,nullptr,threadRontine,(void*)"thread-1"); 
    pthread_create(&t2,nullptr,threadRontine,(void*)"thread-2"); 
    pthread_create(&t3,nullptr,threadRontine,(void*)"thread-3"); 

    sleep(5);//5s后让条件变量唤醒线程
    while(true)
    {
        sleep(10);
        pthread_mutex_lock(&mutex);

        tickets += 1000;//票

        pthread_mutex_unlock(&mutex);
        pthread_cond_broadcast(&cond);//唤醒全部线程
        //pthread_cond_signal(&cond);//唤醒一个线程

    }

    pthread_join(t1,nullptr);
    pthread_join(t2,nullptr);
    pthread_join(t3,nullptr);

}