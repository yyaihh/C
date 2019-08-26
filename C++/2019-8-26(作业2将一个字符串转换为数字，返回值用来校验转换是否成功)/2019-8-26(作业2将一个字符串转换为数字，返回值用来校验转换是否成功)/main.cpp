#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//将一个字符串转换为数字，返回值用来校验转换是否成功
bool strtoi(const char* str, int &num) {
	long long tmp = 0;
	double max = pow(2, 31);
	int t;
	for (int k = 0; *str; ++str) { 
		if (k) {
			tmp *= (long)pow(10, k);
			k = 0;
		}
		t = *(str + 1);
		while (t) {
			++k;
			t /= 10;
		}
		tmp += (int)*str;
		if (tmp >= max) {
			return false;
		}
	}
	num = (int)tmp;
	return true;
}
int main() {
	int num = 0;
	char str[10];
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