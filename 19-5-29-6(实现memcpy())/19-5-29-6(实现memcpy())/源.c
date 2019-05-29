#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void* Memcpy(void* Dst, const void* Src, int size) {
	for (int i = 0; i < size; ++i) {
		*((char*)Dst + i) = *((char*)Src + i);
	}
	return Dst;
}
int main() {
	char str1[12] = "abcdef";
	char str2[12];
	int a = 520;
	int b;
	double c = 520.1314;
	double d;
	struct S {
		int aa;
		char str[5];
	}S1 ,S2;
	struct S* p = &S1;
	struct S* q = &S2;
	p->aa = 520;
	strcpy(p->str, "1314");
	Memcpy(str2, str1, 7);//7个字节
	Memcpy(&b, &a, 4);//四个字节
	printf("str2: %s\n", str2);
	printf("b = %d\n", b);
	Memcpy(&d, &c, 8);//八个字节
	printf("d = %f\n", d);
	Memcpy(q, p, 9);//九个字节
	printf("struct S2 :%d %s\n", q->aa, q->str);
	system("pause");
	return 0;
}