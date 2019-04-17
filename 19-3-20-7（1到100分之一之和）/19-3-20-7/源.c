//1/1-1/2+1/3-1/4+1/5 ¡­¡­ + 1/99 - 1/100 µÄÖµ¡£
#include<stdio.h>
#include<stdlib.h>
void main() {
	double s=0;
	int a = 1;
	for (int i = 1; i <= 100; i++) {
			s = s + a*1.0 / i;
			a = -a;
		}
	
	printf("%f\n", s);
	system("pause");
}