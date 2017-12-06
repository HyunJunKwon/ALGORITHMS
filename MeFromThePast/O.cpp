#include <cstdio>
int I, J;
int a[100 + 10][100 + 10];
int si, sj;
int sol, cnt;
typedef struct {
	int i, j, v;
}Q_T;
Q_T queue[100 * 100 + 10];
int rd, wr;
int BFS(void) {
	int i, j, v = 0, k, ii, jj;
	static int di[] = { 0,1,0,-1 };
	static int dj[] = { -1,0,1,0 };
	queue[wr].i = si, queue[wr].j = sj, queue[wr++].v = 3;
	a[si][sj] = 0;
	while (rd<wr) {
		ii = queue[rd].i, jj = queue[rd].j, v = queue[rd++].v;
		for (k = 0; k<4; k++) {
			i = ii + di[k], j = jj + dj[k];
			if (i>0 && i <= I && j>0 && j <= J && a[i][j]) {
				queue[wr].i = i, queue[wr].j = j, queue[wr++].v = v + 1;
				a[i][j] = 0;
			}
		}
	}
	return v;
}
int main(void) {
	int i, j;
	scanf("%d %d", &J, &I);
	for (i = 1; i <= I; i++) {
		for (j = 1; j <= J; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	scanf("%d %d", &sj, &si);
	sol = BFS();
	for (i = 1; i <= I; i++) {
		for (j = 1; j <= J; j++) {
			if (a[i][j]) cnt++;
		}
	}
	printf("%d\n%d", sol, cnt);
	return 0;
}
