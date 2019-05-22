#if 0
#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a,const void* b) {
	return *(int*)a - *(int*)b;
}
int main() {
	int arr[10] = { 6,10,8,1,5,3,4,7,2,9 };
	printf("≈≈–Ú«∞:\n");
	for (int i = 0; i < 10; ++i) {
		printf("%d\t", arr[i]);
	}
	printf("\n≈≈–Ú∫Û\n");
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), cmp);
	for (int i = 0; i < 10; ++i) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
#endif
#if 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp_int(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
int cmp_double(const void* a, const void* b) {
	if (*(double*)a - *(double*)b > 0) {
		return 1;
	}
	else if (*(double*)a - *(double*)b < 0) {
		return -1;
	}
	else {
		return 0;
	}
}
int cmp_char(const void* a, const void* b) {
	return *(char*)a - *(char*)b;
}
int cmp_str(const void* a, const void* b) {
	return strcmp(*(char**)a, *(char**)b);
}
void swap(char* p, char* q, int m) {
	for (int i = 0; i < m; ++i, ++p, ++q) { //∞¥◊÷Ω⁄Ωªªª
		*p = *p^*q;
		*q = *p^*q;
		*p = *p^*q;
	}
}
void bsort(void* a,int n,int m,int (*cmp)(const void*, const void*)) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (cmp((char*)a + m * j, (char*)a + m * (j + 1)) > 0) { 
				swap((char*)a + m * j, (char*)a + m * (j + 1), m);
			}
		}
	}
}
int main() {
	int a1[10] = { 6,10,8,1,5,3,4,7,2,9 };
	char a2[10] = { 'b','g','a','d','e','r','c','f','n','z' };
	double a3[10]= { 6.23,10.12,8.34,1.0,5.6,3.90,4.788,7.3456,2.098,9.903 };
	char str1[5] = "dacd";
	char str2[5] = "abcd";
	char str3[5] = "edvv";
	char*a4[3] = { str1,str2,str3 };
	//1
	printf("int a1[10]≈≈–Ú«∞:\n");
	for (int i = 0; i < 10; ++i) {
		printf("%d\t", a1[i]);
	}
	printf("\nint a1[10]≈≈–Ú∫Û\n");
	bsort(a1, sizeof(a1) / sizeof(a1[0]), sizeof(a1[0]), cmp_int);
	for (int i = 0; i < 10; ++i) {
		printf("%d\t", a1[i]);
	}
	printf("\n\n");
	//2
	printf("char a2[10]≈≈–Ú«∞:\n");
	for (int i = 0; i < 10; ++i) {
		printf("%c\t", a2[i]);
	}
	printf("\nchar a2[10]≈≈–Ú∫Û\n");
	bsort(a2, sizeof(a2) / sizeof(a2[0]), sizeof(a2[0]), cmp_char);
	for (int i = 0; i < 10; ++i) {
		printf("%c\t", a2[i]);
	}
	printf("\n\n");
	//3
	printf("double a3[10]≈≈–Ú«∞:\n");
	for (int i = 0; i < 10; ++i) {
		printf("%f  ", a3[i]);
	}
	printf("\ndouble a3[10]≈≈–Ú∫Û\n");
	bsort(a3, sizeof(a3) / sizeof(a3[0]), sizeof(a3[0]), cmp_double);
	for (int i = 0; i < 10; ++i) {
		printf("%f  ", a3[i]);
}
	printf("\n\n");
	//4
	printf("char*a4[3]≈≈–Ú«∞:\n");
	for (int i = 0; i < 3; ++i) {
		printf("str%d=%s  ", i + 1, a4[i]);
	}
	printf("\nchar*a4[3]≈≈–Ú∫Û\n");
	bsort(a4, sizeof(a4) / sizeof(a4[0]), sizeof(a4[0]), cmp_str);
	for (int i = 0; i < 3; ++i) {
		printf("str%d=%s  ", i + 1, a4[i]);
	}
	printf("\n\n");
	system("pause");
	return 0;
}
#endif
#if 0
#include <stdio.h>
int main(int argc, char *argv[])
{
	int a = 10, b = 20;
	int *pa = &a;
	void * pa1 = (void *)pa;
	printf("int pa->a,%p\n", pa);
	printf("int pa+1=%p\n", (pa + 1));
	printf("void pa1->a,%p\n", pa1);
	printf("void pa1+1=%p\n", (pa1 + 1));
	system("pause");
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>
void swap(char *a, char *b) {
	char tmp;
	for (int i = 0; i < 8; ++i) {
		tmp = *a;
		*a = *b;
		*b = tmp;
		a++;
		b++;
	}
}

int int_cmp(const void *a, const void *b) {
	return *(int*)a - *(int *)b;
}


void bubble(void *arr, int size, int wid, int(*cmp)(const void *a, const void *b)) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - 1 - i; ++j) {
			if (cmp((char*)arr + j * wid, (char *)arr + wid * (j + 1)) > 0) {
				swap((int*)arr + j, (int *)arr + (j + 1));
			}
		}
	}
}


int main() {
	char arr1[4] = { "bcd" };
	char arr2[4] = { "abc" };
	double a = 3.236;
	double b = 4.675552;
	int aq[3][4];
	printf("%d:%p\n%d:%p\n", sizeof((&aq[1])),&aq[1],sizeof(aq+1),aq+1);
	/*int size = sizeof(arr) / sizeof(arr[0]);
	int wid = sizeof(arr[0]);
	bubble(arr, size, wid, int_cmp);
	for (int i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
	puts("\n");*/
	swap(&a, &b);
	printf("%f\n", a);
	puts(arr1);
	puts(arr2);
	system("pause");
	return 0;
}
#endif