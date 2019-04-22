#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
struct staff {//�����ṹ�����
	int id;//ְ����
	char name[1024];//����
};
void input(struct staff* p) {//����ְ����������ְ����
	struct staff* q = p;
	for (int i = 1; p < q + N; ++i, ++p) {
		printf("�������%d��ְ����ְ����\n", i);
		scanf("%d", &p->id);
		printf("�������ְ��������\n");
		scanf("%s", p->name);//p->name��������ָ��,��ŵľ��ǵ�ַ,����ȡ��ַ

	}
}
void sort(struct staff* p) {//��ְ���ŴӴ�С����
	char temp[1024];
	struct staff* q = p;
	for (; p < q + N; ++p) {
		for (struct staff* qq = p + 1; qq < q + N; ++qq) {
			if (p->id > qq->id) {
				p->id = p->id ^ qq->id;//��λ���
				qq->id = p->id ^ qq->id;
				p->id = p->id ^ qq->id;
				strcpy(temp, p->name);
				strcpy(p->name, qq->name);
				strcpy(qq->name, temp);
			}
		}
	}
}
struct staff* bisearch(int n, struct staff* p) {//�����Ƿ���ְ����Ϊn��ְ��(���ֲ���)
	int left = 0;
	int right = N - 1;
	int mid;
	struct staff* Mp;
	while (left <= right) {
		mid = (left + right) / 2;
		Mp = p + mid;
		if (n == Mp->id) {
			return Mp;//���򷵻����id����Ӧ��ָ��ṹ�������ָ��Mp
		}
		else if (n > Mp->id) {
			left = mid + 1;
		}
		else if (n < Mp->id) {
			right = mid - 1;
		}
	}
	return NULL;//���򷵻ؿ�ָ��
}
void main() {
	int n;
	struct staff staff[N];//����N���ṹ�����
	struct staff* p;//����ָ��ṹ��
	p = staff;//ָ��ṹ���������Ԫ��
	input(p);
	system("cls");
	sort(p);
	//�öδ�����Լ�������Ƿ�ɹ�
	for (; p < staff + N; ++p) {
		printf("%d\t%s\n", p->id, p->name);
	}
	p = staff;
	//
	printf("��������Ҫ��ѯ��Ա����\n");
	scanf("%d", &n);
	struct staff* q = bisearch(n, p);
	if (q != NULL) {
		printf("ְ����Ϊ%d��ְ������Ϊ:%s\n", q->id, q->name);
	}
	else {
		printf("û��ְ����Ϊ%d��Ա��\n", n);
	}
	system("pause");
}
