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
					B.push_back(N[temp++]); // N[i]���� ū ���ڵ�� �ٸ� �迭�� �����.
			}
			cache[i] += (1 + B.size()); // �ϴ� �� ĭ ���������Ƿ� +1
			/*if (B.size() == 0) // ���� N[i]�� ���� ū ���
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