#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
int FindMax(const std::vector<int>& arr){return 0;}};

#ifndef COMPILER_ONLINE
#include "header.cpp"
#endif

void Test1()
{
    // 通过定义临时对象，来完成⽅法的调⽤
    int ret = Solution().FindMax(vector<int>{1,4,6,-1,0,5});
    if (ret == 6)
    {
        std::cout << "通过⽤例1, 测试通过 ... OK!" << std::endl;
    }
    else
    {
        std::cout << "没有通过⽤例1" << std::endl;
    }
}
void Test2()
{
    // 通过定义临时对象，来完成⽅法的调⽤
    int ret = Solution().FindMax(vector<int>{0,100,22,55,1024});
    if (ret == 1024)
    {
        std::cout << "通过⽤例2, 测试通过 ... OK!" << std::endl;
    }
    else
    {
        std::cout << "没有通过⽤例2" << std::endl;
    }
}
int main()
{
    Test1();
    Test2();
    return 0;
}

