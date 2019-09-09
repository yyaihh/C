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
//	cout << "TestA函数调用开始\n";
//	A a1, a2;
//	A a3(a1);
//	cout << "现在有" << A::GetACount() << "个对象" << endl;
//}
//int main() {
//	cout << "初始有" << A::GetACount() << "个对象" << endl;
//	A a1, a2;
//	cout << "未调用TesTA之前有" << A::GetACount() << "个对象" << endl;
//	TestA();
//	cout << "TestA函数调用结束\n";
//	cout << "现在有" << A::GetACount() << "个对象" << endl;
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
	cout << "打印a\n";
	a.PrintA();
	system("pause");
	return 0;
}
//explicit A(int a = 0) :m_a(a) {
//
//}