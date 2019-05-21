#if 0
#include<stdio.h>
#include<stdlib.h>
int main() {
	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int(*p)[4] = a;
	printf("\t[0]\t[1]\t[2]\t[3]\n");
	for (int i = 0; i < 3; ++i, printf("\n")) {
		printf("a[%d]\t", i);
		for (int j = 0; j < 4; ++j) {
			printf("%d\t", *(*(p + i) + j));//等价printf("%d\t", a[i][j]);
		}
	}
	printf("\n数组各元素地址为\n");
	printf("\t[0]\t\t[1]\t\t[2]\t\t[3]\n");
	for (int i = 0; i < 3; ++i, printf("\n")) {
		printf("a[%d]\t", i);
		for (int j = 0; j < 4; ++j) {
			printf("%p\t", *(p + i) + j);
		}
	}
	printf("\n");
	printf("&a\t=%p\n", &a);
	printf("&a+1\t=%p\n\n", &a + 1);

	printf("a\t=%p,解引用为:%d\n", a, **a);
	printf("a+1\t=%p,解引用为:%d\n\n", a + 1, **(a + 1));

	printf("&a[0]\t=%p\n", &a[0]);
	printf("&a[0]+1\t=%p\n", &a[0]+1);
	printf("a[0]\t=%p,解引用为:%d\n", a[0], *a[0]);
	printf("a[0]+1\t=%p,解引用为:%d\n\n", a[0] + 1, *(a[0] + 1));

	printf("a[0][0]\t地址=%p,值为:%d\n", &a[0][0], a[0][0]);
	printf("&a[0][0]+1=%p,解引用为:%d\n\n", &a[0][0] + 1, *(&a[0][0] + 1));

	printf("*a+1\t=%p,解引用为:%d\n", *a + 1, *(*a + 1));
	printf("*(a+1)\t=%p,解引用为:%d\n", *(a + 1), *(*(a + 1)));
	printf("*(*(a+1)+1)地址=%p,值为:%d\n", *(a + 1) + 1, *(*(a + 1) + 1));
	system("pause");
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
int main() {
	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int(*p)[4] = a;
	printf("\t[0]\t[1]\t[2]\t[3]\n");
	for (int i = 0; i < 3; ++i, printf("\n")) {
		printf("a[%d]\t", i);
		for (int j = 0; j < 4; ++j) {
			printf("%d\t", *(*(p + i) + j));//等价printf("%d\t", a[i][j]);
		}
	}

	printf("\n");
	printf("&a\t=%p\n", &a);
	printf("a\t=%p,解引用为:%d\n", a, **a);
	printf("&a[0]\t=%p\n", &a[0]);
	printf("a[0]\t=%p,解引用为:%d\n", a[0], *a[0]);
	printf("&a[0][0]=%p,解引用为:%d\n\n", &a[0][0], a[0][0]);
	system("pause");
	return 0;
}
#endif
#if 1
#include<stdio.h>
#include<stdlib.h>
int main() {
	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int(*p)[4] = a;//p为数组指针
	int* q[3] = { a[0],a[1],a[2] };//int* q[3] = { *(p), *(p + 1), *(p + 2) };二者等价
	for (int i = 0; i < 3; ++i, printf("\n")) {
		for (int j = 0; j < 4; ++j) {
			printf("%d\t", *(*(p + i) + j));//等价printf("%d\t", a[i][j]);
		}
	}
	printf("\n");
	for (int i = 0; i < 3; ++i, printf("\n")) {
		for (int j = 0; j < 4; ++j) {
			printf("%d\t", q[i][j]);
			//等价printf("%d\t", *(*(q + i) + j));虽然 *(*(q + i) + j)与数组指针p的用法一样但含义并不相同
		}
	}
	system("pause");
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
int main() {
	int a[5] = { 1,2,3,4,5 };
	int* q[5] = { &a[0],&a[1] ,&a[2] ,&a[3] ,&a[4] };
	for (int i = 0; i < 5; ++i) {
		printf("%d\t", a[i]);
	}
	printf("\n");
	for (int i = 0; i < 5; ++i) {
		printf("%d\t", **(q + i));//等价于printf("%d\t", *q[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
#endif