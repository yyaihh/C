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
	printf("\n0到999之间各位数之和为15的数有%d个\n", fun());
	system("pause");
}