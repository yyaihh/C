#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int fun(int x) {
	double m = sqrt(x);;
	for (int j = 2; j <= m; j++)
		if (x%j == 0)
			return 0;
	return 1;
}
void main() {
	int num;
	printf("请输入需要判断的数\n");
	scanf("%d", &num);
	if (fun(num) == 1) {
		printf("%d是素数\n", num);
	}
	else {
		printf("%d不是素数\n", num);
	}
	system("pause");
}