#include "Mahjong.h"
#include<ctime>


Mahjong::Mahjong(int a, int b) {
	m_type = a;
	m_point = b;
}


Mahjong::~Mahjong() {
	
}

void Swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}
void Mahjong::output() {
	const char* Type[5] = { "万","条","筒","东" ,"南","西","北","中","白" };
	const char* Point[16] = { "","A","2","3","4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "小王", "大王" };
	cout << Type[type] << Point[point] << "  ";
}
void PackCards::InitPoker() {//初始化,洗牌
	int rn[54];
	srand((unsigned int)time(0));
	for (int i = 0; i < 54; ++i) {
		rn[i] = i;
	}
	for (int i = 0; i < 50; ++i) {
		Swap(rn[rand() % 54], rn[rand() % 54]);
	}
	for (int n = 0, i = 0; n < 4; ++n) {
		for (int m = 1; m < 14; ++m) {
			src[rn[i++]].input(n, m);
		}
	}
	src[rn[52]].input(4, 1);
	src[rn[53]].input(4, 2);
}
void PackCards::allprint() {
	for (auto i : src) {
		i.output();
	}
	cout << endl << endl;
}
Poker* PackCards::fapai() {
	if (size >= 0) {
		return &src[size--];
	}
	else {
		cout << "牌发完了!";
		return nullptr;
	}
}
void Player::Draw1_(ALL& A) {
	if (size < 18) {
		a[size++] = *(A.fapai());
	}
	else {
		cout << "取牌结束\n";
	}
}

void Player::Draw18(PackCards& A) {
	for (auto& i : a) {
		i = *(A.fapai());
	}
}
void PackCards::draw1(PackCards& A, Player& p1, Player& p2, Player& p3) {
	for (int i = 0; i < 18; ++i) {
		p1.Draw1_(A);
		p2.Draw1_(A);
		p3.Draw1_(A);
	}
}
void Player::print() {
	for (auto i : a) {
		i.output();
	}
	cout << endl << endl << endl;
}
bool Player::cmppoker(Poker a, Poker b) {
	return (a.Point() > b.Point()) ||
		(a.Point() == b.Point() && a.Type() < b.Type());
}
void Player::InsertSort() {
	int i, j;
	Poker tmp;

	for (i = 1; i < 18; i++)
	{
		tmp = a[i];

		for (j = i; j > 0 && cmppoker(tmp, a[j - 1]); j--)
		{
			a[j] = a[j - 1];
		}

		a[j] = tmp;
	}
}

