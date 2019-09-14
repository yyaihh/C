#include"seqlist.h"
void test() {
	seqList<int> a(10);
	for (int i = 0; i < 12; ++i) {
		a.PushBack(i + 1);
	}
	a.PopBack();
	cout << a << endl;
	for (size_t i = 0; i < a.size(); ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}
int main() {
	test();
	system("pause");
	return 0;
}
