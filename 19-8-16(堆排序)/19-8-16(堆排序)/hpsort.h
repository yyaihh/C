#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int HPDataType;
void adjustDown(HPDataType* array, int n, int size);//���µ����㷨
void HeapPop(HPDataType* array, int size);//ɾ��
void HeapSort(HPDataType* array, int size);//������
void PrintArray(int* src, int size);//��ӡ