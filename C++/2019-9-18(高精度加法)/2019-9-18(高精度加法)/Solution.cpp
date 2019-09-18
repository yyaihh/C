#include "Solution.h"
string Solution::Add(const string& num1, const string& num2) {
	if (num1.size() == 0) {
		return num2;
	}
	if (num2.size() == 0) {
		return num1;
	}
	string stmp, res;
	string nummax = num1;
	string nummin = num2;
	int leftmax = 0, leftmin = 0;
	int rightmax = num1.size() - 1;
	int rightmin = num2.size() - 1;
	stmp.resize(rightmax+ 3 + rightmin, '0');
	if (rightmax < rightmin) {
		swap(rightmax, rightmin);
		swap(leftmax, leftmin);
		swap(nummax, nummin);
	}
	int n = 0;
	int m = stmp.size() - 1;
	for (; rightmin >= leftmin; --rightmin, --rightmax, --m) { 
		n = nummax[rightmax] + stmp[m] + nummin[rightmin] - 3 * '0';//相加结果
		stmp[m] = n % 10 + ' 0';
		stmp[m - 1] += n / 10 ;//进位
	}
	for (; rightmax >= leftmax; --rightmax, --m) {
		n = stmp[m] - '0' + nummax[rightmax] - '0';
		stmp[m] = n % 10 + '0';
		stmp[m - 1] += (n / 10);//进位
	}
	int i = 1, j = stmp.size();
	for (; (i < j) && (stmp[i] == '0'); ++i);
	if (i >= j) {
		return "0";
	}

	for (; i < j; ++i) {
		res.push_back(stmp[i]);
	}
	return res;
}