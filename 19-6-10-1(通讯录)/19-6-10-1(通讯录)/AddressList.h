#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int num = 0;
typedef struct AddressList {
	char sex;
	int age;
	char Tel[20];
	char name[50];
	char Add[100];
	struct AddressList* next;
}AL;
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
	��ȡ,
	f = 'Ů',
	m= '��',
};
int Menu();//�˵�
void AddressList();
void input(AL*);
AL* add(AL*);//��
void del(AL*);//ɾ
int alter(AL*); //��
AL** allfind(AL*);//��
AL* find_1(AL*, const char*);//��������
AL* find_2(AL*, const char*);//��������
AL* find_3(AL*, const char*);//���绰������
AL* find_4(AL*, const char*);//����ַ��
void print(AL*);//���
void allprint(AL*); //ȫ�����
int empty(AL*);//���
void swap(AL*, AL*);//����
int sort(AL*);//����
int save(AL*);//����
void finput(AL*, FILE*);//
int read();//��ȡ
int fun();