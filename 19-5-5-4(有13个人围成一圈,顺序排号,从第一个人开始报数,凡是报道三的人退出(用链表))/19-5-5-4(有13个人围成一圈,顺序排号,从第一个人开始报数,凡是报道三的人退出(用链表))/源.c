#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N 13
#define M sizeof(struct arr)
struct arr {
	int num;
	struct arr* next;
};
typedef struct arr arr;
arr* creat() {//创建链表
	arr* p = NULL;
	arr* s;
	arr* head = NULL;
	for (int i = 0; i < N; ++i) {
		s = (arr*)malloc(M);
		s->num = i + 1;
		printf("%d\t", s->num);
		if (i == 0) {
			head = s;
			p = head;
		}
		s->next = p->next;
		p->next = s;
		if (i == N - 1) {
			p = head;
			continue;
		}
		p = p->next;
	}
	return head;
}
int fun(arr* head) {//报号为3的人退出(删除)
	arr* p = head;
	arr* temp;
	int k = 1;
	for (p = head; p->next != p; p = p->next) {
		printf("%d\t", p->num);
		if (k == 2) {
			temp = p->next;
			p->next = temp->next;
			free(temp);
			k = 1;
			continue;
		}
		k += 1;
	}
	return p->num;
}
void main() {
	arr* p;
	printf("初始号数为\n");
	p = creat();
	printf("\n边报数边退出:\n");
	printf("\n最后剩下的人为最初的%d号\n", fun(p));
	system("pause");
}
