#include<iostream>
#include<ctime>
using namespace std;
#define N 1000
class WhiteMouse{
	int* m_mouse;
	int* m_drug;
	int m_msize;
	int m_dsize;
public:
	WhiteMouse(int num, int size) : m_msize(num), m_dsize(size) { 
		srand((unsigned int)time(0));
		m_mouse = new int[num];
		for (int i = 0; i < num; m_mouse[i++] = 0);
		m_drug = new int[size];
		for (int i = 0; i < size; m_drug[i++] = 0);
		m_drug[rand() % 1000] = 1;
	}
	~WhiteMouse() {
		delete m_mouse;
		delete m_drug;
	}
	int test(int start, int end);
	void dealpoison(int start, int end, int i);
	int poison();
};
int WhiteMouse::test(int start, int end) {
	for (int i = start; i < end; ++i) {
		m_drug[i] ? m_mouse[i] = 1 : i;
	}
}
void WhiteMouse::dealpoison(int start, int end, int i) {
	int mid;
	mid = test();
	dealpoison(start, mid - 1, i);
	dealpoison(mid + 1, end, i);
}
int WhiteMouse::poison() {

}
int main() {
	WhiteMouse a(10, N);
	cout << a.poison() << endl;
	system("pause");
	return 0;
}