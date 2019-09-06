#include<iostream>
#include<ctime>
using namespace std;
class Drug {
	int* m_drug;
	int m_dsize;
public:
	int fun1();
	int* fun2();
	Drug(int size) :m_dsize(size){
		srand((unsigned int)time(0));
		m_drug = new int[size];
		for (int i = 0; i < size; m_drug[i++] = 0);
		int n = rand() % 1000;
		cout << "毒药是第" << n + 1 << endl;
		m_drug[n] = 1;
	}
	~Drug() {
		delete m_drug;
	}
	int num();
};
int Drug::fun1() {
	return m_dsize;
}
int* Drug::fun2() {
	return m_drug;
}
int Drug::num() {
	int num = 1;
	for (int i = 1; i * 2 < m_dsize; i *= 2, ++num);
	return num;
}

class WhiteMouse{
	int* m_mouse;
	int m_msize;
public:
	WhiteMouse() {

	}
	~WhiteMouse() {
		delete m_mouse;
	}
	int poison(Drug& a);
};
int WhiteMouse::poison(Drug& d) {
	int num = d.num();
	if (num < 1)return 0;
	m_msize = num;
	m_mouse = new int[m_msize];
	for (int i = 0; i < m_msize; m_mouse[i++] = 0);
	int size = d.fun1();
	int* drug = d.fun2();
	if (size < 1) {
		cout << "药瓶数不能小于1\n";
		return 0;
	}
	int n = 0;
	for (int i = size / 2, k = 0; i > 0; i /= 2, ++k) {
		for (int j = 0; j < size; j += (2 * i)) {
			size <= j + i ? n = size : n = j + i;
			cout << j << "-" << n << "  ";
			for (int a = j; a < n; ++a) {
				if (drug[a]) {
					m_mouse[k] = 1;
				}
			}
		}
		cout << endl<<endl;
	}
	for (int i = 0; i < m_msize; ++i) {
		cout << m_mouse[i]<<" ";
	}
	return -1;
}
int main() {
	Drug a(1000);
	WhiteMouse b;
	b.poison(a);
	system("pause");
	return 0;
}