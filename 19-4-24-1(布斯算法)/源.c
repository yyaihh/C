#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int a = 0;
int b = 0;
int c = 0;
void p(int num, int m) {
	if (m!= 1 && m != 0) {
		p(num / 2, --m);
	}
	printf("%d", num % 2);
	if (m == 0) {
		printf("0");
	}
}
void print(int num, int m,int XY) {
	p(XY, 2);
	printf(".");
	p(num, m);
	printf("\n");
}
int complement(int num, int m) {//用无符号十进制数字的形式表示二进制补码
	int count = 0;
	int n, complement = 0;
	m = 0;
	if (num < 0) {
		num = -num;
		n = num;
		while (n) {
			++count;
			n /= 2;
		}
		for (int i = 0; i < count; ++i) {
			if ((num&(1 << i)) == 0) {
				complement += (int)pow(2, i);
			}
		}
		complement += 1;//补码
		n = complement;
		while (n) {
			++m;
			n /= 2;
		}
		m = m > count ? m : count;
	}
	else {
		complement = num;
		n = complement;
		while (n) {
			++m;
			n /= 2;
		}
	}
	return complement;
}

void Booth(int x, int y) {//
	int xb, yb, _xb;
	int X = 0, Y = 0, _X = 0;
	if (x < 0) {
		X = 3;
	}
	if(-x < 0) {
		_X = 3;
	}
	if (y < 0) {
		Y = 3;
	}
	xb = complement(x, a);
	print(xb, a, X);
	yb = complement(y, b);
	print(yb, b, Y);
	_xb = complement(-x, a);
	print(_xb, a, _X);
	int xyb = y;
	int n;
	int XY = Y;
	int yb_1 = 0;
	for (int i = 0; i < 1; ++i) {
		if (yb % 2 == yb_1) {
		}
		else if (yb % 2 > yb_1) {
			xyb = xyb + _xb;
			if (XY + _X > 3) {
				XY = 0;
			}
			else {
				XY = XY + _X;
			}
			c = 0;
			n = xyb;
			while (n) {
				++c;
				n /= 2;
			}
		}
		else {
			xyb = xyb + xb;
			if (XY + X > 3) {
				XY = 0;
			}
			else {
				XY = XY + X;
			}
			c = 0;
			n = xyb;
			while (n) {
				++c;
				n /= 2;
			}
		}
		yb_1 = yb % 2;
		xyb = xyb >> 1;
		if (XY == 1 || XY == 3) {
			xyb = xyb + (int)pow(2, c - 1);
		}
		if (XY > 1) {
			XY = 2 + (XY >> 1);
		}
		else {
			XY = XY >> 1;
		}
		yb = yb >> 1;
		if (Y == 1 || Y == 3) {
			yb = yb + (int)pow(2, b - 1);
		}
		if (Y > 1) {
			Y = 2 + (Y >> 1);
		}
		else {
			Y = Y >> 1;
		}
	}
	
	if (yb % 2 == yb_1) {
	}
	else if (yb % 2 > yb_1) {
		xyb = xyb + _xb;
		if (XY + _X > 3) {
			XY = 0;
		}
		else {
			XY = XY + _X;
		}
		c = 0;
		n = xyb;
		while (n) {
			++c;
			n /= 2;
		}
	}
	else {
		xyb = xyb + xb;
		if (XY + X > 3) {
			XY = 0;
		}
		else {
			XY = XY + X;
		}
		c = 0;
		n = xyb;
		while (n) {
			++c;
			n /= 2;
		}
	}


	n = xyb;
	c = 0;
	while (n) {
		++c;
		n /= 2;
	}
	print(xyb, c, XY);
}
void main() {
	int x, y, n;
	scanf("%d %d", &x, &y);
	n = x;
	while (n) {
		++a;
		n /= 2;
	}
	n = y;
	while (n) {
		++b;
		n /= 2;
	}
	Booth(x, y);
	system("pause");
}
