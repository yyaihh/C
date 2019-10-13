#pragma once
#include<iostream>
using namespace std;
class Orders {
	static double* m_s_OriginalCost;
	int m_size;
public:
	Orders();
	~Orders();
	static void input(int n);
	static void Free();
	double count(int n);
};

