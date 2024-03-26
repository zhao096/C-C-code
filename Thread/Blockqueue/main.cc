#include"BlockQueue.hpp"
#include"Task.hpp"
#include<string>

const string opers = "+-*/%&()";

class TreadData
{
public:
    Blockqueue<Task> * bq;
    string name;
};

void* cosumer(void*args)
{
    Blockqueue<Task> *bq = static_cast<Blockqueue<Task>*>(args);
    while(true)
    {
        Task t;
        //1.消费数据 bq->pop(&data),获取数据到data
        bq->Pop(&t);

        //2.进行处理
        t();//t.Run()
        cout << "consumer data: "<<  t.PrintResult() << endl;
        sleep(1);//因为生产快（sleep）消费慢，生产满了，后消费一个再生产一个    

    }
    return nullptr;
}

void* productor(void*args)
{
    Blockqueue<Task> *bq = static_cast<Blockqueue<Task>*>(args);
    while(true)
    {
        //有数据
        int data1 = rand() % 10;
        usleep(rand() % 100);
        int data2 = rand() % 10;//去10以内的随机数
        usleep(rand() % 100);

        char oper = opers[rand() % opers.size()];//取opers中的符号
        
        //进行生产：bq->push
        Task t(data1,data2,oper);
        bq->Push(t);

        //debug
        cout << "productor data: "<<t.PrintTask() << endl;
        //sleep(1);//因为生产慢（sleep）消费快，所以也就是生成一个消费一个
    }
    return nullptr;
}


int main()
{
    srand((uint16_t)time(nullptr) ^ getpid() ^ pthread_self());//产生随机数
    //让生产者给消费者分配任务：
    Blockqueue<Task> * bq = new Blockqueue<Task>();
    pthread_t c,p;
    //不用担心谁先执行，因为即使消费者先也会因为空队列而进行等待
    pthread_create(&c,nullptr,cosumer,bq);
    pthread_create(&p,nullptr,productor,bq);

    pthread_join(c,nullptr);
    pthread_join(p,nullptr);
    return 0;
}