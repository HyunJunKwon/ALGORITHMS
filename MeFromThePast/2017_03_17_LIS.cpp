#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int C;
int N[500];
//int cache[500];
vector<int> cache(500, 0);
vector<int> B;
int len;
int dp(int start)
{
	for (int i = start; i < len; i++) // start = 0
	{
		if (cache[i] != 0)
		{
			return cache[i];
		}
		else
		{
			int temp = i + 1;
			B.clear();
			while (temp < len)
			{
				if (N[i] < N[temp])
					B.push_back(N[temp++]); // N[i]보다 큰 숫자들로 다른 배열을 만든다.
			}
			cache[i] += (1 + B.size()); // 일단 한 칸 움직였으므로 +1
			/*if (B.size() == 0) // 현재 N[i]가 가장 큰 경우
				return cache[i];*/
			int ret = dp(++i);
			return cache[i] = max(cache[i], ret);
		}
	}
}
int main(void)
{
	scanf("%d", &C);
	while (C--)
	{
		//memset(cache, 0, sizeof(cache));
		scanf("%d", &len);
		for (int i = 0; i < len; i++)
		{
			scanf("%d", &N[i]);
		}
		dp(0);

		printf("%d\n", max_element(cache.begin(), cache.back()));
	
	}

	return 0;
}