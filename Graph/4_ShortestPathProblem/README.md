# Shortest Path Problem

가중치가 없는 그래프에 대한 최단 경로는 앞선 BFS에서 찾을 수 있기 때문에, 이 절에서는 가중치가 있는 그래프 위에서의 최단 경로를 찾는 알고리즘들을 다룬다.

* 음수 간선의 중요성
  * 최단 경로 문제에서 음수 간선이 중요한 이유는 가중치의 합이 음수인 사이클이(음수 사이클)이 등장할 수 있기 때문이다. 음수 사이클을 반복해 돌면 경로의 길이는 음의 무한대까지 발산할 수 있습니다. 따라서 음수 사이클이 있는 경우 최단 경로 문제는 제대로 정의되지 않는다.

* 단일 시작점과 모든 쌍 알고리즘
  * 단일 시작점 알고리즘들은 너비 우선 탐색과 비슷하게, 하나의 시작점에서 다른 모든 정점까지 가는 최단 거리를 구해준다. 반면 모든 쌍 알고리즘은 모든 정점의 쌍에 대해 최단 거리를 계산한다. 따라서 모든 쌍 알고리즘의 수행 결과는 V x V 크기의 배열이 된다. 이 배열의 각 원소는 두 정점 사이의 최단 거리를 나타낸다.

* 방향 그래프와 무방향 그래프
  * 이 절에서 다루는 최단 거리 알고리즘들은 모두 방향 그래프를 기준으로 동작한다. 따라서 무방향 그래프 위에서의 최단 경로를 찾기 위해서는 각각의 양방향 간선을 두 개의 일방 통행 간선으로 쪼개서 방향 그래프로 만들어야만 한다. 그러나 음수 가중치가 있는 무방향 그래프에서는 이와 같은 기법을 사용할 수 없다. 무방향 음수 간선을 두 개로 쪼개면 이 둘만으로 음수 사이클을 만들 수 있기 때문이다. 따라서 음수 간선이 있는 무방향 그래프에 대해서는 항상 최단 경로 문제를 제대로 풀 수 없다.


### 다익스트라의 최단 경로 알고리즘

다익스트라 알고리즘은 단일 시작점 최단 경로 알고리즘으로, 시작 정점 s에서부터 다른 정점들까지의 최단 거리를 계산합니다.

* 우선순위 큐를 사용하는 너비 우선 탐색
  * 다익스트라 알고리즘은 너비 우선 탐색과 유사한 형태를 가진 알고리즘으로, 너비 우선 탐색처럼 시작점에서 가까운 순서대로 정점을 방문해 간다. 물론 가중치가 잇는 그래프에서는 너비 우선 탐색을 그대로 적용할 수 없다.
  * 다익스트라 알고리즘은 우선순위 큐를 사용함으로써 이 문제를 해결한다. 너비 우선 탐색에서는 큐에 정점의 번호를 넣었지만, 다익스트라 알고리즘에서는 우선순위 큐에 정점의 번호와 함께 지금까지 찾아낸 해당 정점까지의 최단 거리를 쌍으로 넣습니다.
  
