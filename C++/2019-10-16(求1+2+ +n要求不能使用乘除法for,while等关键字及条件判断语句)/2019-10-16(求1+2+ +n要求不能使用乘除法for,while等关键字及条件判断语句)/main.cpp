#include<iostream>
//#include<cmath>
using namespace std;
//求1+2+3+...+n
//要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
//1.递归
//2.sum=n(n+1)/2
using namespace std;
#if 0
class Solution {
public:
	int Sum_Solution(int n) {
		int _sum = n;
		n > 0 && (_sum += Sum_Solution(n - 1));
		return _sum;
	}
	/*int Sum_Solution(int n) {
		return ((int)pow(n, 2) + n) >> 1;
	}*/
};
#else
class _Solution {
public:
	static int tmp;
	static int sum;
	_Solution() {
		++tmp;
		sum += tmp;
	}
};
int _Solution::sum = 0;
int _Solution::tmp = 0;
class Solution {
public:
	int Sum_Solution(int n) {
		_Solution::tmp = 0;
		_Solution::sum = 0;
		_Solution* p = new _Solution[n];
		return _Solution::sum;
	}
};
#endif
int main() {
	Solution p;
	cout << p.Sum_Solution(3) << endl;
	cout << p.Sum_Solution(6) << endl;
	cout << p.Sum_Solution(10) << endl;
	system("pause");
	return 0;
}