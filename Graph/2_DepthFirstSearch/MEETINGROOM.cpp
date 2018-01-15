/*
SAT����
�� ������ �ذ��ϱ� ���ؼ��� �� ȸ�Ǹ��� �� ȸ�Ǹ� ����, ���� �������� �����ؾ� �Ѵ�. �̷��� ���̳�, �����̳��� ������ ���� �� �ؾ� �ϴ� �������� �Ҹ� �� ������ ����(Boolean satisfiability problem, Ȥ�� SAT)�� �𵨸��� �� �ִ�. SAT ������ �Ҹ� �� ������ �� ���¿� ���� ���µ�� ������ ���� �־��� ��, �� ���� ���� ������ �ϴ� ������ ������ �ִ��� ã�� ���̴�.
���� ���, a && (!b || !a) && (c && (!a || !b))��� ���� �ִٰ� ����. �� �Ŀ��� a�� !a�� ���� �� ������ �� ���¿� ���� ���¸� ��Ÿ����. ���� a�� ���� ��� a�� ��, !a�� ������ �ȴ�.
�� ���� ����� ������ �Ϸ���, �켱 a�� ���̾�� ���� ��Ȯ�ϴ�. �̶� (!b || !a)�� ���̷��� b�� �����̾ƾ� �ϴµ�, �׷��� (!a || b)�� ������ �� ���ۿ� ����. ���� �� ���� ������ �ϴ� �Ҹ� �� ���� a, b, c�� ������ ������ �� �� �ִ�. �ݸ� ���� ������ �κ��� (c || (!a || b))���ٸ� c�� ������ �ּ� c�� ������ �ּ� ���� ����� ������ �� �� �־��� ���̴�.
���� �ð��� Ǯ �� �ִ� ��� �������� SAT������ �ٲ㼭 Ǯ �� �ִ�.
*/
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<vector<int>> adj;
vector<int> sccId, discovered, finished;
int sccCounter, vertexCounter;
stack<int> st;
vector<vector<int>> ans;
// �� ���� a�� b�� ���� ��ġ�� �ʴ����� Ȯ���Ѵ�
bool disjoint(const pair<int, int>& p, const pair<int, int>& q)
{
	return p.second <= q.first || q.second <= p.first;
}
// meetings[]�� �� ���� �ϰ� �;��ϴ� ȸ�� �ð��� ����� ��,
// �̸� 2-SAT ������ ��ȯ�� �� �׷����� �����Ѵ�.
// i�� ���� meeting[2 * i] Ȥ�� meeting[2 * i + 1]�� �ϳ� �ð��� ȸ�ǽ��� ��� �Ѵ�.
void makeGraph(const vector<pair<int, int>>& meetings)
{
	int vars = meetings.size();
	// �� �׷����� �� �������� �� ���� ������ ���´�.
	adj.clear(); adj.resize(vars * 2);
	for (int i = 0; i < vars; i += 2)
	{
		// �� ���� i�� ȸ�ǳ� j�� ȸ�� �� �� �ϳ��� �ؾ� �Ѵ�.
		int j = i + 1;
		adj[i * 2 + 1].push_back(j * 2);
		adj[j * 2 + 1].push_back(i * 2);
	}
	for (int i = 0; i < vars; i++)
		for (int j = 0; j < i; j++)
		{
			if (!disjoint(meetings[i], meetings[j]))
			{
				adj[i * 2].push_back(j * 2 + 1);
				adj[j * 2].push_back(i * 2 + 1);
			}
		}
}
int scc(int here)
{
	int ret = discovered[here] = vertexCounter++;
	st.push(here);

	for (size_t i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];

		if (discovered[there] == -1)
			ret = min(ret, scc(there));
		else if (discovered[there] < discovered[here] && finished[there] != 1)
			ret = min(ret, discovered[there]);
	}

	if (ret == discovered[here])
	{
		ans.push_back(vector<int>());
		while (true)
		{
			int t = st.top();
			st.pop();
			sccId[t] = sccCounter;
			ans[sccCounter].push_back(t);
			finished[t] = 1;
			if (t == here)
				break;
		}
		sccCounter++;
	}

	return ret;
}

vector<int> tarjanSCC()
{
	sccId = discovered = finished = vector<int>(adj.size(), -1);
	sccCounter = vertexCounter = 0;

	for (int i = 0; i < adj.size(); i++)
		if (discovered[i] == -1)
			scc(i);
	return sccId;
}
// adj[]�� ���� �׷����� ���� ����Ʈ ǥ���� �־��� ��, 2-SAT ������ ���� ��ȯ�Ѵ�.
vector<int> solve2SAT()
{
	int n = adj.size() / 2; // ������ ��
	// ���� �׷����� �������� ������ ��Һ��� ���´�.
	vector<int> label = tarjanSCC();
	// �� SAT ������ Ǫ�� ���� �Ұ������� Ȯ���Ѵ�. �� ������ ��Ÿ���� �� ������
	// ���� ������ ��ҿ� ���� ���� ��� ���� ����.
	for (int i = 0; i < 2 * n; i += 2)
		if (label[i] == label[i + 1])
			return vector<int>();
	// SAT ������ Ǫ�� ���� �����ϴ�. ���� ��������
	vector<int> value(n, -1);
	// Tarjan �˰��򿡼� SCC��ȣ�� ���� ������ �������� �����ȴ�.
	// SCC ��ȣ�� �������� �� ������ �����ϸ� ���� ���� ������ �ȴ�.
	vector<pair<int, int>> order;
	for (int i = 0; i < 2 * n; i++)
		order.push_back({ -label[i], i });
	sort(order.begin(), order.end());
	// �� ������ ���� �����Ѵ�.
	for (int i = 0; i < 2 * n; i++)
	{
		int vertex = order[i].second;
		int variable = vertex / 2, isTrue = vertex % 2 == 0;
		if (value[variable] != -1)
			continue;
		// not A�� A���� ���� �������� A�� ��
		// A�� not A���� ���� �������� A�� ����
		value[variable] = !isTrue;
	}
	return value;
}
int main (void)
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		vector<pair<int, int>> meetings(N * 2); // 2�� ���̴�.
		for (int i = 0; i < N; i++)
			scanf("%d%d%d%d", &meetings[2 * i].first, &meetings[2 * i].second, &meetings[2 * i + 1].first, &meetings[2 * i + 1].second);
		makeGraph(meetings);
		vector<int> ans = solve2SAT();
		if (ans.empty())
			puts("IMPOSSIBLE");
		else
		{
			puts("POSSIBLE");
			for (size_t i = 0; i < ans.size(); i += 2)
			{
				if (ans[i] == 1 || ans[i + 1] == 0)
					printf("%d %d\n", meetings[i].first, meetings[i].second);
				else
					printf("%d %d\n", meetings[i + 1].first, meetings[i + 1].second);
			}
		}
	}

	return 0;
}
