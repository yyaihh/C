#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 1.5
//方程为:2x^3 - 4x^2 + 3x - 6 = 0
void main() {
	double x0, x1, f, f1;
	x0 = N;
	while (1) {
		f = 2 * pow(x0, 3) - 4 * pow(x0, 2) + 3 * x0 - 6;
		f1 = 6 * pow(x0, 2) - 8 * x0 + 3;
		x1 = x0 - f / f1;
		if (fabs(x0 - x1) < 1e-5) {
			break;
		}
		x0 = x1;
	}
	printf("方程:2x^3 - 4x^2 + 3x - 6 = 0在%f附近的根为%f\n", N ,x1);
	system("pause");
}