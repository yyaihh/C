#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 10000//�������仮�ֳɵȼ���10000��,����С����Խ��,���ֽ��Խ׼ȷ
double integral_sin(double a, double b) {
	double sum = 0;
	for (double i = a; i <= b; i += (1.0 / N)) {
		sum += sin(i)*(1.0 / N);//sin(i)*(1.0 / N)Ϊÿһ��С���ε����
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
	printf("��ֱ���������[a,b] a��ֵ��b��ֵ\n");
	scanf("%lf %lf", &a ,&b);
	printf("sin������%f��%f�ϵĻ���Ϊ%f\n", a, b, integral_sin(a, b));
	printf("cos������%f��%f�ϵĻ���Ϊ%f\n", a, b, integral_cos(a, b));
	printf("e^x������%f��%f�ϵĻ���Ϊ%f\n", a, b, integral_ex(a, b));
	system("pause");
}