#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//��һ���ַ���ת��Ϊ���֣�����ֵ����У��ת���Ƿ�ɹ�
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
	cout << "������һ���ַ���\n";
	scanf("%s", &str);
	if (strtoi(str, num)) {
		cout << "ת���ɹ�\nת��������Ϊ:" << num << endl;
	}
	else {
		cout << "ת��ʧ��!\n";
	}
	system("pause");
	return 0;
}