#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct arr {
	int num;
	struct arr* next;
};
typedef struct arr arr;
arr* creat(int n) {
	arr* s;
	arr* p;
	arr* head = (arr*)malloc(sizeof(arr));//ͷ���
	p = head;
	for (int i = 0; i < n; ++i) {
		s = (arr*)malloc(sizeof(arr));
		s->num = i + 1;
		s->next = p->next;
		p->next = s;
		p = p->next;
		if (i == n - 1) {
			p->next = NULL;
		}
	}
	return head;
}
void print(arr* head) {
	for (arr* p = head->next; p != NULL; p = p->next) {
		printf("%d\t", p->num);
	}
	printf("\n");
}
arr* del(arr* head, int m) {
	arr* p = head;
	arr* temp;
	for (int i = 0; i < m - 1; ++i) {
		p = p->next;
	}
	temp = p->next;
	p->next = temp->next;
	free(temp);
	return head;
}
void main() {
	int n ,m;
	printf("����������ĳ���\n");
	scanf("%d", &n);
	arr* head;
	head = creat(n);
	printf("���δɾ��ָ���ڵ�ǰ����\n");
	print(head);
	printf("Ҫɾ���ڼ����ڵ�,������\n");
	scanf("%d", &m);
	for (; m < 1 || m>n; printf("������������,����������\n"), scanf("%d", &m));
	head = del(head, m);
	printf("ɾ��ָ����������Ϊ\n");
	print(head);
	system("pause");
}