 #define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;
//
//int main()
//{
	//string st;
	//
	//string st1("hello world");

	//
	//string st2(st1);
	//
	//string st3(st1, 6, 5);
	//
	//string st4(st1, 6);
	//
	//string st5("hello world",5);

	//string st6(10,'*');

	//cout << st <<endl;
	//cout << st1 <<endl;
	//cout << st2 <<endl;
	//cout << st3 <<endl;
	//cout << st4 <<endl;
	//cout << st5 <<endl;
	//cout << st6 <<endl;



	//string st7("张三");
	//cout << st7 << endl;
	//
	//st7 = "张三丰";
	//cout << st7 << endl;
	//st7 = 'z';
	//cout << st7 << endl;
	//
	//string st8("李四");
	//st7 = st8;
	//cout << st7 << endl;


	//string st("hello");
	///*st.push_back(' ');
	//st.append("world");*/

	//st += ' ';
	//st += "world";
	//
	//cout << st << endl;

	//string st("abcdef");
	//cout << st << endl;

	//for (int i = 0; i < st.size(); i++)//这里附加一个函数size是库中已经定义好的函数能得出该字符串的长度
	//{
	//	st[i]++;
	//}
	//for (int i = 0; i < st.size(); i++)//这里附加一个函数size是库中已经定义好的函数能得出该字符串的长度
	//{
	//	cout << st[i];
	//}
	//cout << endl;
//	string st("hello world");
//	string::iterator it = st.begin();//begin函数找到字符对象的首元素
//	//迭代器 iterator 类似于一个指针
//	//for (int i = 0; i < st.size(); i++)
//	//{
//	//	cout << *it; //用法和指针很像
//	//	it++;
//	//}
//	//cout << endl;
//
////范围for的底层就是迭代器
//	for (char& c : st)
//	{
//		cout << ++c;
//	}
//	cout << endl;


	//vector<int> v;
	//v.push_back(10);
	//v.push_back(21);
	//v.push_back(3);
	//v.push_back(14);

	//vector<int>::iterator vec = v.begin();
	//while(vec != v.end())
	//{
	//	cout << *vec << ' ';
	//	vec++;
	//}
	//cout << endl;

	//list<int> li;
	//li.push_back(15);
	//li.push_back(22);
	//li.push_back(35);
	//li.push_back(4);

	//list<int>::iterator lit = li.begin();
	//while (lit != li.end())
	//{
	//	cout << *lit << ' ';
	//	lit++;
	//}
	//cout << endl;

	////现在我们只需大概的知道怎么用即可，先暂时不做过多深入的学习
	////下面是一个算法reverse()， 其头有文件是：#include<algorithm>，
	////算法要作用到数据上去，所以就需要通过迭代器去访问容器的数据，因为容器类也是私有的不能够直接去访问
	//reverse(v.begin(),v.end());
	//reverse(li.begin(), li.end());
	////因为都满足迭代器所以就能直接通范围for的形式来进行打印
	//for (auto x : v)
	//{
	//	cout << x << ' ';
	//}
	//cout << endl;

	//for (auto l : li)
	//{
	//	cout << l << ' ';
	//}
	//cout << endl;
	////排序函数
	//sort(v.begin(), v.end());
	//for (auto x : v)
	//{
	//	cout << x << ' ';
	//}
	//cout << endl;

	//string st("hello world");
	//string::reverse_iterator it = st.rbegin();
	//while (it != st.rend())
	//{
	//	cout << *it << ' ';
	//	it++;
//	//}
//	//cout << endl;
//}/*	*/

void fun(const string& st)
{
	string::const_reverse_iterator it = st.rbegin();
	while (it != st.rend())
	{
		cout << *it << ' ';
		it++;
	}
	cout << endl;
}

int main()
{
	string st("hello world");
	string::reverse_iterator it = st.rbegin();
	while (it != st.rend())
	{
		cout << *it << ' ';
		it++;
	}
	cout << endl;

	//fun(st);
	return 0;
}

