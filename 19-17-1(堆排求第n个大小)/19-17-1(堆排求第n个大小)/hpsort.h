#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int HPDataType;
void adjustDown(HPDataType* array, int n, int size);
void HeapPop(HPDataType* array, int size);
int HeapSort(HPDataType* array, int size, int n);
