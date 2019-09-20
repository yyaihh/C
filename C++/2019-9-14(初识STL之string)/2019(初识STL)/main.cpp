#include<iostream>
#include<string>
#include <typeinfo>
using namespace std;
void test() {
	//string的8个构造函数(重载关系)
	string s;//string()
	string s1("abcdef");//string(const char* s)
	string s2(4, 'a');	//string(size_t n, char c)
	string s3(s1);		//string(const string& s)
	string s4(s1, 3);	//string(const string& s, size_t n)
	string s5(s1, 1, 5);
	string s6("abcdefe", 3);
	string s7("scscssr", 2, 6);
	cout << typeid(s1.begin()).name() << endl;
	cout << typeid(*s1.begin()).name() << endl;
	string::iterator begin = s1.begin();
	string::iterator end = s1.end();

	string s8(begin, end);
	cout << "s: " << endl
	    << "s1:" << s1 << endl
		<< "s2:" << s2 << endl
		<< "s3:" << s3 << endl
		<< "s4:" << s4 << endl
		<< "s5:" << s5 << endl
		<< "s6:" << s6 << endl
		<< "s7:" << s7 << endl
		<< "s8:" << s8 << endl;
	for (int i = 0; begin + i < end; ++i) {
		cout << *(begin + i);
	}
	cout << endl;
	system("pause");
	system("cls");
}
void test1() {
	string s1("abcdef");//string(const char* s)
	string s2(4, 'a');	//string(size_t n, char c)
	string s3(s1);		//string(const string& s)
	cout << "sting类的容量操作\n";
	cout << "s1有效长度是:" << s1.size() << endl;
	//size_t size() const 返回字符串有效字符长度
	cout << "s1有效长度是:" << s1.length() << endl;
	//size_t length() const 返回字符串有效字符长度
	cout << "s2有效长度是:" << s2.size() << endl;
	cout << "s2有效长度是:" << s2.length() << endl;
	cout << "s1的容量是:" << s1.capacity() << endl;
	//size_t capacity() const 返回空间总大小
	cout << "s2的容量是:" << s2.capacity() << endl;
	s1.reserve(20);
	//void reserve(size_t res_arg = 0) 为字符串预留空间
	cout << "s1有效长度是:" << s1.size() << endl;
	cout << "s1的容量是:" << s1.capacity() << endl;
	s2.resize(25);
	//void resize(size_t n) 将有效字符的个数改成n个，多出的空间用0填充
	cout << "s2有效长度是:" << s2.size() << endl;
	cout << "s2的容量是:" << s2.capacity() << endl;
	s2 += "字符串结束";
	cout << "s2:" << s2 << endl;
	s3.resize(20, 'z');
	//void resize(size_t n, char c) 将有效字符的个数该成n个，多出的空间用字符c填充
	cout << "s3有效长度是:" << s3.size() << endl;
	cout << "s3的容量是:" << s3.capacity() << endl;
	cout << "s3:" << s3 << endl;
	s1.empty() ? cout << "s1为空\n" : cout << "s1不为空!\n";
	//bool empty() const 检测字符串释放为空串，是返回true，否则返回false
	cout << "清空s2\n";
	s2.clear();
	s2.empty() ? cout << "s2为空\n" : cout << "s2不为空!\n";
	system("pause");
	system("cls");
}
void test2() {
	//string类对象的访问操作
	string s1("abcdef");
	const string s2("xyz");
	cout << "s1:" << s1 << endl;
	for (size_t i = 0; i < s1.size(); ++i) {
		cout << s1[i] << " ";
		//char& operator[] ( size_t pos ) 返回pos位置的字符，非const string类对象调用
	}
	cout << endl;
	cout << "s2:" << s2 << endl;
	for (size_t i = 0; i < s2.size(); ++i) {
		cout << s2[i] << " ";
		//char& operator[] ( size_t pos ) 返回pos位置的字符，const string类对象调用
	}
	cout << endl;
	system("pause");
	system("cls");
}
void test3() {
	string s("abcdef");
	string s1("higk");
	string s2("qrst");
	cout << "s:" << s << endl;
	s.push_back('g');//void push_back(char c) 在字符串后尾插字符c
	cout << "s:" << s << endl;
	s.append(s1);//string& append (const char* s); 在字符串后追加一个字符串
	s.append("dsscs");
	s.append(8, 'a');
	cout << "s:" << s << endl;
	s += "lmnop";//string& operator+=(const char* s) 在字符串后追加一个字符串
	cout << "s:" << s << endl;
	s += s2;//string& operator+=(const string& str)在字符串后追加sting类字符串str
	cout << "s:" << s << endl;
	s += 'u';//string& operator+=(char c) 在字符串后追加字符c
	cout << "s:" << s << endl;
	s.pop_back();//void pop_back() 删除字符串最后一个字符
	cout << "s:" << s << endl;
	const char* c_s = s1.c_str();//const char* c_str( )const 返回C格式字符串
	cout << "c_s:" << c_s << endl;
	char c = 'd';
	size_t pos = 0;
	size_t n = s.find(c, pos);//pos<s.size();否则会发生访问越界
	//size_t find (char c, size_t pos =0)const //pos是缺省参数, 不传就是从0开始
	//从字符串pos位置开始往后找字符c，找到字符返回字符串中的下标,找不到返回-1, 因为返回值是size_t所以是4294967295
	n != (size_t)-1 ? cout << c << "在字符串s中下标为" << n << "的位置\n" :
		cout << c << "不在从下标" << pos << "位置开始往后的字符串中\n";

	n = s.find(s1/*缺省参数默认0*/);//pos<s.size();否则会发生访问越界
	//size_t find (string c, size_t pos =0)const //pos是缺省参数, 不传就是从0开始
	//从字符串pos位置开始往后找字串c，找到字符串c
	//返回c在被找字符串中的下标,找不到返回-1, 因为返回值是size_t所以是4294967295
	n != (size_t)-1 ? cout << s1 << "在字符串s中下标为" << n << "的位置\n" :
		cout << s1 << "不在从下标" << pos << "位置开始往后的字符串中\n";

	n = s.rfind(c_s, s.size() - 1);//pos<s.size();否则会发生访问越界
	//size_t find (char* c, size_t pos =0)const //pos是缺省参数, 不传就是从0开始
	//从字符串pos位置开始往后找字串c，找到字符串c
	//返回c在被找字符串中的下标,找不到返回-1, 因为返回值是size_t所以是4294967295
	n != (size_t)-1 ? cout << c_s << "在字符串s中下标为" << n << "的位置\n" :
		cout << c_s << "不在从下标" << pos << "位置开始往后的字符串s中\n";

	size_t npos = 10;
	n = s.rfind(c, npos);//npos<s.size();否则会发生访问越界
	//size_t rfind (char c, size_t pos =0)const//pos是缺省参数, 默认为0
	//从字符串pos位置开始往前找字符c
	//找到字符返回字符串中的下标,找不到返回-1, 因为返回值类型size_t所以是4294967295
	n != (size_t)-1 ? cout << c << "在字符串s中下标为" << n << "的位置\n" :
		cout << c << "不在从下标" << npos << "位置开始往前的字符串中\n";
	string s3 = s.substr(pos, npos);//npos<s.size(), pos>=0, npos-pos>=0;
	//pos为缺省参数
	//string substr(size_t pos = 0, size_t n= npos)const
	//在str中从pos位置开始，截取n个字符，然后将其返回
	cout << "s3:" << s3 << endl;
	system("pause");
	system("cls");
}
void test4() {
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2, 'c');
	cout << s1 << endl;
	cout << s2 << endl;
	system("pause");
	system("cls");
}
int main() {
	test();
	test1();
	test2();
	test3();
	test4();
	return 0;
 }