#include"fun.h"
#define N 10
int main() {
	
	int src1[N] = { 4,8,1,6,9,10,2,7,3,5 };
	double src2[N] = { 4.5,8.6,1.7,6.8,9.67,10.90,2.45,7.67,3.12,5.1 };
	mysort(src1, N);
	PrintArray(src1, N);
	mysort(src2, N, 100);
	PrintArray(src2, N);
	system("pause");
	return 0;
}