#include "Solution.h"
int main() {
	string s1("999");
	string s2("1999");
	Solution mul;
	cout << "s1= " << s1 << endl;
	cout << "s2= " << s2 << endl;
	cout << s1 << " + " << s2 << " = ";
	cout << mul.Add(s1, s2) << endl;
	system("pause");
	return 0;
}