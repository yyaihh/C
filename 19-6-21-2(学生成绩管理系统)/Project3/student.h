#pragma once
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<string>
class stu {
public:
	int id;
	char name[20];
	char sex;
	int age;
	char Tel[20];
	double chinese;
	double math;
	double english;
	double aver;
	stu* next;
};
class Student :private stu {
public:
	void student();
	void Menu();
	stu* Init(stu*);//��ʼ��/����
	stu* add(stu*);//���
	void input(stu*);
	stu* find_1(stu*, const char*);//����
	stu* find_2(stu*, const char*);//����
	stu* find_3(stu*, const char*);//�ɼ�
	stu** allfind(stu*);//����
	void del(stu*);//ɾ��
	void alter(stu*);//�޸�
	void print(stu*);//���
	void allprint(stu*);//ȫ�����
	int empty(stu*);
	void swap(stu*, stu*);//����
	int sort(stu*);//����
	void finput(stu*, FILE*);
	int save(stu*);//����
};
enum {
	�˳�,
	���,
	ɾ��,
	�޸�,
	����,
	��ʾ,
	���,
	����,
	����,
};