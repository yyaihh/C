#include<iostream>
//#include<cmath>
using namespace std;
//求1+2+3+...+n
//要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
//1.递归
//2.sum=n(n+1)/2
using namespace std;
class Solution {
	int sum;
public:
	int Sum_Solution(int n) {
		int _sum = n;
		n > 0 && (_sum += Sum_Solution(n - 1));
		return _sum;
	}
	Solution():sum(0) {

	}
	/*int Sum_Solution(int n) {
		n > 0 && Sum_Solution(n - 1);
		sum += n;
		return sum;
	}*/
	/*int Sum_Solution(int n) {
		return ((int)pow(n, 2) + n) >> 1;
	}*/
};
int main() {
	Solution p;
	cout << p.Sum_Solution(3) << endl;
	cout << p.Sum_Solution(6) << endl;
	cout << p.Sum_Solution(10) << endl;
	system("pause");
	return 0;
}