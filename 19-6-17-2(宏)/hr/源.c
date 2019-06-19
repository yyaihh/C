
#if 0
#include<stdio.h>
#include<stdlib.h>
#define M1(a,b) a*b
#define M2(a,b) (a)*(b)
#define M3(a,b) ((a)*(b))
#define A1(a,b) a+b
#define A2(a,b) (a)+(b)
#define A3(a,b) ((a)+(b))
int main() {
	int i = 4;
	int j = 5;
	printf("%d\t%d\t%d\n", M1(i, j), M2(i, j), M3(i, j));//结果20,20,20
	printf("%d\n", M1(i + i, j + j));//预期结果80,实际处理为i+i*j+j=4+20+5=29
	printf("%d\n", M2(i + i, j + j));//预期结果80,实际处理为(i+i)*(j+j)*(i+i)*(j+j)=80
	printf("%d\n", M3(i + i, j + j));//预期结果80,实际处理为((i+i)*(j+j)*(i+i)*(j+j))=80
	printf("%d\t%d\t%d\n", A1(i, j), A2(i, j), A3(i, j));//结果9,9,9
	printf("%d\n", A1(i, j)*A1(i, j));//预期结果9*9=81,实际处理为i+j*i+j=29
	printf("%d\n", A2(i, j)*A2(i, j));//预期结果9*9=81,实际处理为(i)+(j)*(i)+(j)=29
	printf("%d\n", A3(i, j)*A3(i, j));//预期结果9*9=81,实际处理为((i)+(j))*((i)+(j))=81
	system("pause");
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
#define 整型 int
#define N 10
#define str "哈哈哈"
#define D1 double*
typedef double* D2;
typedef char 字符型;
int main() {
	整型 num = 5;
	printf("num = %d\n%d\n", num, sizeof(整型));
	printf("N = %d\n", N);
	printf("str :%s\n", str);
	//double* a1, b1;
	D1 a1, b1;
	D2 a2, b2;
	字符型 ch = 'a';
	printf("ch = %c\n", ch);
	printf("%d  %d\n", sizeof(a1), sizeof(b1));
	printf("%d  %d\n", sizeof(a2), sizeof(b2));
	system("pause");
	return  0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
#define M(a,b,c,d) a=c+d;b=c-d
#define PRINT_1(a,b) \
	printf(#a"+"#b"=%d\n",(a)+(b))
#define SUM_PRINT(x,y,z) x##y += z;\
	printf(#x#y"=%d\n",x##y)
int main() {
	int a, b, c, d, ab;
	c = 6;
	d = 2;
	ab = 0;
	M(a, b, c, d);
	printf("%d %d %d %d\n", a, b, c, d);
	PRINT_1(a, b);
	SUM_PRINT(a, b, 5);
	system("pause");
	return  0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
#define MALLOC(num, type)\
(type *)malloc(num * sizeof(type))
int main() {
	int* p;
	p = MALLOC(10, int);//类型作为参数
	for (int i = 0; i < 10; ++i) {
		*(p + i) = i + 1;
	}
	for (int i = 0; i < 10; ++i) {
		printf("%d ", *(p + i) = i + 1);
	}
	printf("\n");
	system("pause");
	return  0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
int mymax(int a, int b) {
	return a > b ? a : b;
}
int main() {
	int x1, y1, z1;
	int x2, y2, z2;
	x1 = 4;
	y1 = 5;
	z1 = MAX(x1++, y1++);
	x2 = 4;
	y2 = 5;
	z2 = mymax(x2++, y2++);
	printf("x1=%d, y1=%d, z1=%d\n", x1, y1, z1);
	printf("x2=%d, y2=%d, z2=%d\n", x2, y2, z2);
	system("pause");
	return  0;
}
#endif
#if 1
#include"x.h"
#include"x.h"
#include<stdio.h>
#include<stdlib.h>
#define M 10
int main() {
	printf("%d\n", M);
	#undef M
	#define M "#undef用于移除一个宏定义"
	printf("%s\n", M);
	system("pause");
	return  0;
}
#endif