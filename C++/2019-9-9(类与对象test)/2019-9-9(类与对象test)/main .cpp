//#include<iostream>
//using namespace std;
//class A {
//	static int m_s_count;
//	int n;
//public:
//	A() {
//		++m_s_count;
//	}
//	A(const A& t) { 
//		++m_s_count; 
//	}
//	~A() {
//		--m_s_count;
//	}
//	static int GetACount() {
//		return m_s_count;
//	}
//};
//int A:: m_s_count= 0;
//void TestA() {
//	cout << "TestA�������ÿ�ʼ\n";
//	A a1, a2;
//	A a3(a1);
//	cout << "������" << A::GetACount() << "������" << endl;
//}
//int main() {
//	cout << "��ʼ��" << A::GetACount() << "������" << endl;
//	A a1, a2;
//	cout << "δ����TesTA֮ǰ��" << A::GetACount() << "������" << endl;
//	TestA();
//	cout << "TestA�������ý���\n";
//	cout << "������" << A::GetACount() << "������" << endl;
//	system("pause");
//	return 0;
//}
#include<iostream>
using namespace std;
class A {
	int m_a;
public:
	explicit A(int a = 0) :m_a(a) {
	
	}
	void PrintA();
};
void A::PrintA() {
	cout << m_a << endl;
}
int main() {
	A a;
	a = 100;
	cout << "��ӡa\n";
	a.PrintA();
	system("pause");
	return 0;
}
//explicit A(int a = 0) :m_a(a) {
//
//}