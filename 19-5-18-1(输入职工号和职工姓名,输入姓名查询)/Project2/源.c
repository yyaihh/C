#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
struct staff {//创建结构体变量
	int id;//职工号
	char name[1024];//姓名
};
void input(struct staff* p) {//输入职工的姓名和职工号
	struct staff* q = p;
	for (int i = 1; p < q + N; ++i, ++p) {
		printf("请输入第%d个职工的职工号\n", i);
		scanf("%d", &p->id);
		printf("请输入该职工的姓名\n");
		scanf("%s", p->name);//p->name本来就是指针,存放的就是地址,无需取地址

	}
}
void sort(struct staff* p) {//按职工号从大到小排序
	char temp[1024];
	struct staff* q = p;
	for (; p < q + N; ++p) {
		for (struct staff* qq = p + 1; qq < q + N; ++qq) {
			if (p->id > qq->id) {
				p->id = p->id ^ qq->id;//按位异或法
				qq->id = p->id ^ qq->id;
				p->id = p->id ^ qq->id;
				strcpy(temp, p->name);
				strcpy(p->name, qq->name);
				strcpy(qq->name, temp);
			}
		}
	}
}
struct staff* bisearch(char* str, struct staff* p) {
	struct staff* q = p;
	int n;
	for (int i = 1; p < q + N; ++i, ++p) {
		n = strlen(p->name);
		if (n == strlen(str)) {
			for (int j = 0; j < n; ++j) {
				if (str[j] != p->name[j]) {
					break;
				}
				if (j == n - 1) {
					return p;
				}
			}
		}
	}
	return NULL;
}
void main() {
	char str[1024];
	struct staff staff[N];//创建N个结构体变量
	struct staff* p;//创建指向结构体
	p = staff;//指向结构体数组的首元素
	input(p);
	sort(p);
	system("cls");
	for (; p < staff + N; ++p) {
		printf("%d\t%s\n", p->id, p->name);
	}
	p = staff;
	printf("请输入需要查询的员工姓名\n");
	scanf("%s", str);
	struct staff* q = bisearch(str, p);
	if (q != NULL) {
		printf("职工%s的职工号为:%d\n", q->name, q->id);
	}
	else {
		printf("没有名字为%s的职工\n", str);
	}
	system("pause");
}
