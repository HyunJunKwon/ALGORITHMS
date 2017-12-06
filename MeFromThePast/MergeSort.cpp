#include <iostream>
#include <cstdlib>

using namespace std;
/*
MERGESORT(A, p, r)
if p < r
then q <- (p + r) / 2
	MERGESORT(A, p, q)
	MERGESORT(A, q + 1, r)
	MERGE(A, p, q, r)
*/
int A[50];
void merge(int LEFT, int MID, int RIGHT)
{
	int result[50]; // �ӽ������� ���� Temporary �迭
	int i, j, k; // �� �迭�� �ε�����, i:��, j:��, k:result[]
	int m;

	//�ʱ�ȭ
	i = LEFT;
	j = MID + 1;
	k = LEFT;

	while (i <= MID && j <= RIGHT) 
	{ //i�� MID�� �����ʰ� j�� RIGHT�� ���� �ʴ� ���������� �ݺ�
		if (A[i] < A[j]) 
		{ // A[i]�� ������ result[k]�� ����
			result[k] = A[i];
			i++;
			k++;
		}
		else 
		{ // �ƴ϶�� A[j]�� ����
			result[k] = A[j];
			j++;
			k++;
		}
	}
	if (i > MID) 
	{ // ���� �迭�� ��� ����Ǿ��ٸ�  
		for (m = j; m <= RIGHT; m++) 
		{ // ���� �迭 �������� ��� result�� ����
			result[k] = A[m];
			k++;
		}
	}
	else
	{ // �ݴ��� ���
		for (m = i; m <= MID; m++)
		{ // �����迭 �������� ��� result�� ����
			result[k] = A[m];
			k++;
		}
	}
	for (m = LEFT; m <= RIGHT; m++) 
		A[m] = result[m]; // Temporary���� ��ü�迭�� �� ����
}
void merge_sort(int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		merge_sort(low, mid);
		merge_sort(mid + 1, high);
		merge(low, mid, high);
	}
}
int main(void)
{

	return 0;
}