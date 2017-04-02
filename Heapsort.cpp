#include <iostream>
#include <windows.h>
#include <vector>
#include <time.h>

using namespace std;

#define COUNT 30 // The number of heap elements
#define NUM_EXTRACT 5 // How many times you will extract minimum numbers?

vector<int> A(COUNT + 1); // 0���� �����ϴ� �迭�� 1���� �����ϴ� �迭�� ��ȯ���ֱ� ���� COUNT+1 �� �迭 ����

typedef struct // heap������ ���� ������ ����ü�� ����
{
	int size;// heapsize[A]
	int length;// length[A]
}_heap;
_heap heap;

int RIGHT(int i) 
{ 
	return (2 * i) + 1; 
} // ������ �ڽĳ�� �ε��� ��ȯ

int LEFT(int i) 
{ 
	return 2 * i; 
} // ���� �ڽĳ�� �ε��� ��ȯ

void Min_Heapify(int i)
{
	int L;
	int R;
	int mini;

	L = LEFT(i); // ���� �ڽĳ�� �ε��� l�� ����
	R = RIGHT(i); // ������ �ڽĳ�� �ε��� l�� ����

	if (L <= heap.size && A[L] < A[i]) 
	{ // L�� heapsize[A] ���� �۰� A[L]�� �θ����� Ű������ ������
		mini = L; // l�� minimum number�� ����
	}
	else mini = i; // �ƴϸ� i�� �״�� minimum ���� ���� 

	if (R <= heap.size && A[R] < A[mini]) 
	{ // r�� heapsize[A] ���� �۰� A[r]�� �θ����� Ű������ ������
		mini = R; // r�� minimum number�� ����
	}
	if (mini != i) 
	{
		int temp = A[i];
		A[i] = A[mini];
		A[mini] = temp; // Exchange A[i] <-> A[mini]
		Min_Heapify(mini); // Call Min_Heapify()
	}
}

void Build_Min_Heap() // Min_Heap ����
{
	int i;

	heap.size = heap.length;

	for (i = heap.length / 2; i > 0; i--)  // ���� ������ ����� �θ������......
	{
		Min_Heapify(i); // Call Min_Heapify
	}
}

int Heap_Extract_Min()
{
	int min;

	if (heap.size < 1) printf("Error! Heap underflow");

	min = A[1]; // Root�� Key���� min ���� ������
	A[1] = A[heap.size]; // �迭�� ���� ������ ���� Root�� �ø���.

	heap.size--; // After extracting min, heapsize minus 1

	Min_Heapify(1); // Property�� ���� ��Ʈ�� ��迭

	return min;
}

void Print_Heap() // Display a heap tree
{
	cout << heap.length << " elements\n";

	for (int i = 1; i <= heap.length; i++) 
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

void HeapSort() // Implementing heapsort
{
	int i;

	for (i = heap.length; i >= 2; i--) 
	{
		int temp = A[1];
		A[1] = A[heap.size];
		A[heap.size] = temp; // exchange A[1] <-> A[heapsize]

		heap.size--; // heapsize = heapsize - 1
		Min_Heapify(1); // �ٽ� heapify
	}

}

int main(void)
{
	int i;
	heap.length = COUNT; // array A size �� heap length�� ����
	srand(GetTickCount()); // Generate random number, �� �� �ߺ����� ��Ȯ�� �����߻��� ����
						   //srand((unsigned)time(NULL));

	for (i = 1; i <= heap.length; i++) 
	{
		A[i] = rand() % 1000; // Make data list within array A[]
	}

	cout << "Before Sorting : \n"; // Display elements of heap before sorting
	Print_Heap();

	Build_Min_Heap(); // Call Build_Min_Heap()

	cout << "\nStarting to extract a minimum element : \n";


	for (i = 0; i < NUM_EXTRACT; i++) {
		heap.length--; // Decrease heaplength, ��Ʈ�� ���� �ּ� Ű���� ���� ��尡 �ϳ��� �����Ƿ�
		cout << "\tThe value " << Heap_Extract_Min() << " is removed.\n";
	}

	cout << "Total " << NUM_EXTRACT << " elements are removed!\n"; // Display how many minimum nodes are removed

	cout << "\nThe elements of a heap tree after Heap_Extract_Min : \n"; // Display elements of heap after extracting minimum values 5times
	Print_Heap(); // Display Heap

	HeapSort(); // Call HeapSort()

	cout << "\nAfter Sorting: \n";// Display elements of heap after sorting
	Print_Heap();

	cout << "Complete!!\n";
	return 0;
}