#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N sizeof(struct arr)
struct arr {
	int num;
	struct arr* next;
};
typedef struct arr arr;
arr* input(int n) {
	arr* p = NULL;
	arr* s;
	arr* head = NULL;
	for (int i = 0; i < n; ++i) {
		s = (arr*)malloc(N);
		if (i == 0) {
			head = s;
			p = head;
		}
		printf("�������%d������ֵ\n", i + 1);
		scanf("%d", &s->num);
		if (i == n - 1) {
			s->next = p->next;
			p->next = s;
			p = head;
			continue;
		}
		s->next = p->next;
		p->next = s;
		p = p->next;
	}
	return head;
}
void print(arr* head) {
	arr* q = head;
	do {
		printf("%d ", q->num);
		q = q->next;
	} while (q != head);
	printf("\n");
}
arr* fun(arr* p, int m) {
	for (int i = 0; i < m; ++i) {
		p = p->next;
	}
	return p;
}
void main() {
	int n, m;
	arr* p;
	printf("����Ҫ�м�����,������һ��������!\n");
	while (1) {
		scanf("%d", &n);
		if (n > 0) {
			break;
		}
		printf("��������Ƿ�,����������!\n");
	}
	printf("����Ҫ������λ,������������(���ܴ���%d)\n", n);
	while (1) {
		scanf("%d", &m);
		if (m > 0 && m < n) {
			break;
		}
		printf("��������Ƿ�,����������!\n");
	}
	p = input(n);
	printf("ת��ǰ\n");
	print(p);
	printf("ת����\n");
	print(fun(p, n - m));
	system("pause");
}