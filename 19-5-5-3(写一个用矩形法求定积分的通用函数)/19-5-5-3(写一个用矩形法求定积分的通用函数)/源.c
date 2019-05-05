#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 10000//积分区间划分成等间距的10000格,划分小矩形越多,积分结果越准确
double integral_sin(double a, double b) {
	double sum = 0;
	for (double i = a; i <= b; i += (1.0 / N)) {
		sum += sin(i)*(1.0 / N);//sin(i)*(1.0 / N)为每一个小矩形的面积
	}
	return sum;
}
double integral_cos(double a, double b) {
	double sum = 0;
	for (double i = a; i <= b; i += (1.0 / N)) {
		sum += cos(i)*(1.0 / N);
	}
	return sum;
}
double integral_ex(double a, double b) {
	double sum = 0;
	for (double i = a; i <= b; i += (1.0 / N)) {
		sum += exp(i)*(1.0 / N);
	}
	return sum;
}
void main() {
	double a, b;
	printf("请分别输入区间[a,b] a的值与b的值\n");
	scanf("%lf %lf", &a ,&b);
	printf("sin函数在%f到%f上的积分为%f\n", a, b, integral_sin(a, b));
	printf("cos函数在%f到%f上的积分为%f\n", a, b, integral_cos(a, b));
	printf("e^x函数在%f到%f上的积分为%f\n", a, b, integral_ex(a, b));
	system("pause");
}