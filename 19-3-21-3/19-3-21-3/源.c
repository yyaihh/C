
#include "stdio.h"
#define N 9
void fun(int a[], int n)
{
	int i, j, max, min, px, pn, t;
	for (i = 0; i < n - 1; i = i + 2)
	{
		max = min = a[i];
		px = pn = i;
		for (j = i + 1; j < n; j++)
		{
			if (max < a[j])

				max = a[j]; px = j;
		}
		if (min > a[j])
		{
			min = a[j]; pn = j;
		}
		if (px != 1)
		{
			t = a[i];
			a[i] = max;
			a[px] = t;
			if (pn == i)
				pn = px;
		}
		if (pn != i + 1)
		{
			t = a[i + 1]; a[i + 1] = min;
			a[pn] = t;
		}
	}
}
void main()
	{
		int b[N] = { 1,4,3,2,9,6,5,8,7 }, i;
		printf("\nthe original data:\n");
		for (i = 0; i < N; i++)
			printf("%4d", b[i]);
		printf("\n");
		fun(b, N);
		printf("\nthe  data after is:\n");
		for (i = 0; i < N; i++)
			printf("%d\t", b[i]);
		printf("\n");
		system("pause");
	}
