/*
A:MyString
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
补足MyString类，使程序输出指定结果
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class MyString {
	char * p;
public:
	MyString(const char * s) {
		if( s) {
			p = new char[strlen(s) + 1];
			strcpy(p,s);
		}
		else
			p = NULL;

	}
	~MyString() { if(p) delete [] p; }
// 在此处补充你的代码
};
int main()
{
	char w1[200],w2[100];
	while( cin >> w1 >> w2) {
		MyString s1(w1),s2 = s1;
		MyString s3(NULL);
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;

		s2 = w2;
		s3 = s2;
		s1 = s3;
		cout << s1 << "," << s2 << "," << s3 << endl;
		
	}
}
输入
多组数据，每组一行，是两个不带空格的字符串
输出
对每组数据，先输出一行，打印输入中的第一个字符串三次
然后再输出一行，打印输入中的第二个字符串三次
样例输入
abc def
123 456
样例输出
abc,abc,abc
def,def,def
123,123,123
456,456,456
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class MyString {
	char * p;
public:
	MyString(const char * s) {
		if( s) {
			p = new char[strlen(s) + 1];
			strcpy(p,s);
		}
		else
			p = NULL;

	}
	~MyString() { if(p) delete [] p; }
	MyString(const MyString & s) {
		if( s.p) {
			p = new char[strlen(s.p) + 1];
			strcpy(p,s.p);
		}
		else
			p = NULL;

	}
	void Copy(const char* s){
			if( s) {
			p = new char[strlen(s) + 1];
			strcpy(p,s);
		}
		else
			p = NULL;
	}
	friend ostream & operator << (ostream &o, const MyString & s){
		o << s.p;
		return o;
	} 
	MyString & operator = (MyString & s)
	{
		p = s.p;
	}
	MyString & operator = (char *s)
	{
		p = s;
	}
};
int main()
{
	char w1[200],w2[100];
	while( cin >> w1 >> w2) {
		MyString s1(w1),s2 = s1;
		MyString s3(NULL);
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;

		s2 = w2;
		s3 = s2;
		s1 = s3;
		cout << s1 << "," << s2 << "," << s3 << endl;
		
	}
}