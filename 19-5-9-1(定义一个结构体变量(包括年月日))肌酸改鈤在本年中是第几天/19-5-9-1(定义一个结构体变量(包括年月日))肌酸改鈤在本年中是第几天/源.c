#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct day {
	int year;
	int month;
	int day;
};
typedef struct day day;
int leap_year(int year) {//�ж��Ƿ�Ϊ����
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
		return 1;//�����귵��1
	}
	return 0;//���Ƿ���0
}
int fun(day* p) {
	int count = 0;
	int Month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };//12�¸�������
	Month[1] += leap_year(p->year);//�����һ�������������+1Ϊ29��,����������+0����28��
	for (int i = 0; i < p->month - 1; ++i) {//ѭ����Ӹ��������·�֮ǰ�������·�����֮��
		count += Month[i];
	}
	count += p->day;//���ϻ�������һ�µ�����
	return count;
}
void main() {
	day d;
	day* p = &d;
	printf("���������\n");
	while (1) {
		scanf("%d", &d.year);
		if (d.year >= 0) {
			break;
		}
		printf("��ݱ���Ǹ�,�������������\n");
	}
	printf("�������·�\n");
	while (1) {
		scanf("%d", &d.month);
		if (d.month < 1) {
			printf("�·ݱ������0\n");
			continue;
		}
		if (d.month > 12) {
			printf("�·ݱ���С�ڵ���12\n");
			continue;
		}
		break;
	}
	printf("��������\n");
	while (1) {
		scanf("%d", &d.day);
		if (d.day < 1) {
			printf("���������0������\n");
			continue;
		}
		if (d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7 || d.month == 8 || d.month == 10 || d.month == 12) {
			if (d.day > 31) {
				printf("���������������%d������,����������\n", d.month);
				continue;
			}
			break;
		}
		else if (d.month == 2) {
			if (leap_year(d.year) == 1 && d.day > 29) {
				printf("���������������%d������,����������\n", d.month);
				continue;
			}
			if (leap_year(d.year) == 0 && d.day > 28) {
				printf("���������������%d������,����������\n", d.month);
				continue;
			}
			break;
		}
		else {
			if (d.day > 30) {
				printf("���������������%d������,����������\n", d.month);
				continue;
			}
			break;
		}
	}
	printf("%d��%d��%d���Ǹ���ĵ�%d��\n", d.year, d.month, d.day, fun(p));
	system("pause");
}
