#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
typedef struct s1 {//12
	char a;//0,1+3
	//char a1;char a2;char a3;
	int b; //4,4+0
	char c;//8,1+3
	//char c1;char c2;char c3;
}s1;
typedef struct s2 {//8
	char a;//0,1
	char b;//1,1+2
	int c;//4,4
}s2;
typedef struct s3 {//24
	s2 a;//0,8
	int b;//8,4+4
	//int b1;
	double c;//16,8+0
}s3;
typedef struct s4 {//16
	s2 a;//0,8
	int b;//8,4+0
	int c;//12,4+0
	//c相当于b1
}s4;
typedef struct s5 {//24
	s2 a;//0,8+0
	double b;//8,8+0
	char c;//16,1+7
	//char c1;char c2;char c3;char c4;char c5;char c6;char c7;
}s5;
typedef struct s6 {//16
	char a;//0,1+3
	int b;//4,4+0
	s2 c;//8,8+0
}s6;
typedef struct s7 {//16
	char a;//0,1+3
	//char a1; char a2; char a3; char a4; char a5; char a6; char a7;
	//s2 b;//4,4+8//自己是8字节,但是别人在对齐时为4,因为它自身对齐是按照4字节对齐的
	double b;
	int c;//12,4+0
	//int c1;
}s7;
typedef struct s8 {//16
	int a;//0,4+0
	//int c;//12,4+0
	char b[4];//4,4+4
	double c;//8,8+8
}s8;
int main() {
	printf("S1\n%d\n", sizeof(s1));
	printf("%d\n", offsetof(s1, a));
	printf("%d\n", offsetof(s1, b));
	printf("%d\n", offsetof(s1, c));
	printf("\nS2\n");
	printf("%d\n", sizeof(s2));
	printf("%d\n", offsetof(s2, a));
	printf("%d\n", offsetof(s2, b));
	printf("%d\n", offsetof(s2, c));
	printf("\nS3\n");
	printf("%d\n", sizeof(s3));
	printf("%d\n", offsetof(s3, a));
	printf("%d\n", offsetof(s3, b));
	printf("%d\n", offsetof(s3, c));
	printf("\nS4\n");
	printf("%d\n", sizeof(s4));
	printf("%d\n", offsetof(s4, a));
	printf("%d\n", offsetof(s4, b));
	printf("%d\n", offsetof(s4, c));
	printf("\nS5\n");
	printf("%d\n", sizeof(s5));
	printf("%d\n", offsetof(s5, a));
	printf("%d\n", offsetof(s5, b));
	printf("%d\n", offsetof(s5, c));
	printf("\nS6\n");
	printf("%d\n", sizeof(s6));
	printf("%d\n", offsetof(s6, a));
	printf("%d\n", offsetof(s6, b));
	printf("%d\n", offsetof(s6, c));
	printf("\nS7\n");
	printf("%d\n", sizeof(s7));
	printf("%d\n", offsetof(s7, a));
	printf("%d\n", offsetof(s7, b));
	printf("%d\n", offsetof(s7, c));
	printf("\nS8\n");
	printf("%d\n", sizeof(s8));
	printf("%d\n", offsetof(s8, a));
	printf("%d\n", offsetof(s8, b));
	printf("%d\n", offsetof(s8, c));
	system("pause");
	return 0;
}