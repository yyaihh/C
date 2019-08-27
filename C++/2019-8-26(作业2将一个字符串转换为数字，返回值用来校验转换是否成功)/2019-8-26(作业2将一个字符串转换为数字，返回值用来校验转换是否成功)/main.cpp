#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//将一个字符串转换为数字，返回值用来校验转换是否成功
bool strtoi(const char* str, int &num) {
	if (!str) {
		return false;
	}
	int flag = 1;//正负标签
	if (*str == '-') {
		flag = -1;
		++str;
	}
	if (*str > '9' || *str < '0') {
		return false;
	}
	long long tmp = 0;
	double max = pow(2, 31) - 1;
	double min = -pow(2, 31);
	for (; *str <= '9' && *str >= '0'&& *str; ++str) { 
		tmp = (int)*str - 48 + tmp * 10;
	}
	tmp = flag * tmp;
	if (tmp < min) {
		return false;
	}
	if (tmp > max) {
		return false;
	}
	num = (int)tmp;
	return true;
}
int main() {
	int num = 0;
	char str[20];
	cout << "请输入一个字符串\n";
	scanf("%s", &str);
	if (strtoi(str, num)) {
		cout << "转换成功\n转化的数字为:" << num << endl;
	}
	else {
		cout << "转换失败!\n";
	}
	system("pause");
	return 0;
}