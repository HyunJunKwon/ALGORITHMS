/*
SAT문제
이 문제를 해결하기 위해서는 각 회의마다 이 회의를 할지, 하지 않을지를 결정해야 한다. 이렇게 참이냐, 거짓이냐의 결정을 여러 번 해야 하는 문제들은 불린 값 만족성 문제(Boolean satisfiability problem, 혹은 SAT)로 모델링할 수 있다. SAT 문제는 불린 값 변수의 참 형태와 거짓 형태들로 구성된 식이 주어질 때, 이 식의 값을 참으로 하는 변수의 조합이 있는지 찾는 것이다.
예를 들어, a && (!b || !a) && (c && (!a || !b))라는 식이 있다고 하자. 이 식에서 a와 !a는 각각 한 변수의 참 형태와 거짓 형태를 나타낸다. 변수 a가 참일 경우 a는 참, !a는 거짓이 된다.
이 식의 결과를 참으로 하려면, 우선 a가 참이어야 함은 명확하다. 이때 (!b || !a)가 참이려면 b가 거짓이아야 하는데, 그러면 (!a || b)는 거짓이 될 수밖에 없다. 따라서 이 식을 참으로 하는 불린 값 변수 a, b, c의 조합은 없음을 알 수 있다. 반면 식의 마지막 부분이 (c || (!a || b))였다면 c를 참으로 둬서 c를 참으로 둬서 식의 결과를 참으로 할 수 있었을 것이다.
다항 시간에 풀 수 있는 모든 문제들은 SAT문제로 바꿔서 풀 수 있다.
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
// 두 구간 a와 b가 서로 겹치지 않는지를 확인한다
bool disjoint(const pair<int, int>& p, const pair<int, int>& q)
{
	return p.second <= q.first || q.second <= p.first;
}
// meetings[]가 각 팀이 하고 싶어하는 회의 시간의 목록일 때,
// 이를 2-SAT 문제로 변환한 뒤 그래프를 생성한다.
// i번 팀은 meeting[2 * i] 혹은 meeting[2 * i + 1]중 하나 시간에 회의실을 써야 한다.
void makeGraph(const vector<pair<int, int>>& meetings)
{
	int vars = meetings.size();
	// 각 그래프는 각 변수마다 두 개의 정점을 갖는다.
	adj.clear(); adj.resize(vars * 2);
	for (int i = 0; i < vars; i += 2)
	{
		// 각 팀은 i번 회의나 j번 회의 둘 중 하나는 해야 한다.
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
// adj[]에 합의 그래프의 인접 리스트 표현이 주어질 때, 2-SAT 문제의 답을 반환한다.
vector<int> solve2SAT()
{
	int n = adj.size() / 2; // 변수의 수
	// 함의 그래프의 정점들을 강결합 요소별로 묶는다.
	vector<int> label = tarjanSCC();
	// 이 SAT 문제를 푸는 것이 불가능한지 확인한다. 한 변수를 나타내는 두 정점이
	// 같은 강결합 요소에 속해 있을 경우 답이 없다.
	for (int i = 0; i < 2 * n; i += 2)
		if (label[i] == label[i + 1])
			return vector<int>();
	// SAT 문제를 푸는 것이 가능하다. 답을 생성하자
	vector<int> value(n, -1);
	// Tarjan 알고리즘에서 SCC번호는 위상 정렬의 역순으로 배정된다.
	// SCC 번호의 역순으로 각 정점을 정렬하면 위상 정렬 순서가 된다.
	vector<pair<int, int>> order;
	for (int i = 0; i < 2 * n; i++)
		order.push_back({ -label[i], i });
	sort(order.begin(), order.end());
	// 각 정점에 값을 배정한다.
	for (int i = 0; i < 2 * n; i++)
	{
		int vertex = order[i].second;
		int variable = vertex / 2, isTrue = vertex % 2 == 0;
		if (value[variable] != -1)
			continue;
		// not A가 A보다 먼저 나왔으면 A는 참
		// A가 not A보다 먼저 나왔으면 A는 거짓
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
		vector<pair<int, int>> meetings(N * 2); // 2개 씩이니.
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
