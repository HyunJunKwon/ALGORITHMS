#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int T;
int test_case;
int n, m, arr[550], dp[550][550], cost[550][550], prefix[550], suffix[550];
void read() {
	for (int i = 1; i <= n; i++)scanf("%d", &arr[i]);
	prefix[0] = 0; suffix[n + 1] = 0;
	memset(cost, 0, sizeof(cost));
	sort(arr + 1, arr + n + 1);
}
int main(int argc, char** argv) {
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		scanf("%d %d", &n, &m);
		read();

		for (int i = 1; i <= n; i++)prefix[i] = prefix[i - 1] + arr[i]; //prefix->앞에서부터 합 prefix sum
		for (int i = n; i >= 1; i--)suffix[i] = suffix[i + 1] + arr[i]; //suffix->뒤에서부터 합 suffix sum

		for (int i = 1; i <= n; i++) {
			cost[i][i] = 0;
			for (int j = i + 1; j <= n; j++) {
				//cost[i][j]-> i~j구간에 쓰레기통을 하나 놓을때 best값
				int mid = (i + j) >> 1; //i~j구간에서 무조건 가운데를 놓는게 이득
				int L = prefix[mid] - prefix[i - 1]; int lCnt = (mid - i + 1);
				int R = suffix[mid + 1] - suffix[j + 1]; int rCnt = (j - mid);
				cost[i][j] = arr[mid] * lCnt - L + R - (arr[mid] * rCnt);
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= min(i, m); j++) {
				dp[i][j] = 1e9;
				if (j == 1) {
					dp[i][j] = cost[1][i];
					continue;
				}
				for (int k = 1; k<i; k++) {
					dp[i][j] = min(dp[i][j], dp[k][j - 1] + cost[k + 1][i]);
				}
			}
		}


		printf("Case #%d\n", test_case);
		printf("%d\n", dp[n][m]);
	}

	return 0;
}