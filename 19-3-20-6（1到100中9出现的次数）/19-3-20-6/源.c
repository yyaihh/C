#include<stdio.h>
#include<stdlib.h>
void main() {
	int num = 0;
	for (int i = 1; i <= 100; i++) {
		if (i % 10 == 9)
			num++;
		if ((i / 10) % 10 == 9)
			num++;
	}
	printf("从1到100中的所有整数中数字9出现的次数为:%d\n", num);
	system("pause");
}