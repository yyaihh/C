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
	printf("��1��100�е���������������9���ֵĴ���Ϊ:%d\n", num);
	system("pause");
}