
//<*SortFunc.cpp*>
#include "SortTest.h"

// Example 4.6
void BubleSort(float a[], int n) 
{
	float temp;
	for (int i = 1; i < n ;i++)
		for (int j = 0; j < n - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
}

void BubleTest(void)
{
	float b[8] = { 12.3, 5.4, 89.6, 37.2, 22.4, 56.3, 62.1, 49.0 };
	std::cout << "before sorting : " << std::endl;
	for (int i = 0; i < 8; i++)
		std::cout << b[i] << '\t';
	std::cout << '\n';
	BubleSort(b, 8);
	std::cout << "aftering sorting : " << std::endl;
	for (int i = 0; i < 8; i++)
		std::cout << b[i] << '\t';
	std::cout << '\n';
}

//Example 6.37

int cmpInt(void *a, void*b) 
{
	return *(int*)a - *(int*)b;
}


int cmpFloat(void *a, void*b)
{
	return *(float*)a - *(float*)b > 0 ? 1:-1;
}

int cmpChar(void *a, void*b)
{
	return strcmp((char*)a, (char*)b);
}


void Sort(void *v, int n, int size, int(*cmp)(void*, void*))
{
	int i, j, k;
	char *p, *q, t;
	for (int i = 0; i < n - 1; i++) {
		p = (char*)v + i * size;
		for (j = i + 1; j < n; j++) {
			q = (char*)v + j * size;
			if (cmp(p, q) > 0)
				for (k = 0; k < size; k++) {
					t = p[k];
					p[k] = q[k];
					p[k] = t;
				}
		}
	}
}

void SortTest(void)
{
	int vi[] = { 34, 12, 25, 43, 8, 16 };
	float vf[] = { 32.2, 23.1, 67.4, 8.9, 14.8 };
	char vc[][10] = { "NanJing", "BeiJing", "WuHan", "ShenYang" };
	int i;
	Sort(vi, sizeof(vi) / sizeof(int), sizeof(int), cmpInt);
	for (i = 0; i < sizeof(vi) / sizeof(int); i++)
		std::cout << vi[i] << '\t';
	std::cout << '\n';

	Sort(vf, sizeof(vf) / sizeof(float), sizeof(float), cmpFloat);
	for (i = 0; i < sizeof(vf) / sizeof(float); i++)
		std::cout << vf[i] << '\t';
	std::cout << '\n';

	Sort(vc, 4, 10, cmpChar);
	for (i = 0; i < 4; i++)
		std::cout << vc[i] << '\t';
	std::cout << '\n';
}