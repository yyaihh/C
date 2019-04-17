#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void fun1(int profit) {
	double bonus = 0.0;
	if (profit <= 100000) {
		bonus = profit * 0.1;
	}
	if (profit <= 200000 && profit > 100000) {
		bonus = (profit - 100000) * 0.075 + 10000;
	}
	if (profit <= 400000 && profit > 200000) {
		bonus = (profit - 200000) * 0.05 + 17500;
	}
	if (profit <= 600000 && profit > 400000) {
		bonus = (profit - 400000) * 0.03 + 27500;
	}
	if (profit <= 600000 && profit > 1000000) {
		bonus = (profit - 200000) * 0.015 + 33500;
	}
	if (profit >= 1000000) {
		bonus = (profit - 1000000) * 0.01 + 37500;
	}
	printf("奖金为%lf\n", bonus);
}
void fun2(int profit) {
	double bonus = 0.0;
	if (profit > 1000000) {
		bonus = (profit - 1000000) * 0.01;
		profit = 1000000;
	}
	if (profit <= 1000000 && profit > 600000) {
		bonus = (profit - 600000) * 0.015 + bonus;
		profit = 600000;
	}
	if (profit <= 600000 && profit > 400000) {
		bonus = (profit - 400000) * 0.03 + bonus;
		profit = 400000;
	}
	if (profit <= 400000 && profit > 200000) {
		bonus = (profit - 200000) * 0.05 + bonus;
		profit = 200000;
	}
	if (profit <= 200000 && profit > 100000) {
		bonus = (profit - 100000) * 0.075 + bonus;
		profit = 100000;
	}
	if (profit <= 100000) {
		bonus = profit * 0.1 + bonus;
	}
	printf("奖金为%lf\n", bonus);
}
void main() {
	int profit_;
	printf("请输入利润数\n");
	scanf("%d", &profit_);
	fun1(profit_);
	fun2(profit_);
	system("pause");
}