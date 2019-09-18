#include"string.h"
#include<string>
void test1() {
	cout << "test1()\n\n";
	String s;
	s = "bcd";
	String s1;
	s1 = "abcdefghijklmn";
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.resize(30, 'c');
	cout << s.capacity() << endl;
	s.empty() ? cout << "sΪ��\n" : cout << "s��Ϊ��\n";
	cout << s1.find('c') << endl;
	cout << s1.find("nop") << endl;
	cout << s1.find(s) << endl;
	cout << s << endl;
	s.clear();
	s.empty() ? cout << "sΪ��\n" : cout << "s��Ϊ��\n";
	cout << s << endl;
	system("pause");
	system("cls");
}
void test2() {
	cout << "test2()\n\n";
	String s;
	s = "bcd";
	String s1;
	s1 = "abcdefghijklmn";
	String s2("rst");
	String s3(s2);
	String s4(5, 'z');
	cout <<"s: "<< s << endl;
	cout << "s1: " << s1 << endl;
	cout << "s2 :" << s2 << endl;
	cout << "s3 :" << s3 << endl;
	cout << "s4 :" << s4 << endl;
	s1 += 'o';
	cout << "s1: " << s1 << endl;
	s1 += "pq";
	cout << "s1: " << s1 << endl;
	s1 += s2;
	cout << "s1: " << s1 << endl;
	s1 = "��ĸ" + s1;
	cout << "s1: " << s1 << endl;
	s1 = s1 + "uv";
	cout << "s1: " << s1 << endl;
	String s5 = "wx";
	s1 = s1 + s5;
	cout << "s1: " << s1 << endl;
	const char* c_s = s1.c_str();
	cout << "c_S: ";
	for (size_t i = 0; i < s1.size(); ++i) {
		cout << c_s[i];
	}
	cout << endl;
	system("pause");
	system("cls");
}
void test3() {
	cout << "test3()\n\n";
	String s1;
	s1 = "abcdefghijklmn";
	const char* c_s2 = "lmn";
	const char* c_s3 = "abcf";
	const char* c_s4 = "ghi";
	String s2(c_s2);
	String s3(c_s3);
	String s4(c_s4);
	cout << "s1 :" << s1 << endl;
	cout << "s2 :" << s2 << endl;
	cout << "s3 :" << s3 << endl;
	cout << "s4 :" << s4 << endl;
	cout << "c_s2 :" << c_s2 << endl;
	cout << "c_s3 :" << c_s3 << endl;
	cout << "c_s4 :" << c_s4 << endl;
	char c1 = 'd';
	char c2 = 'z';
	cout << s1.find(c1) << endl;
	cout << s1.find(c2) << endl;
	cout << s1.find(c_s2) << endl;
	cout << s1.find(c_s3) << endl;
	cout << s1.find(c_s4) << endl;
	cout << s1.find(s2) << endl;
	cout << s1.find(s3) << endl;
	cout << s1.find(s4) << endl;
	cout << s1.rfind(s2, s1.size()) << endl;
	cout << s1.rfind(s3, s1.size()) << endl;
	cout << s1.rfind(s4, s1.size()) << endl;
	
	cout << s1.substr(10, 10) << endl;
	String s10;
	s10 = "123456789";
	cout << s10.substr(3, 7)<< endl;
	cout << s10.substr(10, 7) << endl;
	system("pause");
	system("cls");
}
void test4() {
	cout << "test4()\n\n";
	String s1 = "abcde";
	String s2 = "abc";
	String s3 = "cde";
	String s4(s1);
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	cout << "s4: " << s4 << endl;
	s1 < s2 ? cout << "s1<s2\n" : cout << "s1>=s2\n";
	s3 > s2 ? cout << "s3>s2\n" : cout << "s3<=s2\n";
	s1 <= s2 ? cout << "s1<=s2\n" : cout << "s1>s2\n";
	s3 >= s2 ? cout << "s3>=s2\n" : cout << "s3<s2\n";
	s1 == s4 ? cout << "s1==s4\n" : cout << "s1!=s4\n";
	s1 != s2 ? cout << "s1!=s2\n" : cout << "s1==s2\n";
	const char* c_s1 = s1.c_str();
	const char* c_s2 = s2.c_str();
	const char* c_s3 = s3.c_str();
	const char* c_s4 = s4.c_str();
	cout << "c_s1: " << c_s1 << endl;
	cout << "c_s2: " << c_s2 << endl;
	cout << "c_s3: " << c_s3 << endl;
	cout << "c_s4: " << c_s4 << endl;
	s1 < c_s2 ? cout << "s1<c_s2\n" : cout << "s1>=c_s2\n";
	s3 > c_s2 ? cout << "s3>c_s2\n" : cout << "s3<=c_s2\n";
	s1 <= c_s2 ? cout << "s1<=s2\n" : cout << "s1>s2\n";
	s3 >= c_s2 ? cout << "s3>=s2\n" : cout << "s3<s2\n";
	s1 == c_s4 ? cout << "s1==c_s4\n" : cout << "s1!=c_s4\n";
	s1 != c_s2 ? cout << "s1!=c_s2\n" : cout << "s1==c_s2\n";
	cout << "\n\n\n";
	c_s2 > s1 ? cout << " c_s2>s1\n" : cout << "c_s2<=s1\n";
	c_s2 < s3 ? cout << " c_s2<s3\n" : cout << "c_s2>=s3\n";
	c_s2 >= s1 ? cout << "c_s2>=s1\n" : cout << "c_s2<s1\n";
	c_s2 <= s3 ? cout << "c_s2<=s3\n" : cout << "c_s2>s3\n";
	c_s4 == s1 ? cout << "c_s4==s1\n" : cout << "c_s4!=s1\n";
	c_s2 != s1 ? cout << "c_s2!=s1\n" : cout << "c_s2==s1\n";
	system("pause");
	system("cls");
}
void test5() {
	cout << "test5()\n\n";
	String s1;
	cout << "������s1\n";
	cin >> s1;
	cout <<"s1: "<< s1 << endl;
	String s2;
	cout << "������s2\n";
	getline(cin, s2);
	cout << "s2: " << s2 << endl;
	cout << "������s2, #����\n";
	getline(cin, s2, '#');
	cout << "s2: " << s2 << endl;
	system("pause");
	system("cls");
}
int main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	return 0;
}