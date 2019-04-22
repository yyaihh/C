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
struct staff* bisearch(int n, struct staff* p) {//查找是否有职工号为n的职工(二分查找)
	int left = 0;
	int right = N - 1;
	int mid;
	struct staff* Mp;
	while (left <= right) {
		mid = (left + right) / 2;
		Mp = p + mid;
		if (n == Mp->id) {
			return Mp;//有则返回这个id所对应的指向结构体数组的指针Mp
		}
		else if (n > Mp->id) {
			left = mid + 1;
		}
		else if (n < Mp->id) {
			right = mid - 1;
		}
	}
	return NULL;//无则返回空指针
}
void main() {
	int n;
	struct staff staff[N];//创建N个结构体变量
	struct staff* p;//创建指向结构体
	p = staff;//指向结构体数组的首元素
	input(p);
	system("cls");
	sort(p);
	//该段代码可以检测排序是否成功
	for (; p < staff + N; ++p) {
		printf("%d\t%s\n", p->id, p->name);
	}
	p = staff;
	//
	printf("请输入需要查询的员工号\n");
	scanf("%d", &n);
	struct staff* q = bisearch(n, p);
	if (q != NULL) {
		printf("职工号为%d的职工姓名为:%s\n", q->id, q->name);
	}
	else {
		printf("没有职工号为%d的员工\n", n);
	}
	system("pause");
}
