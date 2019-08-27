#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void InsertSort(int* src, int size);//直接插入排序
void ShellSort(int* src, int size);//希尔排序( 缩小增量排序 ), 多重的插入排序, 利用了插排数组越有序, 插排越快
void MergeSort(int* src, int size);//归并排序接口
void dealMergeSort(int* src, int* tmp, int start, int size);//归并排序
//直接插入稳定
//希尔不稳定
//选择排序稳定
//堆排不稳定
//冒泡稳定
//归并稳定
//快排不稳定
//O(nlog2n)时间复杂度的只有归并稳定
//O(n^2的全稳定)(冒泡,选择)


//快速排序
//1.前后指针发(有两种)   (基准左边找比他大, 右边找比较小)
//2.挖坑法
//3.霍尔法(平均速度最快)
//4.非递归法
//时间复杂度为nlog2(n) 到 n^2
void swapArga(int* a, int* b);//交换
int doublePointerWay1(int* src, int start, int end);//双指针法
int doublePointerWay2(int* src, int start, int end);//双指针法优化1
int digWay(int* src, int start, int end);//双指针法优化2,覆盖不交换(挖坑法)
//时间复杂度为nlog2(n) 到 n^2
//所以要用霍尔法(三数取中法)进行优化
int HoareWay(int* src, int start, int end);//霍尔法
void dealQuickSort(int* src, int start, int end);
void QuickSort(int* src, int size);//快速排序
void QuickSortNoR(int* src, int size);//快速排序的非递归实现