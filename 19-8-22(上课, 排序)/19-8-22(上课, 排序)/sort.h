#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void InsertSort(int* src, int size);//ֱ�Ӳ�������
void ShellSort(int* src, int size);//ϣ������( ��С�������� ), ���صĲ�������, �����˲�������Խ����, ����Խ��
void MergeSort(int* src, int size);//�鲢����ӿ�
void dealMergeSort(int* src, int* tmp, int start, int size);//�鲢����
//ֱ�Ӳ����ȶ�
//ϣ�����ȶ�
//ѡ�������ȶ�
//���Ų��ȶ�
//ð���ȶ�
//�鲢�ȶ�
//���Ų��ȶ�
//O(nlog2n)ʱ�临�Ӷȵ�ֻ�й鲢�ȶ�
//O(n^2��ȫ�ȶ�)(ð��,ѡ��)


//��������
//1.ǰ��ָ�뷢(������)   (��׼����ұ�����, �ұ��ұȽ�С)
//2.�ڿӷ�
//3.������(ƽ���ٶ����)
//4.�ǵݹ鷨
//ʱ�临�Ӷ�Ϊnlog2(n) �� n^2
void swapArga(int* a, int* b);//����
int doublePointerWay1(int* src, int start, int end);//˫ָ�뷨
int doublePointerWay2(int* src, int start, int end);//˫ָ�뷨�Ż�1
int digWay(int* src, int start, int end);//˫ָ�뷨�Ż�2,���ǲ�����(�ڿӷ�)
//ʱ�临�Ӷ�Ϊnlog2(n) �� n^2
//����Ҫ�û�����(����ȡ�з�)�����Ż�
int HoareWay(int* src, int start, int end);//������
void dealQuickSort(int* src, int start, int end);
void QuickSort(int* src, int size);//��������
void QuickSortNoR(int* src, int size);//��������ķǵݹ�ʵ��