
//<*SortTest.h*>
#ifndef DFF_SORT_TEST_HEADER_ON
#define DFF_SORT_TEST_HEADER_ON
#pragma once

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#define MAXSIZE 20

using namespace std;

typedef int KeyType;
typedef int InfoType;

typedef struct {
	KeyType key;
	InfoType otherinfo;
}RedType;

typedef struct {
	RedType r[MAXSIZE + 1];
	int length;
}SqList;

typedef SqList HeapType;

void InsertSort(SqList &L);
void BInsertSort(SqList &L);
void SelectSort(SqList &L);
void BubbleSort(SqList &L);
void QuickSort(SqList &L);
void ShellSort(SqList &L, int dlta[], int t);
void HeapSort(HeapType &H);
void MergeSort(SqList &L);
void CompareSqList(const SqList &L1, const SqList &L2, string msg);

void RandSqList(SqList &L);
void Output(const SqList& L);

void BubleTest(void);
void SortTest(void);


#endif