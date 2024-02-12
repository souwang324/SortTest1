

//<*DataStructure.cpp*>
#include "SortTest.h"

void InsertSort(SqList &L)
{
	int i, j;
	int tmp;
	for (i = 1; i <= L.length; ++i)
	{
		j = i;
		tmp = L.r[i].key;
		L.r[0].key = tmp;
		while (L.r[j-1].key >tmp )
		{
			L.r[j] = L.r[j-1];
			j--;
		}
		L.r[j].key = tmp;
	}
} 


void BInsertSort(SqList &L)
{
	int low, high, m;
	for (int i = 2; i <= L.length; ++i)
	{
		L.r[0] = L.r[i];
		low = 1; high = i - 1;
		while (low <= high)
		{
			m = (low + high) / 2;
			if (L.r[0].key < L.r[m].key)high = m - 1;
			else low = m + 1;
		}
		for (int j = i - 1; j >= high + 1; --j)
			L.r[j + 1] = L.r[j];
		L.r[high + 1] = L.r[0];
	}
}

void SelectSort(SqList &L)
{
	int j, k;
	for (int i = 1; i <= L.length; ++i)
	{
		k = i;
		for (j = i + 1; j <= L.length; j++)
			if (L.r[j].key < L.r[k].key)k = j;
		if (k != i)
		{
			L.r[0].key = L.r[i].key;
			L.r[i].key = L.r[k].key;
			L.r[k].key = L.r[0].key;
		}
	}
}

void BubbleSort(SqList &L)
{
	int i, j;
	for (i = 1; i <= L.length; ++i)
	{
		for (j = 1; j < L.length - i + 1; ++j)
		{
			if (L.r[j + 1].key < L.r[j].key)
			{
				L.r[0].key = L.r[j].key;
				L.r[j].key = L.r[j + 1].key;
				L.r[j + 1].key = L.r[0].key;
			}
		}
	}
} 


int Partition(SqList &L, int low, int high)
{
	L.r[0] = L.r[low];
	KeyType pivotkey = L.r[low].key;
	while (low < high)
	{
		while (low < high&&L.r[high].key >= pivotkey)--high;
		L.r[low] = L.r[high];
		while (low < high&&L.r[low].key <= pivotkey)++low;
		L.r[high] = L.r[low];
	}
	L.r[low] = L.r[0];
	return low;
}

void QSort(SqList &L, int low, int high)
{
	if (low < high)
	{
		int pivotloc = Partition(L, low, high);
		QSort(L, low, pivotloc - 1);
		QSort(L, pivotloc + 1, high);
	}
}

void QuickSort(SqList &L)
{
	QSort(L, 1, L.length);
}

void ShellInsert(SqList &L, int dk)
{
	int i, j;
	for (i = dk + 1; i <= L.length; ++i)
	{
		if (L.r[i].key < L.r[i - dk].key) {
			L.r[0] = L.r[i];
			for (j = i - dk; j > 0 && L.r[0].key < L.r[j].key; j -= dk)
				L.r[j + dk] = L.r[j];
			L.r[j + dk] = L.r[0];
		}
	}
}

void ShellSort(SqList &L, int dlta[], int t)
{
	for (int k = 0; k < t; ++k)
		ShellInsert(L, dlta[k]);
}



void HeapAdjust(HeapType &H, int s, int m)
{
	RedType rc = H.r[s]; int j;
	for (j = 2 * s; j <= m; j *= 2)
	{
		if (j < m&&H.r[j].key < H.r[j + 1].key)++j;
		if (!(rc.key < H.r[j].key))break;
		H.r[s] = H.r[j]; s = j;
	}
	H.r[s] = rc;
}
void HeapSort(HeapType &H)
{
	int i;
	RedType temp;
	for (i = H.length / 2; i > 0; --i)
		HeapAdjust(H, i, H.length);
	for (i = H.length; i > 1; --i)
	{
		temp = H.r[1];
		H.r[1] = H.r[i];
		H.r[i] = temp;
		HeapAdjust(H, 1, i - 1);
	}
}

void Merge(RedType SR[], RedType TR[], int i, int m, int n)
{
	int j, k;
	for (j = m + 1, k = i; i <= m && j <= n; ++k)
	{
		if (SR[i].key < SR[j].key)
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
	int t;
	if (i <= m)
	{
		for (t = i; t <= m; t++)
			TR[k + t - i] = SR[t];
	}
	if (j <= n)
	{
		for (t = j; t <= n; t++)
			TR[k + t - j] = SR[t];
	}
}

void MSort(RedType SR[], RedType *TR1, int s, int t)
{
	int m;
	RedType* TR2 = new RedType[MAXSIZE + 1];
	if (s == t)TR1[s] = SR[s];
	else {
		m = (s + t) / 2;
		MSort(SR, TR2, s, m);
		MSort(SR, TR2, m + 1, t);
		Merge(TR2, TR1, s, m, t);
	}
	delete TR2;
}
void MergeSort(SqList &L)
{
	MSort(L.r, L.r, 1, L.length);
}


void RandSqList(SqList &L)
{
	int n = MAXSIZE, max= MAXSIZE, min=1;
	L.length = n;
	for (int i = 1; i <= L.length; ++i)
	{
		L.r[i].key = rand() % (max - min + 1);
		L.r[i].key += min;
	}
} 

void Output(const SqList& L)
{
	for (int i = 1; i <= L.length; i++)
		cout << L.r[i].key << ",";
	cout << "\n";
}

void CompareSqList(const SqList &L1, const SqList &L2, string msg)
{
	bool flag = false;
	for (int i = 1; i <= L1.length; i++) {
		if (L1.r[i].key != L2.r[i].key) {
			flag = true;
			break;
		}
	}

	if (flag) {
		cout << msg << " Failed " << endl;
		Output(L1);
		Output(L2);
	}
	else
	{
		cout << msg << " Passed \n";
	}
}