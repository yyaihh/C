#include<iostream>
using namespace std;
class Test {
	size_t m_size;
	int* m_arr;
public:
	Test(size_t size = 0) {
		m_size = size;
		m_arr = (int*)malloc(sizeof(int)*size);
	}
	~Test() {
		if (m_arr) {
			free(m_arr);
		}
	}
	Test& operator=(const Test& t);
	void SetTest();
	void PrintTest()const;
};
Test& Test::operator=(const Test& t) {
	m_size = t.m_size;
	m_arr = (int*)malloc(sizeof(int)*m_size);
	for (int i = 0; i < (int)m_size; ++i) {
		m_arr[i] = t.m_arr[i];
	}
	return *this;
}
void Test::SetTest() {
	for (int i = 0; i < (int)m_size; ++i) {
		cout << "请输入第" << i + 1 << "个元素的值\n";
		cin >> m_arr[i];
	}
}
void Test::PrintTest() const { 
	for (int i = 0; i < (int)m_size; ++i) {
		cout << m_arr[i] << "  ";
	}
	cout << endl;
}
void test() {
	Test a(3);
	Test b;
	cout << "给对象a输入数据\n";
	a.SetTest();
	cout << "打印对象a:\n";
	a.PrintTest();
	b = a;
	cout << "打印对象b:\n";
	b.PrintTest();
	cout << "给对象b输入数据\n";
	b.SetTest();
	cout << "打印对象b:\n";
	b.PrintTest();
	cout << "打印对象a:\n";
	a.PrintTest();
}
int main_() {
	test();
	system("pause");
	return 0;
}