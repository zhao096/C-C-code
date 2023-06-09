 #define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
	


//int main()
//{
//	//string s("12345678910");
//
//	//s.reserve(100);//用法如此
//	//cout << s.size() << endl;//查看数据个数
//	//cout << s.capacity() << endl;//查看开辟的空间
//	//s.shrink_to_fit();
//	//cout << s.size() << endl;//查看数据个数
//	//cout << s.capacity() << endl;//查看开辟的空间
//
//	////s.clear();
//	//s.reserve(0);
//	//cout << s.size() << endl;//查看数据个数
//	//cout << s.capacity() << endl;//查看开辟的空间
//
//	//string s;
//
//	//s.resize(100,'x');
//	//cout << s.size() << endl;//查看数据个数
//	//cout << s.capacity() << endl;//查看开辟的空间
//	//
//	//s.resize(5);
//	//cout << s.size() << endl;//查看数据个数
//	//cout << s.capacity() << endl;//查看开辟的空间
//	//string s("hello world");
//	//s.assign("666");
//	//cout << s << endl;
//
//	//s.insert(0, "555");//下标为0的位置下插入字符串
//	//cout << s << endl;
//
//	//s.insert(6, 3,'7');//下标为6的位置处插入3个字符7
//	//cout << s << endl;
//
//	//s.insert(s.begin()+9, 3, '8');//此处的迭代器就像一个指针可以一样使用即可
//	//cout << s << endl;
//	
//	//string s("hello world");
//
//
//	//s.erase(5, 1);//把下标为5的空格给除去
//	//cout << s << endl;
//	//s.erase(5);//把下标为5的及往后的所有字符都给除去
//	//cout << s << endl;
//	//s.erase(s.begin());//头删，指定单独删除一个
//	//cout << s << endl;
//	//s.erase(s.begin(), s.end());//指定范围删除，此处把从头到尾都删了
//	//cout << s << endl;
//
//	//string s("hello world");
//	//cout << s << endl;//上面是string重载的流插入，进行打印的
//	//cout << s.c_str() << endl;//而此处是s.c_str返回一个字符串流插入识别打印的
//	////这两个概念是不一样的，虽然结果一样
//
//
//
//
//	std::string str("Please, replace the vowels in this sentence by asterisks.");
//	std::size_t found = str.find_first_of("aeiou");
//	while (found != std::string::npos)
//	{
//		str[found] = '*';//把包含aeiou的位置换成*
//		found = str.find_first_of("aeiou", found + 1);
//	}
//
//	std::cout << str << '\n';
//
//
//	return 0;
//}


//int main()
//{
//	
//	string str1("hello");
//	string str2("hello");
//
//	string str3("hello cpp");
//	
//	if (str1 == str2)
//		cout << "==" << endl;
//	
//	// ....
//
//	if (str1 < str3)
//		cout << "<" << endl;
//
//	return 0;
//}

//int main()
//{
//	
//	string str1("hello");
//	
//	cout << str1 + " world" << endl;//返回的是临时变量
//	cout << str1 << endl;//实际并没有变
//
//	return 0;
//}
//int main()
//{
//
//	string str1;
//	cin >> str1 ;
//	cout << str1 << endl;
//	//getline(cin, str1);
//	//cout << str1 << endl;
//
//	return 0;
//}

int main()
{
	string str1 = to_string(1234);
	string str2 = to_string(12.34);
	cout << str1 << endl;
	cout << str2 << endl;

	int ret1 = stoi(str1);
	double ret2 = stold(str2);
	cout << ret1 << endl;
	cout << ret2 << endl;

	return 0;
}