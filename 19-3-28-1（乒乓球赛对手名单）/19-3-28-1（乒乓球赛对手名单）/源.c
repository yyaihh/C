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
	printf("A�Ķ�����%c\n", A);
	printf("B�Ķ�����%c\n", B);
	printf("C�Ķ�����%c\n", C);
	system("pause");
}