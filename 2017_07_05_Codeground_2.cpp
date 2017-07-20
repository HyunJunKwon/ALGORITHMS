/*
여러가지 test case 를 통한 규칙 찾기인가...?
*/
//#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int T; 
int N;
vector<int> cur;
vector<int> score;
int counts;
int base;
int main(void)
{
	scanf("%d", &T);
	//cin >> T;
	for (register int i = 1; i <= T; i++)
	{
		//cin >> N;
		scanf("%d", &N);
		counts = 1;
		cur.clear();
		score.clear();
		cur.assign(N, 0);
		score.assign(N, 0);
		for (register int j = 0; j < N; j++)
		{
			scanf("%d", &cur[j]);
			//cin >> cur[j];
			score[j] = j + 1;
		}
		// 1
		sort(cur.begin(), cur.end(), greater<int>());
		for (register int k = 0; k < N; k++)
		{
			int temp = cur[k] + score[k];
			if (temp > base)
			{
				base = temp;
			} // 기저
		}
		// 2
		for (register int l = 1; l < N; l++)
		{
			for (register int m = (N - 1); m >= 0; m--)
			{
				if (cur[l] + score[m] >= base)
				{
					counts++;
					break;
				}
				else
					break;
			}
		}
		printf("Case #%d\n", i);
		printf("%d\n", counts);
	}
	return 0;
}