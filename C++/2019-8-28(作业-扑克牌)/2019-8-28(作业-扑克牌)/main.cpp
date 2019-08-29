#include"class.h"

int main() {
#if 1
	//一人一张顺序抽取
	ALL a;
	cout << "洗牌后整副牌\n";
	a.InitPoker();
	a.allprint();//输出洗后的牌
	Player p[3];
	a.draw1(a, p[0], p[1], p[2]);
	for (int i = 0; i < 3; ++i) { 
		cout << "玩家" << i + 1 << "抽取的牌\n";
		p[i].print();
	}
	for (int i = 0; i < 3; ++i) {
		p[i].InsertSort();//排序
	}
	for (int i = 0; i < 3; ++i) {
		cout << "整牌后玩家" << i + 1 << "抽取的牌\n";
		p[i].print();
	}
	
#else
	//一次性随机给三个玩家18张牌
	ALL a;
	cout << "洗牌后整副牌\n";
	a.InitPoker();
	a.allprint();//输出洗后的牌
	Player p[3];
	for (int i = 0; i < 3; ++i) {
		p[i].Draw18(a);
	}
	for (int i = 0; i < 3; ++i) {
		cout << "玩家" << i + 1 << "抽取的牌\n";
		p[i].print();
	}
	for (int i = 0; i < 3; ++i) {
		p[i].InsertSort();//排序
	}
	for (int i = 0; i < 3; ++i) {
		cout << "整牌后玩家" << i + 1 << "抽取的牌\n";
		p[i].print();
	}
#endif
	system("pause");
}