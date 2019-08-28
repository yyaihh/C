#pragma once
#include<iostream>
using namespace std;
enum {
	SPADES,//黑桃
	HEARTS,//红桃
	CLUBS,//梅花
	DIAMONDS,//方片
	JOKER  //大小王
};

class Poker {
private:	
	int type;
	int point;
public:
	void input(int T, int P);
	void output();
	char Type() { return type; }
	int Point() { return point; }
};

class ALL {
private:
	Poker src[54];
	int size = 53;
public:
	void InitPoker();//初始化一副牌, 洗牌
	void allprint();
	Poker* fapai();//发牌
};

class Player {
private:
	Poker a[18];
	int size = 0;
public:
	void Draw1(ALL& A);//手动摸牌, 一次取一张摸牌
	void Draw18(ALL& A);//自动发牌,一次18张
	void print();//
	bool cmppoker(Poker a, Poker b);
	void InsertSort();//排序
};
