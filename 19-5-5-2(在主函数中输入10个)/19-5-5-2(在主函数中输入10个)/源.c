#include<stdio.h>
#include<stdlib.h>
#define N 11//
void fun(char* str[]) {
	char* temp;
	for (int i = 0; i < 10; ++i) {
		for (int j = i + 1; j < 10; ++j) {
			for (int k = 0; k < N; ++k) {
				if (str[i][k] > str[j][k]) {
					temp = str[i];
					str[i] = str[j];
					str[j] = temp;
					break;
				}
				else if (str[i][k] < str[j][k]) {
					break;
				}
			}
		}
	}
}
void main() {
	char str1[N] = { '\0' };
	char str2[N] = { '\0' };
	char str3[N] = { '\0' };
	char str4[N] = { '\0' };
	char str5[N] = { '\0' };
	char str6[N] = { '\0' };
	char str7[N] = { '\0' };
	char str8[N] = { '\0' };
	char str9[N] = { '\0' };
	char str10[N] = { '\0' };
	//定义指针数组str, 由10个指向char型数据的指针元素组成, 这10个指针元素分别是指向十个字符数组的指针
	char* str[10] = { str1,str2,str3,str4,str5,str6,str7,str8,str9,str10 };
	for (int i = 0; i < 10; ++i) {
		printf("请输入第%d个字符串\n", i + 1);
		fgets(str[i], N, stdin);
	}
	system("cls");
	//消除用fgets函数接受字符串后字符串末尾的换行符'\n'
	for (int i = 0; i < 10; ++i) {
		for (char* p = str[i]; *p; ++p) {
			if (*p == '\n') {
				*p = '\0';
				break;
			}
		}
	}
	printf("排序前:\n");
	for (int i = 0; i < 10; ++i) {
		printf("%s\n\n", str[i]);
	}
	fun(str);
	printf("排序后:\n");
	for (int i = 0; i < 10; ++i) {
		printf("%s\n\n", str[i]);
	}
	system("pause");
}
