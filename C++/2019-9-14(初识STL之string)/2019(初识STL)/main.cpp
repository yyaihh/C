#include<iostream>
#include<string>
using namespace std;
void test1() {
	//string������������캯��(���ع�ϵ)
	string s;//string()
	string s1("abcdef");//string(const char* s)
	string s2(4, 'a');	//string(size_t n, char c)
	string s3(s1);		//string(const string& s)
	string s4(s1, 3);	//string(const string& s, size_t n)
	cout << "s1:" << s1 << endl
		<< "s2:" << s2 << endl
		<< "s3:" << s3 << endl
		<< "s4:" << s4 << endl;
	cout << "sting�����������\n";
	cout << "s1��Ч������:" << s1.size() << endl;
	//size_t size() const �����ַ�����Ч�ַ�����
	cout << "s1��Ч������:" << s1.length() << endl;
	//size_t length() const �����ַ�����Ч�ַ�����
	cout << "s2��Ч������:" << s2.size() << endl;
	cout << "s2��Ч������:" << s2.length() << endl;
	cout << "s1��������:" << s1.capacity() << endl;
	//size_t capacity() const ���ؿռ��ܴ�С
	cout << "s2��������:" << s2.capacity() << endl;
	s1.reserve(20);
	//void reserve(size_t res_arg = 0) Ϊ�ַ���Ԥ���ռ�
	cout << "s1��Ч������:" << s1.size() << endl;
	cout << "s1��������:" << s1.capacity() << endl;
	s2.resize(25);
	//void resize(size_t n) ����Ч�ַ��ĸ����ĳ�n��������Ŀռ���0���
	cout << "s2��Ч������:" << s2.size() << endl;
	cout << "s2��������:" << s2.capacity() << endl;
	cout << "s2:" << s2 << "����" << endl;
	s3.resize(20, 'z'); 
	//void resize(size_t n, char c) ����Ч�ַ��ĸ����ó�n��������Ŀռ����ַ�c���
	cout << "s3��Ч������:" << s3.size() << endl;
	cout << "s3��������:" << s3.capacity() << endl;
	cout << "s3:" << s3 << endl;
	s1.empty() ? cout << "s1Ϊ��\n" : cout << "s1��Ϊ��!\n";
	//bool empty() const ����ַ����ͷ�Ϊ�մ����Ƿ���true�����򷵻�false
	cout << "���s2\n";
	s2.clear();
	s2.empty() ? cout << "s2Ϊ��\n" : cout << "s2��Ϊ��!\n";
	system("pause");
	system("cls");
}
void test2() {
	//string�����ķ��ʲ���
	string s1("abcdef");
	const string s2("xyz");
	cout << "s1:" << s1 << endl;
	for (size_t i = 0; i < s1.size(); ++i) {
		cout << s1[i] << " ";
		//char& operator[] ( size_t pos ) ����posλ�õ��ַ�����const string��������
	}
	cout << endl;
	cout << "s2:" << s2 << endl;
	for (size_t i = 0; i < s2.size(); ++i) {
		cout << s2[i] << " ";
		//char& operator[] ( size_t pos ) ����posλ�õ��ַ���const string��������
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
	s.push_back('g');//void push_back(char c) ���ַ�����β���ַ�c
	cout << "s:" << s << endl;
	s.append(s1);//string& append (const char* s); ���ַ�����׷��һ���ַ���
	cout << "s:" << s << endl;
	s += "lmnop";//string& operator+=(const char* s) ���ַ�����׷��һ���ַ���
	cout << "s:" << s << endl;
	s += s2;//string& operator+=(const string& str)���ַ�����׷��sting���ַ���str
	cout << "s:" << s << endl;
	s += 'u';//string& operator+=(char c) ���ַ�����׷���ַ�c
	cout << "s:" << s << endl;
	s.pop_back();//void pop_back() ɾ���ַ������һ���ַ�
	cout << "s:" << s << endl;
	const char* c_s = s.c_str();//const char* c_str( )const ����C��ʽ�ַ���
	cout << "c_s:";
	for (int i = 0; c_s[i] != 0; ++i) { 
		cout << c_s[i] << " ";
	}
	cout << endl;
	char c = 'd';
	int pos = 0;
	size_t n = s.find(c, pos);
	//size_t find (char c, size_t pos =0)const
	//���ַ���posλ�ÿ�ʼ�������ַ�c�����ظ��ַ����ַ����е�λ��
	n ? cout << c << "���ַ���s�е�" << n << "��λ��\n" :
		cout << c << "���ڴ�" << pos << "λ�ÿ�ʼ������ַ�����\n";
	int npos = 10;
	n = s.rfind(c, npos);
	//size_t rfind (char c, size_t pos =0)const
	//���ַ���posλ�ÿ�ʼ��ǰ���ַ�c�����ظ��ַ����ַ����е�λ��
	n ? cout << c << "���ַ���s�е�" << n << "��λ��\n" : 
		cout << c << "���ڴ�" << npos << "λ�ÿ�ʼ������ַ�����\n";
	string s3 = s.substr(pos, npos);
	//string substr(size_t pos = 0, size_t n= npos)const
	//��str�д�posλ�ÿ�ʼ����ȡn���ַ���Ȼ���䷵��
	cout << "s3:" << s3;
	system("pause");
	system("cls");
}
int main() {
	test1();
	test2();
	test3();
	return 0;
 }