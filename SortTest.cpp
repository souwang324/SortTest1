
//<*SortTest.cpp*>


#include "SortTest.h"

int main(int argn, char** argv)
{

	 //BubleTest();
	 // SortTest();
	time_t t1, t2;
	SqList L1, L2;
	RandSqList(L1);
	SqList L = L1;
	cout << "before sorting \n";
	Output(L);
	t1 = clock();
	BubbleSort(L);
	t2 = clock();
	cout << "after BubbleSorting \n";
	Output(L);
	L2 = L;
	double BubbleSortTime = double(t2 - t1) / CLOCKS_PER_SEC;
	cout << "BubbleSortTime   : " << BubbleSortTime << endl;

	L = L1;
	t1 = clock();
	InsertSort(L);
	t2 = clock();

	CompareSqList(L2, L, "InsertSort");

	double InsertSortTime = double(t2 - t1) / CLOCKS_PER_SEC;
	cout << "InsertSortTime   : " << InsertSortTime << endl;

	L = L1;
	t1 = clock();
	BInsertSort(L);
	t2 = clock();

	CompareSqList(L2, L, "BInsertSort");

	double BInsertSortTime = double(t2 - t1) / CLOCKS_PER_SEC;
	cout << "BInsertSortTime   : " << BInsertSortTime << endl;

	L = L1;
	t1 = clock();
	SelectSort(L);
	t2 = clock();
	CompareSqList(L2, L, "SelectSort");
	double SelectSortTime = double(t2 - t1) / CLOCKS_PER_SEC;
	cout << "SelectSortTime   : " << SelectSortTime << endl;

	L = L1;
	t1 = clock();
	QuickSort(L);
	t2 = clock();
	CompareSqList(L2, L, "QuickSort");

	double QuickSortTime = double(t2 - t1) / CLOCKS_PER_SEC;
	cout << "QuickSortTime   : " << QuickSortTime << endl;

	//void ShellSort(SqList &L, int dlta[], int t);

	L = L1;
	t1 = clock();
	HeapSort(L);
	t2 = clock();
	CompareSqList(L2, L, "HeapSort");
	double HeapSortTime = double(t2 - t1) / CLOCKS_PER_SEC;
	cout << "HeapSortTime   : " << HeapSortTime << endl;

	L = L1;
	t1 = clock();
	MergeSort(L);
	t2 = clock();
	CompareSqList(L2, L, "MergeSort");
	double MergeSortTime = double(t2 - t1) / CLOCKS_PER_SEC;
	cout << "MergeSortTime   : " << MergeSortTime << endl;

	return 0;
}

