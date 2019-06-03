#include<stdio.h>
#include<stdlib.h>

int main() {
	int a = 1;
	int b[7] = { 2,3,4,5,6,7,8 };
	int c = 9;
	for (int i = -1; i <= 7; ++i) {
		printf("%d\n", b[i]);
	}
	system("pause");
	return 0;
}