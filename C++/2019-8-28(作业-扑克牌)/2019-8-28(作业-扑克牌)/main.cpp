#include"class.h"

int main() {
#if 1
	//һ��һ��˳���ȡ
	ALL a;
	cout << "ϴ�ƺ�������\n";
	a.InitPoker();
	a.allprint();//���ϴ�����
	Player p[3];
	a.draw1(a, p[0], p[1], p[2]);
	for (int i = 0; i < 3; ++i) { 
		cout << "���" << i + 1 << "��ȡ����\n";
		p[i].print();
	}
	for (int i = 0; i < 3; ++i) {
		p[i].InsertSort();//����
	}
	for (int i = 0; i < 3; ++i) {
		cout << "���ƺ����" << i + 1 << "��ȡ����\n";
		p[i].print();
	}
	
#else
	//һ����������������18����
	ALL a;
	cout << "ϴ�ƺ�������\n";
	a.InitPoker();
	a.allprint();//���ϴ�����
	Player p[3];
	for (int i = 0; i < 3; ++i) {
		p[i].Draw18(a);
	}
	for (int i = 0; i < 3; ++i) {
		cout << "���" << i + 1 << "��ȡ����\n";
		p[i].print();
	}
	for (int i = 0; i < 3; ++i) {
		p[i].InsertSort();//����
	}
	for (int i = 0; i < 3; ++i) {
		cout << "���ƺ����" << i + 1 << "��ȡ����\n";
		p[i].print();
	}
#endif
	system("pause");
}