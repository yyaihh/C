#include"class.h"

int main() {
#if 1
	//一人一张顺序抽取
	ALL a;
	//cout << "洗牌后\n";
	a.InitPoker();
	//a.allprint();//输出洗后的牌
	Player p1, p2, p3;
	a.draw1(a, p1, p2, p3);
	cout << "玩家1抽取的牌\n";
	p1.print();
	p1.InsertSort();
	cout << "整牌后\n";
	p1.print();
	cout << "玩家2抽取的牌\n";
	p2.print();
	p2.InsertSort();
	cout << "整牌后\n";
	p2.print();
	cout << "玩家3抽取的牌\n";
	p3.print();
	p3.InsertSort();
	cout << "整牌后\n";
	p3.print();
#else
	//一次性随机给三个玩家18张牌
	ALL a;
	a.InitPoker();
	Player p1, p2, p3;
	p1.Draw18(a);
	p2.Draw18(a);
	p3.Draw18(a);
	cout << "玩家1抽取的牌\n";
	p1.print();
	p1.InsertSort();
	cout << "整牌后\n";
	p1.print();
	cout << "玩家2抽取的牌\n";
	p2.print();
	p2.InsertSort();
	cout << "整牌后\n";
	p2.print();
	cout << "玩家3抽取的牌\n";
	p3.print();
	p3.InsertSort();
	cout << "整牌后\n";
	p3.print(); 
#endif
	system("pause");
}