#pragma once
#include<iostream>
using namespace std;
class Class {
	static int* m_OriginalCost;
	int m_size;
public:
	Class(int n);
	~Class();
	static void input(int n);
	static void m();
	int count(int n);
};

