#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 50 //二分次数
double fun(double x1, double x2) {
	int count = 0;
	double f1, f2, fm, mid;
	while (1) {
		f1 = 2 * pow(x1, 3) - 4 * pow(x1, 2) + 3 * x1 - 6;
		f2 = 2 * pow(x2, 3) - 4 * pow(x2, 2) + 3 * x2 - 6;
		if (f1 * f2 > 0) {
			return 0;
		}
		++count;
		mid = (x1 + x2) / 2;
		fm = 2 * pow(mid, 3) - 4 * pow(mid, 2) + 3 * mid - 6;
		if (fm * f1 == 0 || fm * f2 == 0 || count == N) {//循环终止条件,(找出根的准确值或者已达二分次数)
			break;
		}
		if (fm * f1 < 0) {
			x2 = mid;
		}
		else if (fm * f2 < 0) {
			x1 = mid;
		}
	}
	return mid;
}
void main() {
	int x1 = -10;
	int x2 = 10;
	if (fun(x1, x2) != 0) {
		printf("方程2x^3 - 4x^2 + 3x - 6 = 0在区间(%d,%d)之间的根为:%f\n", x1, x2, fun(x1, x2));
	}
	else {
		printf("方程2x^3 - 4x^2 + 3x - 6 = 0在区间(%d,%d)之间无根\n",x1, x2);
	}
	system("pause");
}