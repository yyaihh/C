#include"Orders.h"

int main() {
	int n;
	cout << "请输入产品类型数\n";
	cin >> n;
	Orders::input(n);//输入原价, 如需更改原价重新调用
	Orders a;
	double m = a.count(n);
	cout << "订单价格为:" << m << endl;
	//更改原价, 产品数, 数量
	cout << "请重新输入产品类型数\n";
	cin >> n;
	Orders::input(n);
	m = a.count(n);
	cout << "订单价格为:" << m << endl;

	Orders::Free();
	system("pause");
	return 0;
}