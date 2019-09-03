#include<iostream>
using namespace std;

class Ftest {
	int m_a;
	int m_b;
public:
	Ftest():
		m_a(0),
		m_b(0)
	{}
	Ftest(int a,int b):
		m_a(a),
		m_b(b)
	{}
	void SetFtest(int a, int b);
	friend ostream& operator<<(ostream& _cout, Ftest& data);
	friend istream& operator>>(istream& _cout, Ftest& data);
};
ostream& operator << (ostream& _cout, Ftest& data) {
	_cout << data.m_a << "  " << data.m_b << endl;
	return _cout;
}
istream& operator>>(istream& _cin, Ftest& data) {
	_cin >> data.m_a >> data.m_b;
	return _cin;
}
void Ftest::SetFtest(int a, int b) {
	m_a = a;
	m_b = b;
}
int main() {
	Ftest ft(100, 200);
	operator<<(cout, ft);
	cout << ft << endl;
	system("pause");
	return 0;
}
