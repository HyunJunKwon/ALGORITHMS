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
	int result[50]; // 임시저장을 위한 Temporary 배열
	int i, j, k; // 각 배열의 인덱스들, i:좌, j:우, k:result[]
	int m;

	//초기화
	i = LEFT;
	j = MID + 1;
	k = LEFT;

	while (i <= MID && j <= RIGHT) 
	{ //i가 MID를 넘지않고 j가 RIGHT을 넘지 않는 범위내에서 반복
		if (A[i] < A[j]) 
		{ // A[i]가 작으면 result[k]에 저장
			result[k] = A[i];
			i++;
			k++;
		}
		else 
		{ // 아니라면 A[j]를 저장
			result[k] = A[j];
			j++;
			k++;
		}
	}
	if (i > MID) 
	{ // 좌측 배열이 모두 복사되었다면  
		for (m = j; m <= RIGHT; m++) 
		{ // 우측 배열 나머지를 모두 result에 저장
			result[k] = A[m];
			k++;
		}
	}
	else
	{ // 반대의 경우
		for (m = i; m <= MID; m++)
		{ // 좌측배열 나머지를 모두 result에 저장
			result[k] = A[m];
			k++;
		}
	}
	for (m = LEFT; m <= RIGHT; m++) 
		A[m] = result[m]; // Temporary에서 전체배열로 값 복사
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