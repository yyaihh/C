#include<stdio.h>
#include<stdlib.h>
int fun(){
	int i, x, y, z, n = 0;
	for (i = 0; i < 1000; i++){
		x = i % 10;
		y = (i / 10) % 10;
		z = (i / 100);
		if (x + y + z == 15){
			n++;
			printf("%d\t", i);
		}
	}
	return n;
}
void main(){
	printf("\n0��999֮���λ��֮��Ϊ15������%d��\n", fun());
	system("pause");
}