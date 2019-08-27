#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define N 10
struct student {
	char name[32];
	int age;
	int Class;
	bool sex;
};
void Print(student* src, int size) {
	cout << "姓名" << "\t" << "年龄" << "\t" << "班级" << "\t" << "性别" << endl;
	for (int i = 0; i < size;++i) {
		cout << src[i].name << "\t" << src[i].age << "\t" << src[i].Class << "\t" << src[i].sex << endl;
	}
}
int count(student* src, int size, const char* name) {
	int count = 0;
	for (int i = 0; i < N; ++i) {
		strcmp(name,src[i].name) ? count : ++count;
	}
	return count;
}
int count(student* src, int size, bool n) {
	int count = 0;
	for (int i = 0; i < N; ++i) {
		n == src[i].sex ? ++count : count;
	}
	return count;
}
int count(student* src, int size, int n, int flag = 0) { 
	int count = 0;
	if (flag == 0) {
		for (int i = 0; i < N; ++i) {
			n == src[i].age ? ++count : count;
		}
	}
	else {
		for (int i = 0; i < N; ++i) {
			n == src[i].Class ? ++count : count;
		}
	}
	return count;
}
int main() {
	student src[N];
	char name[32];
	int Class;
	int Age;
	bool Sex;
	for (auto& i : src) {
		cout << "请输入学生的信息\n请输入姓名\n";
		scanf("%s", i.name);
		cout << "请输入年龄\n";
		cin >> i.age;
		cout << "请输入班级\n";
		cin >> i.Class;
		cout << "请输入性别,男生输入1,女生输入0\n";
		cin >> i.sex;
		system("cls");
	}
	system("cls");
	Print(src, N);
	cout << "请输入你需要统计的姓名\n";
	scanf("%s", name);
	cout << "请输入你需要统计的年龄\n";
	cin >> Age;
	cout << "请输入你需要统计的班级\n";
	cin >> Class;
	cout << "请输入你需要统计的性别, 男生1,女生0\n";
	cin >> Sex;
	cout << "张三的名字有" <<count(src, N, name)<< "个" <<endl;
	cout << Class << "班的学生有" << count(src, N, Class, 100) << "个" << endl;
	cout << Age << "岁的有学生有" << count(src, N, Age) << "个" << endl;
	Sex ? cout << "男" : cout << "女";
	cout << "性的有学生有" << count(src, N, Sex) << "个" << endl;
	system("pause");
	return 0;
}