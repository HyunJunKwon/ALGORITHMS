#include <iostream>

using namespace std;

void print(int *a, int n)
{
	int i = 0;
	while (i < n) 
	{
		cout << a[i] << ",";
		i++;
	}
}

void swap(int i, int j, int *a) 
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}


void quicksort(int * arr, int left, int right) 
{
	int mid = (left + right) / 2;
	cout << "QS:" << left << "," << right << "\n";

	int L = left;
	int R = right;
	int pivot = arr[mid];

	while (left < R || L < right)
	{
		while (arr[L] < pivot)
			L++;
		while (arr[R] > pivot)
			R--;
		if (L <= R) 
		{
			swap(L, R, arr);
			L++;
			R--;
		}
		else 
		{
			if (left < R)
				quicksort(arr, left, R);
			if (L < right)
				quicksort(arr, L, right);
			return;
		}
	}
}


int main (void) 
{
	int arr[8] = { 110, 5, 10,3 ,22, 100, 1, 23 };
	quicksort(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1);
	print(arr, (sizeof(arr) / sizeof(arr[0])));
	return 0;
}