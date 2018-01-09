#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int T; vector<string> words; vector<vector<int> > adj;
vector<int> visited; vector<int> order;
void makeDAG()
{
	adj = vector<vector<int> >(26, vector<int>(26, 0));
	int numOfWords = words.size();
	for (int j = 1; j < numOfWords; j++)
	{
		int i = j - 1; int len = min(words[i].size(), words[j].size());
		for (int k = 0; k < len; k++)
		{
			if (words[i][k] != words[j][k])
			{
				int a = words[i][k] - 'a'; int b = words[j][k] - 'a';
				adj[a][b] = 1;
				break; // 선행관계가 파악되면 break, 뒤에 볼필요 없다.
				// 문제에서 이미 개별 사전 순으로 input을 주기 때문에, 먼저 나온것이 
				// 사전순으로 앞에 나온 것.
			}
		}
	}
}
// 위상정렬 세트
void dfs(int here)
{
	visited[here] = 1; // dfs는 들어가서 check
	for (int there = 0; there < adj.size(); there++)
	{
		if (!visited[there] && adj[here][there] == 1) dfs(there);
		// 방문한 곳이 아니고, 그 점에서 인접한 곳이 있으면 dfs(there) 실행
	}
	// dfs가 끝나면, order에 방문 점 저장
	order.push_back(here);
}
vector<int> topologicalSort()
{
	int n = adj.size(); // 문제에선 26
	visited = vector<int>(n, 0);
	order.clear();
	for (int here = 0; here < n; here++)
	{
		if (!visited[here]) dfs(here);
	}
	reverse(order.begin(), order.end());
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (adj[order[j]][order[i]]) return vector<int>();
		}
	}
	return order;
}
int main(void)
{
	scanf("%d", &T);
	while (T--)
	{
		int W = 0;
		scanf("%d", &W);
		words.clear();
		for (int i = 0; i < W; i++)
		{
			string str; cin >> str;
			words.push_back(str);
		}
		makeDAG();
		vector<int> ret = topologicalSort();
		if (ret.empty())
			printf("INVALID HYPOTHESIS\n");
		else
		{
			for (int i = 0; i < ret.size(); i++)
				printf("%c", ret[i] + 'a');
			printf("\n");
		}
	}
	return 0;
}
