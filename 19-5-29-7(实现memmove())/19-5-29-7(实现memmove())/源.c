#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void* Memmove(void* Dst, const void* Src, int size) {
	for (int i = size; i >= 0; --i) {
		*((char*)Dst + i) = *((char*)Src + i);
	}
	return Dst;
}
void* Memcpy(void* Dst, const void* Src, int size) {
	for (int i = 0; i < size; ++i) {
		*((char*)Dst + i) = *((char*)Src + i);
	}
	return Dst;
}
int main() {
	char str1[30] = "abcdefghij";
	char str2[30] = "abcdefghij";
	char* s1 = str1 + 4;
	char* s2 = str2 + 4;
	memmove(s1, str1, 11);
	memcpy(s2, str2, 11);
	printf("%s\n", s1);
	printf("%s\n", str1);
	printf("%s\n", s2);
	printf("%s\n", str2);
	system("pause");
	return 0;
}
