/*
STL¿« Sorting¿∫ 
*/
#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
int T;
int N;
int K;
int result;
vector<int> arr;
int partition(int L, int R)
{
	int pivot; int i; int j; int t;
	pivot = arr[L];
	i = L; j = R + 1;
	while (1)
	{
		do ++i; while (arr[i] <= pivot && i <= R);
		do --j; while (arr[j] > pivot);
		if (i >= j) break;
		swap(arr[i], arr[j]);
	}
	swap(arr[L], arr[j]);
	return j;
}
void quicksort(int L, int R)
{
	int j;
	if (L < R)
	{
		j = partition(L, R);
		quicksort(L, j - 1);
		quicksort(j + 1, R);
	}
}
int main(void)
{
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		scanf("%d %d", &N, &K);
		arr.assign(N, 0);
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[j]);
		}
		//sort(arr.begin(), arr.end(), greater<int>() );
		quicksort(arr[0], arr[N - 1]);
		for (int l = 0; l < K; l++)
		{
			result = result + arr[l];
		}
		printf("Case #%d\n", i);
		printf("%d\n", result);
		arr.clear();
	}
	return 0;
}