 #define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


int main()
{
	//string s("12345678910");

	//s.reserve(100);//用法如此
	//cout << s.size() << endl;//查看数据个数
	//cout << s.capacity() << endl;//查看开辟的空间
	//s.shrink_to_fit();
	//cout << s.size() << endl;//查看数据个数
	//cout << s.capacity() << endl;//查看开辟的空间

	////s.clear();
	//s.reserve(0);
	//cout << s.size() << endl;//查看数据个数
	//cout << s.capacity() << endl;//查看开辟的空间

	//string s;

	//s.resize(100,'x');
	//cout << s.size() << endl;//查看数据个数
	//cout << s.capacity() << endl;//查看开辟的空间
	//
	//s.resize(5);
	//cout << s.size() << endl;//查看数据个数
	//cout << s.capacity() << endl;//查看开辟的空间
	//string s("hello world");
	//s.assign("666");
	//cout << s << endl;

	//s.insert(0, "555");//下标为0的位置下插入字符串
	//cout << s << endl;

	//s.insert(6, 3,'7');//下标为6的位置处插入3个字符7
	//cout << s << endl;

	//s.insert(s.begin()+9, 3, '8');//此处的迭代器就像一个指针可以一样使用即可
	//cout << s << endl;
	
	//string s("hello world");


	//s.erase(5, 1);//把下标为5的空格给除去
	//cout << s << endl;
	//s.erase(5);//把下标为5的及往后的所有字符都给除去
	//cout << s << endl;
	//s.erase(s.begin());//头删，指定单独删除一个
	//cout << s << endl;
	//s.erase(s.begin(), s.end());//指定范围删除，此处把从头到尾都删了
	//cout << s << endl;

	//string s("hello world");
	//cout << s << endl;//上面是string重载的流插入，进行打印的
	//cout << s.c_str() << endl;//而此处是s.c_str返回一个字符串流插入识别打印的
	////这两个概念是不一样的，虽然结果一样




	std::string str("Please, replace the vowels in this sentence by asterisks.");
	std::size_t found = str.find_first_of("aeiou");
	while (found != std::string::npos)
	{
		str[found] = '*';//把包含aeiou的位置换成*
		found = str.find_first_of("aeiou", found + 1);
	}

	std::cout << str << '\n';


	return 0;
}