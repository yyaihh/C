#include"Class.h"

int main() {
	int n;
	cout << "请输入产品类型数\n";
	cin >> n;
	Class::input(n);//输入原价, 如需更改原价重新调用
	Class a(n);
	int m = a.count(n);
	cout << "订单价格为:" << m << endl;
	Class::m();
	system("pause");
	return 0;
}