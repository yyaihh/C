#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int leap_year(int year) {//�ж��Ƿ�Ϊ����
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
		return 1;//�����귵��1
	}
	return 0;//���Ƿ���0
}
int fun(int year, int month, int day) {
	int count = 0;
	int Month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };//12�¸�������
	Month[1] += leap_year(year);//�����һ�������������+1Ϊ29��,����������+0����28��
	for (int i = 0; i < month - 1; ++i) {//ѭ����Ӹ��������·�֮ǰ�������·�����֮��
		count += Month[i];
	}
	count += day;//���ϻ�������һ�µ�����
	return count;
}
void main() {
	int year, month, day;
	printf("���������\n");
	while (1) {
		scanf("%d", &year);
		if (year >= 0) {
			break;
		}
		printf("��ݱ���Ǹ�,�������������\n");
	}
	printf("�������·�\n");
	while (1) {
		scanf("%d", &month);
		if (month < 1){
			printf("�·ݱ������0\n");
			continue;
		}
		if(month>12) {
		printf("�·ݱ���С�ڵ���12\n");
		continue;
		}
		break;
	}
	printf("��������\n");
	while (1) {
		scanf("%d", &day);
		if (day < 1) {
			printf("���������0������\n");
			continue;
		}
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day > 31) {
				printf("���������������%d������,����������\n", month);
				continue;
			}
			break;
		}
		else if (month == 2) {
			if (leap_year(year) == 1 && day > 29) {
				printf("���������������%d������,����������\n", month);
				continue;
			}
			if (leap_year(year) == 0 && day > 28) {
				printf("���������������%d������,����������\n", month);
				continue;
			}
			break;
		}
		else {
			if (day > 30) {
				printf("���������������%d������,����������\n", month);
				continue;
			}
			break;
		}
	}
	printf("%d��%d��%d���Ǹ���ĵ�%d��\n", year, month, day, fun(year, month, day));
	system("pause");
}