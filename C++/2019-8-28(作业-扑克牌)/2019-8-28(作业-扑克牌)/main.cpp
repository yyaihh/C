#include"class.h"

int main() {
	ALL a;
	cout << "洗牌后整副牌\n";
	a.InitPoker();
	a.allprint();//输出洗后的牌
	Player p[3];
#if 0
	//一人一张顺序抽取
	a.draw1(a, p[0], p[1], p[2]);
	
#else
	//给三个玩家随机生成18张牌
	for (int i = 0; i < 3; ++i) {
		p[i].Draw18(a);
	}
#endif
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
	system("pause");
}