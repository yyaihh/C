#include"solution.h"
int main() {
	string s1;
	string s2;
	solution mul;
	cout << "ÇëÊäÈës1\n";
	mul.input(s1);
	cout << "s1= " << s1 << endl;
	cout << "ÇëÊäÈës2\n";
	mul.input(s2);
	cout << "s2= " << s2 << endl;
	cout << s1 << " x " << s2 << " = ";
	cout << mul.multiply(s1, s2) << endl;
	system("pause");
	return 0;
}
