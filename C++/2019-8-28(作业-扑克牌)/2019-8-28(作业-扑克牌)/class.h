#pragma once
#include<iostream>
using namespace std;
enum {
	SPADES,//����
	HEARTS,//����
	CLUBS,//÷��
	DIAMONDS,//��Ƭ
	JOKER  //��С��
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
	void InitPoker();//��ʼ��һ����, ϴ��
	void allprint();
	Poker* fapai();//����
};

class Player {
private:
	Poker a[18];
	int size = 0;
public:
	void Draw1(ALL& A);//�ֶ�����, һ��ȡһ������
	void Draw18(ALL& A);//�Զ�����,һ��18��
	void print();//
	bool cmppoker(Poker a, Poker b);
	void InsertSort();//����
};
