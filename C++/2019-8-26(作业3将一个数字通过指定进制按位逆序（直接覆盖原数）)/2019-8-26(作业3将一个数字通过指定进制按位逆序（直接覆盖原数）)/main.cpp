#include<iostream>
using namespace std;
//将一个数字通过指定进制按位逆序（直接覆盖原数）
void sysReverse(int &num, int n) {
	int tmp = 0;
	while (num) { 
		tmp += num % n;
		tmp *= n;
		num /= n;
	}
	num = tmp;
}
void Print_2(int num) {
	if (num != 1) {
		Print_2(num / 2);
	}
	printf("%d", num % 2);
}
int main() {
	int num1, num2, num3, num4;
	num1 = num2 = num3 = num4 = 25;
	printf("2进制输出%d为:", num1);
	Print_2(num1);
	sysReverse(num1, 2);
	printf("\n2进制下%d按位逆序为:", num1);
	Print_2(num1);
	cout << "\n\n";

	printf("8进制下输出%d为:%o\n", num2, num2);
	sysReverse(num2, 8);
	printf("8进制下按位逆序为:%o\n\n", num2);

	printf("10进制下输出%d为:%d\n", num3, num3);
	sysReverse(num3, 10);
	printf("10进制下按位逆序为:%d\n\n", num3);

	printf("16进制下输出%d为:%X\n", num4, num4);
	sysReverse(num4, 16);
	printf("16进制下按位逆序为:%X\n\n", num4);
	system("pause");
	return 0;
}