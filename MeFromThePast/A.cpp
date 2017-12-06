#include <cstdio>
#include <cstring>
using namespace std;
typedef struct
{
	int row; int col; //int chk;
}QUEUE;
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1}; // 상하좌우
int N; int arr[110][110]; int result; int chk[110][110]; int sum[110][110];
QUEUE Q[100 * 100 + 10];
int WP; int RP;
int BFS()
{
	Q[WP].row = 1; Q[WP++].col = 1; //chk[Q[WP].row][Q[WP++].col] = 1;//Q[WP++].chk = 1; // 초기화.
	while (RP < WP)
	{
		int tempRow; int tempCol; int tempVal; int nextRow; int nextCol;
		tempRow = Q[RP].row; tempCol = Q[RP++].col; //tempVal = Q[RP++].val;
		for (int k = 0; k < 4; k++)
		{
			nextRow = tempRow + di[k]; nextCol = tempCol + dj[k];
			if (chk[nextRow][nextCol] == 1) continue;
			if (nextRow < 1 || nextRow > N || nextCol < 1 || nextCol > N) continue; // 범위확인
			if (sum[tempRow][tempCol] + arr[nextRow][nextCol] < sum[nextRow][nextCol]) sum[nextRow][nextCol] = sum[tempRow][tempCol] + arr[nextRow][nextCol];
			Q[WP].row = nextRow; Q[WP++].col = nextCol;
		}
		chk[tempRow][tempCol] = 1;	
	}
	return sum[N][N];
}
//2147483647
int main(void)
{
	//memset(sum, 10, (110 * 110) * sizeof(int));
	for (int i = 0; i < 110; i++)
		for (int j = 0; j < 110; j++)
			sum[i][j] = 1000;
	sum[1][1] = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			scanf("%d", &arr[i][j]);
	}
	result = BFS();
	printf("%d\n", result);
	return 0;
}