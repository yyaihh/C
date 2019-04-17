#include<stdio.h>
#include<stdlib.h>
void main() {
	char A;
	char B;
	char C;
	char str;
	for (str = 'X'; str <= 'Z'; str++) {
		if (str != 'X' && str != 'Z') {
			C = str;
		}
	}
	for (str = 'X'; str <= 'Z'; str++){
		if (str != 'X' && str != C) {
			A = str;
		}
	}
	for (str = 'X'; str <= 'Z'; str++) {
		if (str != A && str != C) {
			B = str;
		}
	}
	printf("A的对手是%c\n", A);
	printf("B的对手是%c\n", B);
	printf("C的对手是%c\n", C);
	system("pause");
}