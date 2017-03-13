#include <iostream>
#include <cstdlib>

using namespace std;

void insertion_sort(int arr[], int length)
{
	int i, j, temp;
	for (i = 1; i < length; i++) // n
	{
		j = i; // n - 1
		while (j > 0 && arr[j - 1] > arr[j]) // sigma j=2 to n (t(j))
		{
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp; // sigma j=2 to n (t(j) - 1)
			j--; // sigma j=2 to n (t(j) - 1)
		}
	}
}
