#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int HPDataType;
void adjustDown(HPDataType* array, int n, int size);//向下调整算法
void HeapPop(HPDataType* array, int size);//删除
void HeapSort(HPDataType* array, int size);//堆排序
void PrintArray(int* src, int size);//打印