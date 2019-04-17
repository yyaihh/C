#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void height1(double _x, double _y) {
	if (sqrt((_x - 2) * (_x - 2 )+ (_y - 2) * (_y - 2)) <= 1) {
		printf("高度为10m\n");
		return;
	}
	else if (sqrt((_x + 2) * (_x + 2) + (_y - 2) * (_y - 2)) <= 1) {
		printf("高度为10m\n");
		return;
	}
	else if (sqrt((_x + 2) * (_x + 2) + (_y + 2) * (_y + 2)) <= 1) {
		printf("高度为10m\n");
		return;
	}
	else if (sqrt((_x - 2) * (_x - 2) + (_y + 2) * (_y + 2)) <= 1) {
		printf("高度为10m\n");
		return;
	}
	else {
		printf("高度为0m\n");
	}
}
void height2(double _x, double _y) {
	int a = 2;
	int b = 2;
	int i, m = 0;
	for (i = 0; i < 2; ++i) {
		a = -a;
		for (int j = 0; j < 2; ++j) {
			b = -b;
			if (sqrt((_x - a) * (_x - a) + (_y - b) * (_y - b)) <= 1) {
				printf("高度为10m\n");
				m = 1;
				break;
			}
		}
		if (m == 1) {
			break;
		}
	}
	if (i == 2) {
		printf("高度为0m\n");
	}
}
void main() {
	double x = 0;
	double y = 0;
	printf("请输入x，y的值\n");
	scanf("%lf %lf", &x, &y);
	height1(x, y);
	height2(x,y);
	system("pause");
}
