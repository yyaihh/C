#include<iostream>

//using namespace std;
//使用这个, 避免与std域中的函数命名重复
namespace N3 {
	namespace N1 {
		int add(int a, int b) {
			std::cout << "1\n";
			return a + b;
		}
	}
	namespace N2 {
		int add(int a, int b) {
			std::cout << "2\n";
			return a + b;
		}
	}
}
//命名空间规则
//命名空间可以解决函数名,全局变量名重复的问题, 包在不同命名空间中的重复函数实际是两个无关的函数
//可以嵌套, 嵌套内部和外部无关
//命名空间可以重名. 会在编译时合并
//命名空间定义了一个新的定义域,解决了C中只能以文件划定作用域的的缺陷(如static只能限制在当前文件))
//使用using可以引用一个名字空间, 使得这个名字空间中的内容对自己可见
//不同命名空间里有相同函数名(函数名与参数列表都一样,内容不一样)的函数时, 如同时对自己可见(using), 
//不使用这个函数, 不会报错, 使用时,不加作用域, 会调用不明确 , 编译报错, 如加上命名空间:: , 则正确

//半缺省参数必须从右往左依次来给出，不能间隔着给
// 缺省参数不能在函数声明和定义中同时出现
//缺省值只能是常量或全局变量

//函数重载
//参数列表不能完全相同, 
//参数列表完全相同, 返回值不同的, 不能算是函数重载
int main() {
	N3::N1::add(1, 2);
	std::cout <<N3::N2::add(2, 2);
	system("pause");
	return 0;
}