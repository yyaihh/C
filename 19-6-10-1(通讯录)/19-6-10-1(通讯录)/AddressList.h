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
	退出,
	添加,
	删除,
	修改,
	查找,
	显示,
	清空,
	排序,
	保存,
	读取,
	f = '女',
	m= '男',
};
int Menu();//菜单
void AddressList();
void input(AL*);
AL* add(AL*);//增
void del(AL*);//删
int alter(AL*); //改
AL** allfind(AL*);//查
AL* find_1(AL*, const char*);//按姓名找
AL* find_2(AL*, const char*);//按年龄找
AL* find_3(AL*, const char*);//按电话号码找
AL* find_4(AL*, const char*);//按地址找
void print(AL*);//输出
void allprint(AL*); //全部输出
int empty(AL*);//清空
void swap(AL*, AL*);//交换
int sort(AL*);//排序
int save(AL*);//保存
void finput(AL*, FILE*);//
int read();//读取
int fun();