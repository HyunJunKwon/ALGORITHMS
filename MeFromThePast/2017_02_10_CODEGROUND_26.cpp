/*
3
100 50 0
Case #1
934849953
100 10 0
Case #2
538396636
100 20 0
Case #3
276891342
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int M = 1000000009;
int N, K, L;
vector<int> MINE;
vector<vector<long long> > DATA;
vector<long long> ANS;

long long solve() {
	for (int bridgeNo = 1; bridgeNo <= N; bridgeNo++) {
		//long long sum = 0;
		if (MINE[bridgeNo]) continue;
		for (int step = 1; step <= K; step++) {
			int prevIdx = bridgeNo - step; // ���翡�� k���� �� ���� �����´�
			if (prevIdx == 0) {
				ANS[bridgeNo]++;
				ANS[bridgeNo] %= M;
				//sum += 1 % M;
				DATA[bridgeNo][step] = 1;
				break;
			}
			else {
				DATA[bridgeNo][step] = ANS[prevIdx] - DATA[prevIdx][step] % M;
				ANS[bridgeNo] += ANS[prevIdx] - DATA[prevIdx][step] % M;
			}
		}
	}
	return ANS[N];
}

int main(int argc, char** argv) {
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		scanf("%d %d %d", &N, &K, &L);

		DATA.clear();
		DATA.assign(N + 1, vector<long long>(K + 1, 0));
		ANS.clear();
		ANS.assign(N + 1, 0);
		MINE.clear();
		MINE.assign(N + 1, 0);

		if (L > 0) {
			for (int i = 0; i<L; i++) {
				int mineIndex;
				scanf("%d", &mineIndex);
				MINE[mineIndex] = 1;
			}
		}

		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		cout << solve() << endl;

	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}