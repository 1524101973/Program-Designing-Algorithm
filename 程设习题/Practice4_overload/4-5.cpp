/*
E:别叫，这个大整数已经很简化了!
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空，输出指定结果

#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
// 在此处补充你的代码
};
int  main() 
{ 
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}
输入
多组数据，每组数据是两个非负整数s和 n。s最多可能200位， n用int能表示
输出
对每组数据，输出6行，内容分别是：
样例输入
99999999999999999999999999888888888888888812345678901234567789 12
6 6
样例输出
99999999999999999999999999888888888888888812345678901234567801
99999999999999999999999999888888888888888812345678901234567801
99999999999999999999999999888888888888888812345678901234567801
25
25
26
12
12
12
13
13
14
*/
#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
// 在此处补充你的代码
	char ch[210];
	public:
	 	CHugeInt(){}
		CHugeInt(const char s[])
		{
			memset(ch,0,sizeof(ch));
			strcpy(ch, s);
		}
		CHugeInt(const int q)
		{
			memset(ch,0,sizeof(ch));
			sprintf(ch,"%d",q);
		}
		CHugeInt & operator+ (const CHugeInt q)
		{
			CHugeInt tmp;
			int mem1[2200];
			int mem2[2200];
			int len1 = strlen(ch);
			int len2 = strlen(q.ch);
			for (int i = len1 - 1; i >= 0; i--)
			{
				mem1[len1 - 1 - i] = ch[i] - '0';
			}
			for (int i = len2 - 1; i >= 0; i--)
			{
				mem2[len2 - 1 - i] = q.ch[i] - '0';
			}
			int len;
			if(len1 > len2) len = len1;
			else len = len2;
			for (int i = 0; i < len; i++)
			{
				mem1[i] += (mem2[i] % 10);
				if(mem1[i] >= 10)
				{
					mem1[i] -= 10;
					mem1[i + 1]++;
				}
			}
			for (int i = 0; i < len; i++)
			{
				tmp.ch[i] = mem1[i] + '0';
			}
			return tmp;
		}
		CHugeInt operator + (int n)
		{
			CHugeInt s;
			sprintf(s.ch,"%d",n);
			return *this + s;
		}
		friend CHugeInt operator+ (int n, CHugeInt q)
		{
			return q + n;
		}
		friend ostream & operator << (ostream & o, const CHugeInt &q)
		{
			int len = strlen(q.ch);
			for(int i = len - 1; i >= 0; --i)
				cout << q.ch[i];
			return o;	
		}
		CHugeInt &operator++()
		{
			*this=*this+1;
			return *this;	
		}
		CHugeInt operator++(int)
		{
			CHugeInt tmp(*this);
			*this=*this+1;
			return tmp;
		}
		CHugeInt & operator += (int n)
		{
			*this = *this + n;
			return *this;
		}
};
int  main() 
{ 
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}