#include  <stdlib.h>
#include  <stdio.h>
int main(){
	int a, b, c;
	for (int i = 100; i < 100000000; ++i) {
		a = i % 10;//��λ
		b = (i / 10) % 10;//ʮλ
		c = i / 100;//��λ
		if (i == a * a*a + b * b*b + c * c*c) {
			printf("%d\n", i);
		}
	}
	system("pause");
	return 0;
}