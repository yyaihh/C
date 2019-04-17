#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main() {
	int a, b;
	printf("请输入a，b的值\n");
	scanf("%d %d", &a, &b);
	printf("方法一:(a + b) / 2 = %d\n", (a + b) >> 1);//存在溢出问题
	printf("方法二:(a + b) / 2 = %d\n", ((a - b) >> 1) + b);//(b加上b比a多的部分的一半)(a-b)/2+b=>((a-b)>>1)+b，不存在溢出问题
	printf("方法三:(a + b) / 2 = %d\n", (a & b) + ((a ^ b) >> 1));//与方法二类似，找出a和b中相同的部分（a & b），再加上不同部分的一半（a ^ b）>>1(不存在溢出)
	system("pause");
}