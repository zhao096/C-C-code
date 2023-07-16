#include<stdio.h>
#include"processBar.h"
#include<unistd.h>
// 模拟 下载时的情况
void DownLoad(processbar i)//利用函数指针
{
    int total = 1000;//假如有1000MB
    int cur = 0;//一开始从0开始
    while(cur <= total)
    {
        int rata  = cur*100 / total;//计算完成的百分比
        i(rata);//把rata传给i 也就是 processBar
        cur += 10;//模拟下载逐渐完成
        usleep(50000);//模拟下载的所需的时间
    }
    printf("\n");
}



int main()
{
    printf("processbar1\n");
    DownLoad(processBar);
    initbar();//清理一下数组内容，为下面处理时腾出空的空间
    
    printf("processbar2\n");
    DownLoad(processBar);

    return 0;
}
