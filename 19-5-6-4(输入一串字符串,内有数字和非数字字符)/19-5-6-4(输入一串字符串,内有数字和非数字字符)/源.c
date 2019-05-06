#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void fun(int n, int m, char* p) {
	int k = m - 1;
	int count = 1;
	int* q = malloc(m * sizeof(int));
	*(q + k) = 0;
	for (int i = n; i >= 0; --i) {
		if (*(p + i) > 47 && *(p + i) < 58) {
			*(q + k) += count * (*(p + i) - 48);
			count *= 10;
		}
		else if (*(p + i + 1) > 47 && *(p + i + 1) < 58 && (*(p + i) < 48 || *(p + i) > 57)) {
			k -= 1;
			count = 1;
			*(q + k) = 0;
		}
	}
	for (int i = 0; i < m; ++i) {
		printf("%d\t", *(q + i));
	}
	printf("\n");
}
void main() {
	char str[1024] = { '\0' };
	char ch;
	char* p = str;
	int i, count = 0;
	for (i = 0; i < 1023; ++i) {
		ch = getchar();
		if (ch == '\n') {
			if (p[i - 1] > 47 && p[i - 1] < 58) {
				count += 1;
			}
			break;
		}
		if (i > 0 && p[i - 1] > 47 && p[i - 1] < 58 && (ch < 48 || ch > 57)) {
			count += 1;
		}
		p[i] = ch;
	}
	printf("字符串%s中\n", p);
	printf("共有整数%d个\n分别是\n", count);
	fun(i, count, p);
	system("pause");
}
