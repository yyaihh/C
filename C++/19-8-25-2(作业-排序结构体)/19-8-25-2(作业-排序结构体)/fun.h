#pragma once
#include<iostream>
using namespace std;
typedef struct node {
	int a;
	int b;
	int c;
	int d;
}node;
int cmp(const node &first, const node &second);
void mysort(node* src, int size, int n = 0);
void InsertSort(int* src, int size);//≤Â≈≈
void BubbleSort(int* src, int size);//√∞≈›
void SelectionSort(int* src, int size);//—°‘Ò
void ShellSort(int* src, int size);//œ£∂˚
void PrintArray(int* src, int size);//¥Ú”°
