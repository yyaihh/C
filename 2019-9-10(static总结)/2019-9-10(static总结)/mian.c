#include<stdio.h>
#include<stdlib.h>
void test(int *pa);
int main() {
	int a = 0;
	int* pa = &a;
	test(pa);
	printf("a= %d\n", a);
	system("pause");
	return 0;
}

//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	printf("a= %d\n", a);
//	system("pause");
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int Max();
//int main() {
//	printf("请输入a和b的值\n");
//	extern a, b;
//	scanf("%d %d", &a, &b);
//	printf("最大值为:%d\n", Max());
//	system("pause");
//	return 0;
//}
//int a, b;
//int Max() {
//	return a > b ? a : b;
//}

//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int a;
//	int* pa = &a;
//	extern void input_a(int* pa);
//	void output_a(int* pa);
//	input_a(pa);
//	output_a(pa);
//	system("pause");
//	return 0;
//}
