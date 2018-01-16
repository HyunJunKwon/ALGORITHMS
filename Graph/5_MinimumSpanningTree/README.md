# Minimum Spanning Tree

가중치 그래프의 스패닝 트리 중 가중치의 합이 가장 작은 트리를 찾은 문제를 최소 스패닝 트리 문제라고 한다.

* 크루스칼의 최소 스패닝 트리 알고리즘

![MST1](https://github.com/HyunJunKwon/ALGORITHMS/blob/master/PictureMaterials/Graph_MST1.JPG?raw=true)

사이클이 되는 간선을 제외하면서 가중치가 제일 작은 간선을 추가한다.

```
// 크루스칼의 최소 스패닝 트리 알고리즘
// 트리를 이용해 상호 배제적 집합을 구현한다.
struct DisjointSet;
const int MAX_V = 100;
// 정점의 개수
int V;
// 그래프의 인접 리스트 (연결된 정점 번호, 간선 가중치) 쌍을 담는다.
vector<pair<int, int> > adj[MAX_V];
// 주어진 그래프에 대해 최소 스패닝 트리에 포함된 간선의 목록을 selected에
// 저장하고, 가중치의 합을 반환한다.
int kruskal(vector<pair<int, int> >& selected)
{
	int ret = 0;
	selected.clear();
	// (가중치, (정점1, 정점2))의 목록을 얻는다.
	vector<pair<int, pair<int, int> > > edges;
	for (int u = 0; u < V; u++)
	{
		for (int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i].first, cost = adj[u][i].second;
			edges.push_back(make_pair(cost, make_pair(u, v)));
		}
	}
	// 가중치 순으로 정렬
	sort(edges.begin(), edges.end());
	// 처음엔 모든 정점이 서로 분리되어 있다.
	DisjointSet sets(V);
	for (int i = 0; i < edges.size(); i++)
	{
		// 간선 (u, v)를 검사한다
		int cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;
		// 이미 u와 v가 연결되어 있을 경우 무시한다.
		if (sets.find(u) == sets.find(v)) continue;
		// 이 둘을 합친다.
		sets.merge(u, v);
		selected.push_back(make_pair(u, v));
		ret += cost;
	}
	return ret;
}
```

O(|E|lg|E|)의 시간 복잡도를 가진다.



* 프림의 최소 스패닝 트리 알고리즘

![PRIM1](https://github.com/HyunJunKwon/ALGORITHMS/blob/master/PictureMaterials/Graph_PRIM1.JPG?raw=true)

```
// 프림 알고리즘의 구현
const int MAX_V = 100;
const int INF = 987654321;
// 정점의 개수
int V;
// 그래프의 인접 리스트 (연결된 정점 번호, 간선 가중치) 쌍을 담는다.
vector<pair<int, int> > adj[MAX_V];
// 주어진 그래프에 대해 최소 스패닝 트리에 포함된 간선의 목록을 selected에
// 저장하고, 가중치의 합을 반환한다.
int prim(vector<pair<int, int> >& selected)
{
	selected.clear();
	// 해당 정점이 트리에 포함되어 있나?
	vector<bool> added(V, false);
	// 트리에 인접한 간선 중 해당 정점에 닿는 최소 간선의 정보를 저장한다.
	vector<int> minWeight(V, INF), parent(V, -1);
	// 가중치의 합을 저장할 변수
	int ret = 0;
	// 0번 정점을 시작점으로, 항상 트리에 가장 먼저 추가한다.
	minWeight[0] = parent[0] = 0;
	for (int iter = 0; iter < V; iter++)
	{
		// 다음에 트리에 추가할 정점 u를 찾는다.
		int u = -1;
		for (int v = 0; v < V; v++)
		{
			if (!added[v] && (u == -1 || minWeight[u] > minWeight[v]))
				u = v;
		}
		// (parent[u], u)를 트리에 추가한다.
		if (!parent[u] != u)
			selected.push_back(make_pair(parent[u], u));
		ret += minWeight[u];
		added[u] = true;
		// u에 인접한 간선(u, v)들을 검사한다.
		for (int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i].first, weight = adj[u][i].second;
			if (!added[v] && minWeight[v] > weight)
			{
				parent[v] = u;
				minWeight[v] = weight;
			}
		}
	}
	return ret;
}
```

