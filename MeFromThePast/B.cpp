#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int N; int M; int arr[14][14]; vector<int> color; int err;
void DFS(int rownum)
{
	if (rownum > N)
		return;
	for (int i = 1; arr[rownum][i] != -1; i++)
	{
		//if (arr[rownum][i] == 1) continue;
		if (arr[rownum][i] == 0) (color[rownum] > i) ? color[rownum] = i : color[rownum] = color[rownum];
		if (arr[rownum][i] == 1) color[rownum] = color[i]++;

	}
	if (color[rownum] != 0) 
		DFS(rownum + 1);
	else err = -1;
}
int main(void)
{
	memset(arr, -1, (14 * 14) * sizeof(int));
	scanf("%d", &N); scanf("%d", &M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++)
			scanf("%d", &arr[i][j]);
	color.assign((M + 1), M+1);
	DFS(1);
	if (err != -1)
	{
		for (int i = 1; i <= M; i++)
			printf("%d ", color[i]);
	}
	else printf("%d", err);
	return 0;
}