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
	stu* Init(stu*);//初始化/读入
	stu* add(stu*);//添加
	void input(stu*);
	stu* find_1(stu*, const char*);//名字
	stu* find_2(stu*, const char*);//年龄
	stu* find_3(stu*, const char*);//成绩
	stu** allfind(stu*);//查找
	void del(stu*);//删除
	void alter(stu*);//修改
	void print(stu*);//输出
	void allprint(stu*);//全部输出
	int empty(stu*);
	void swap(stu*, stu*);//交换
	int sort(stu*);//排序
	void finput(stu*, FILE*);
	int save(stu*);//保存
};
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
};