![다익스트라1](https://github.com/HyunJunKwon/ALGORITHMS/blob/master/PictureMaterials/Graph_Dijkstra1.JPG?raw=true)

s->a->b->c가 s->c보다 최단이다.

```
// 다익스트라의 최단 거리 알고리즘 구현
// 정점의 개수
int V;
// 그래프의 인접 리스트. (연결된 정점 번호, 간선 가중치) 쌍을 담는다.
vector<pair<int, int> > adj[MAX_V];
vector<int> dijkstra(int src) 
{
	vector<int> dist(V, INF);
	dist[src] = 0;
	priority_queue<pair<int, int> > pq;
	// 우선순위 큐는 기본적으로 가장 큰 원소가 위로 가도록 큐를 구성하기 때문에,
	// 거리의 부호를 바꿔서 거리가 작은 정점부터 꺼내지도록 하는 것에 주목
	pq.push(make_pair(0, src));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		// 만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것을 무시한다.
		if (dist[here] < cost) continue;

		// 인접한 정점들을 모두 검사한다.
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			// 더 짧은 경로를 발견하면, dist[]를 갱신하고 우선순위 큐에 넣는다.
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;
}
```

![다익스트라2](https://github.com/HyunJunKwon/ALGORITHMS/blob/master/PictureMaterials/Graph_Dijkstra2.JPG?raw=true)

<br/>

* 우선순위 큐를 사용하지 않는 다익스트라 알고리즘의 구현
  * 정점의 수가 적거나 간선의 수가 매우 많은 경우에는 아예 우선순위 큐를 사용하지 않고 구현하는 방식이 더욱 빠른 경우가 있다. 매번 반복문을 이용하는데, 이 경우 다익스트라 알고리즘의 시간 복잡도는 O(|V|^2 + |E|)가 됨을 쉽게 알 수 있다.

```
// 우선순위 큐를 사용하지 않는 다익스트라 알고리즘의 구현
vector<int> dijkstra2(int src)
{
	vector<int> dist(V, INF);
	// 각 정점을 방문했는지 여부를 저장한다.
	vector<bool> visited(V, false);
	dist[src] = 0; visited[src] = true;
	while (true)
	{
		// 아직 방문하지 않은 정점 중 가장 가까운 정점을 찾는다.
		int closest = INF, here;
		for (int i = 0; i < V; i++)
		{
			here = i;
			closest = dist[i];
		}
		if (closest == INF) break;
		// 가장 가까운 정점을 방문한다.
		visited[here] = true;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			if (visited[there]) continue;
			int nextDist = dist[here] + adj[here][i].second;
			dist[there] = min(dist[there], nextDist);
		}
	}
	return dist;
}
```

<br/>

### 벨만-포드의 최단 경로 알고리즘
다익스트라 알고리즘과 똑같은 단일 시작점 최단 경로 알고리즘이지만, 음수 간선이 있는 그래프에 대해서도 최단 경로를 찾을 수 있으며 그래프에 음수 사이클이 있어서 최단 거리가 제대로 정의되지 않을 경우 이것도 알려준다.
벨만-포드 알고리즘은 시작점에서 각 정점까지 가는 최단 거리의 상한을 적당히 예측한 뒤 예측 값과 실제 최단 거리 사이의 오차를 반복적으로 줄여가는 방식으로 동작한다.
벨만-포드 알고리즘은 수행 과정에서 각 정점까지의 최단 거리의 상한을 담은 배열 upper[]를 유지한다.

* 벨만-포드의 동작과정
  * 시작점 u와 v까지의 최단 거리 ```dist[v] <= dist[u] + w(u, v)```

* 음수 사이클의 판정
  * 음수 사이클의 존재 여부를 판정하려면 |V| - 1번 모든 간선에 대해 완화를 시도하는 대신 |V|번 완화를 시도하면 된다. 그래프에 음수 사이클이 없다면 |V| - 1번만의 반복으로 모든 최단 거리를 찾아내기 때문에, 마지막 반복의 완화는 전부 실패한다. 반면 음수 사이클이 있다면 |V|번째 반복에서도 항상 완화가 한 번은 성공한다는 점을 증명할 수 있다.

```
// 벨만-포드 알고리즘의 구현
// 정점의 개수
int V;
// 그래프의 인접 리스트 (연결된 정점 번호, 간선 가중치) 쌍을 담는다.
vector<pair<int, int> > adj[MAX_V];
// 음수 사이클이 있을 경우 텅 빈 배열을 반환
vector<int> bellmanFord(int src)
{
	// 시작점을 제외한 모든 정점까지의 최단 거리 상한은 INF로 둔다.
	vector<int> upper(V, INF);
	upper[src] = 0;
	bool updated;
	// V번 순회한다.
	for (int iter = 0; iter < V; iter++)
	{
		updated = false;
		for (int here = 0; here < V; here++)
		{
			for (int i = 0; i < adj[here].size(); i++)
			{
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				// (here, there) 간선을 따라 완화를 시도한다.
				if (upper[there] > upper[here] + cost)
				{
					// 성공
					upper[there] = upper[here] + cost;
					updated = true;
				}
			}
			// 모든 간선에 대해 완화가 실패했을 경우 V - 1번도 돌 필요 없이 곧장 종료
			if (!updated) break;
		}
		// V 번째 순회에서도 완화가 성공했다면 음수 사이클이 있다.
		if (updated) upper.clear();
		return upper;
	}
}
```

<br/>

### 플로이드의 모든 쌍 최단 거리 알고리즘
문제에 따라서는 한 개의 시작점 대신 모든 정점 쌍에 대해 둘 사이의 최단 거리를 구해야 할 때도 있다. 플로이드 알고리즘은 그래프의 모든 정점 쌍의 최단 거리를 저장하는 2차원 배열 dist[][]를 계산한다. 이 배열의 원소 dist[u][v]는 정점 u에서 v로 가는 최단 거리를 나타낸다.

* 구현

```
// 플로이드 알고리즘의 구현
// 정점의 개수
int V;
// 그래프의 인접 행렬 표현
// adj[u][v] = u에서 v로 가는 간선의 가중치. 간선이 없으면 아주 큰 값을 넣는다.
int adj[MAX_V][MAX_V];
// 플로이드의 모든 쌍 최단 거리 알고리즘
void floyd()
{
	for (int i = 0; i < V; i++)
		adj[i][i] = 0;

	for (int k = 0; k < V; k++)
	{
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
		}
	}
}

```

* 플로이드 알고리즘의 최적화
  * 두 번째 for문 바로 다음에 i에서 k로 가는 경로가 실제 있는지를 확인해 본다. 만약 i에서 k로 가는 경로가 없다면 j에 대한 for문은 수행할 필요학 없다.

* 실제 경로 계산하기
  * 플로이드 알고리즘을 수행한 뒤 두 정점 사이의 최단 경로를 계산하기 위해서는 각 정점의 쌍 u, v에 대해 마지막으로 adj[u][v]를 갱신했을 때 사용했던 k의 값을 저장해 두면 된다.

```
// 플로이드 알고리즘에서 실제 최단 경로 계산하기
// 정점의 개수
int V;
// 그래프의 인접 행렬 표현
// adj[u][v] = u에서 v로 가는 간선의 가중치. 간선이 없으면 아주 큰 값을 넣는다.
int adj[MAX_V][MAX_V];
// via[u][v] = u에서 v까지 가는 최단 경로가 경유하는 점 중 가장 번호가 큰 정점
// -1로 초기화해 둔다.
int via[MAX_V][MAX_V];
// 플로이드의 모든 쌍 최단 거리 알고리즘
void floyd2()
{
	for (int i = 0; i < V; i++)
		adj[i][i] = 0;
	memset(via, -1, sizeof(via));

	for (int k = 0; k < V; k++)
	{
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if (adj[i][j] > adj[i][k] + adj[k][j])
				{
					via[i][j] = k;
					adj[i][j] = adj[i][k] + adj[k][j];
				}
			}
		}
	}
}
// u에서 v로 가는 최단 경로를 계산해 path에 저장한다.
void reconstruct(int u, int v, vector<int>& path)
{
	// 기저 사례
	if (via[u][v] == -1)
	{
		path.push_back(u);
		if (u != v) path.push_back(v);
	}
	else
	{
		int w = via[u][v];
		reconstruct(u, w, path);
		path.pop_back(); // w가 중복으로 들어가므로 지운다.
		reconstruct(w, v, path);
	}
}


```
