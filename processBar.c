#include "processBar.h"

const char *lable = "|/-\\";// \ 反斜杠是特殊的字符所以需要用\\ 来表示成\ 

char bar[102] = {0};
//函数processBar来展示下载的过程
//原理和之前一样，只不过此时把逐渐完成的过程放到了外部

void initbar()//清理数组中的内容
{
    memset(bar,'\0',sizeof(bar));//将内容全部置为\0
}

void processBar(int rata)
{
    if(rata < 0 || rata > 100) return ;
    int len =  strlen(lable);
    
    printf("[%-100s][%d%%][%c]\r",bar,rata,lable[rata%len]); 
    fflush(stdout);
    bar[rata++] = BODY;
    if(rata < 100) bar[rata] = RIGHT;
        
}
/*void processBar(int speed)
{
    int cnt = 0;
    char bar[102];
    memset(bar,'\0',sizeof(bar));
    int len =  strlen(lable);

    while(cnt <= 100)
    {
        printf("[%-100s][%d%%][%c]\r",bar,cnt,lable[cnt%len]);//%-100d 先预先开辟100个字符位并且向左对齐、对于最后的旋转可以用不断遍历数组显示、%%表示%因为%是特殊字符 所以若要表示出来单独的%则需要用%% 或者 \% 
        fflush(stdout);//没有\n来刷新，所以需要自己刷新缓冲区
        bar[cnt++] = BODY;//逐渐增加的进度条
        if(cnt < 100) bar[cnt] = RIGHT;// > 在最后一个位置就不需要在出现了
        usleep(speed);//休眠多少微秒
    }
    printf("\n");

}*/

