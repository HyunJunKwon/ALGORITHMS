#include <iostream>
#include <windows.h>
#include <vector>
#include <time.h>

using namespace std;

#define COUNT 30 // The number of heap elements
#define NUM_EXTRACT 5 // How many times you will extract minimum numbers?

vector<int> A(COUNT + 1); // 0부터 시작하는 배열을 1부터 시작하는 배열로 변환해주기 위해 COUNT+1 된 배열 생성

typedef struct // heap구현에 사용될 변수들 구조체로 선언
{
	int size;// heapsize[A]
	int length;// length[A]
}_heap;
_heap heap;

int RIGHT(int i) 
{ 
	return (2 * i) + 1; 
} // 오른쪽 자식노드 인덱스 반환

int LEFT(int i) 
{ 
	return 2 * i; 
} // 왼쪽 자식노드 인덱스 반환

void Min_Heapify(int i)
{
	int L;
	int R;
	int mini;

	L = LEFT(i); // 왼쪽 자식노드 인덱스 l에 저장
	R = RIGHT(i); // 오른쪽 자식노드 인덱스 l에 저장

	if (L <= heap.size && A[L] < A[i]) 
	{ // L이 heapsize[A] 보다 작고 A[L]이 부모노드의 키값보다 작을때
		mini = L; // l을 minimum number로 설정
	}
	else mini = i; // 아니면 i를 그대로 minimum 으로 설정 

	if (R <= heap.size && A[R] < A[mini]) 
	{ // r이 heapsize[A] 보다 작고 A[r]이 부모노드의 키값보다 작을때
		mini = R; // r을 minimum number로 설정
	}
	if (mini != i) 
	{
		int temp = A[i];
		A[i] = A[mini];
		A[mini] = temp; // Exchange A[i] <-> A[mini]
		Min_Heapify(mini); // Call Min_Heapify()
	}
}

void Build_Min_Heap() // Min_Heap 생성
{
	int i;

	heap.size = heap.length;

	for (i = heap.length / 2; i > 0; i--)  // 가장 마지막 노드의 부모노드부터......
	{
		Min_Heapify(i); // Call Min_Heapify
	}
}

int Heap_Extract_Min()
{
	int min;

	if (heap.size < 1) printf("Error! Heap underflow");

	min = A[1]; // Root의 Key값을 min 으로 저장후
	A[1] = A[heap.size]; // 배열내 가장 마지막 값을 Root로 올린다.

	heap.size--; // After extracting min, heapsize minus 1

	Min_Heapify(1); // Property에 맞춰 힙트리 재배열

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
		Min_Heapify(1); // 다시 heapify
	}

}

int main(void)
{
	int i;
	heap.length = COUNT; // array A size 를 heap length로 설정
	srand(GetTickCount()); // Generate random number, 좀 더 중복없이 정확한 난수발생을 위해
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
		heap.length--; // Decrease heaplength, 힙트리 안의 최소 키값을 가진 노드가 하나씩 빠지므로
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