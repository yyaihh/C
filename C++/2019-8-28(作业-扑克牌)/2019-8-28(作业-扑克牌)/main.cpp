#include"class.h"

int main() {
#if 1
	//һ��һ��˳���ȡ
	ALL a;
	//cout << "ϴ�ƺ�\n";
	a.InitPoker();
	//a.allprint();//���ϴ�����
	Player p1, p2, p3;
	a.draw1(a, p1, p2, p3);
	cout << "���1��ȡ����\n";
	p1.print();
	p1.InsertSort();
	cout << "���ƺ�\n";
	p1.print();
	cout << "���2��ȡ����\n";
	p2.print();
	p2.InsertSort();
	cout << "���ƺ�\n";
	p2.print();
	cout << "���3��ȡ����\n";
	p3.print();
	p3.InsertSort();
	cout << "���ƺ�\n";
	p3.print();
#else
	//һ����������������18����
	ALL a;
	a.InitPoker();
	Player p1, p2, p3;
	p1.Draw18(a);
	p2.Draw18(a);
	p3.Draw18(a);
	cout << "���1��ȡ����\n";
	p1.print();
	p1.InsertSort();
	cout << "���ƺ�\n";
	p1.print();
	cout << "���2��ȡ����\n";
	p2.print();
	p2.InsertSort();
	cout << "���ƺ�\n";
	p2.print();
	cout << "���3��ȡ����\n";
	p3.print();
	p3.InsertSort();
	cout << "���ƺ�\n";
	p3.print(); 
#endif
	system("pause");
}