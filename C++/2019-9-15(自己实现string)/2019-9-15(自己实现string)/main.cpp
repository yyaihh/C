#include"string.h"
int main() {
	String s;
	String s1;
	String s2("rst");
	String s3(s2);
	String s4(5, 'z');
	cout << "s2:" << s2 << endl;
	cout << "s3:" << s3 << endl;
	cout << "s4:" << s4 << endl;
	s = "bcd";
	cout << s << endl;
	s1 = "abcdefghijklmn";
	cout << "s1" << s1 << endl;
	s1 += 'o';
	cout << s1 << endl;
	s1 += "pq";
	cout << s1 << endl;
	s1 += s2;
	cout << s1 << endl;
	//cout << "字母" + s1 << endl;
	//cout << s1 + "uv" << endl;
	String s5 = "wx";
	//cout << s1 + s5 << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.resize(30, 'c');
	cout << s.capacity() << endl;
	s.empty() ? cout << "s为空\n" : cout << "s不为空\n";
	cout << s1.find('c') << endl;
	cout << s1.find("nop") << endl;
	cout << s1.find(s) << endl;
	cout << s << endl;
	s.clear();
	s.empty() ? cout << "s为空\n" : cout << "s不为空\n";
	cout << s << endl;
	system("pause");
	return 0;
}