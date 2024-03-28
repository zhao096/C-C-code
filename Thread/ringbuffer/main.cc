#include"RingQueue.hpp"
#include"Task.hpp"
#include"Log.hpp"


const string opers = "+-*/%&()";

void* Productor(void * args)
{
    // sleep(5);//先生产，消费者就会先等待，当生产后就会开始消费
    RingQueue<Task> * rq = static_cast<RingQueue<Task> *>(args);
    while(true)
    {   
        int data1 = rand() % 10;
        usleep(rand() % 100);
        int data2 = rand() % 10;//去10以内的随机数
        usleep(rand() % 100);

        char oper = opers[rand() % opers.size()];//取opers中的符号
        
        Task t(data1,data2,oper);
        rq->Push(t);

        //debug
        cout << "productor data: "<<t.PrintTask() << endl;

        // sleep(1);
    }

}

void* Consumer(void * args)
{
    RingQueue<Task> * rq = static_cast<RingQueue<Task> *>(args);

    while(true)
    {
        Task t;
        rq->Pop(&t);

        t();//t.Run()
        cout << "consumer data: "<<  t.PrintResult() << endl;
        // sleep(1);//因为生产快（sleep）消费慢，生产满了，后消费一个再生产一个    
    }
}

int main()
{
    //单生产，单消费：321
    Log log;
    log.LogMessage(Debug,"hello %d %s %f",10,"bite,3.14");



    // srand((uint16_t)time(nullptr) ^ getpid() ^ pthread_self());//产生随机数
    // pthread_t c[3], p[2];

    // RingQueue<Task>* rq = new RingQueue<Task>();
    
    // pthread_create(&p[0],nullptr,Productor,rq);
    // pthread_create(&p[1],nullptr,Productor,rq);
    // pthread_create(&c[0],nullptr,Consumer,rq);
    // pthread_create(&c[1],nullptr,Consumer,rq);
    // pthread_create(&c[2],nullptr,Consumer,rq);

    // pthread_join(p[0],nullptr);
    // pthread_join(p[1],nullptr);
    // pthread_join(c[0],nullptr);
    // pthread_join(c[1],nullptr);
    // pthread_join(c[2],nullptr);
}