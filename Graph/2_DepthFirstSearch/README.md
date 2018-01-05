# 2. Depth First Search

### 1. Depth First Search Basic

<br/>

* Basic Representation of DFS

```
// 그래프의 인접 리스트 표현
vector<vector<int> > adj;
vector<bool> visited;
void dfs(int here)
{
   cout << "DFS visits" << here << endl;
   visited[here] = true;
   for(int i = 0; i < adj[here].size(); i++)
   {
      int there = adj[here][i];
      if(!visited[there])
         dfs(there);
   }
   // 더이상 방문할 정점이 없으니, 재귀 호출을 종료하고 이전 정점으로 돌아간다.
}
void dfsAll()
{
   visited = vector<bool>(adj.size(), false);
   for(int i = 0; i < adj.size(); i++)
   {
      if(!visited[i])
         dfs(i);
   }
}
```

* 대개 DFS는 그래프 전체의 구조를 파악하기 위해 사용되므로, 그래프의 구조상 한 번에 모든 정점을 다 볼 수 없는 경우에도 모든 정점을 다 방문할 필요가 있다.

* DFS의 시간 복잡도
   * DFS의 시간 복잡도는 어떤 그래프 표현 방식을 사용하느냐에 따라 달라진다.
   * 인접리스트의 경우: O(|V| + |E|)
   * 인접 행렬의 경우: O(|V|^2)

<br/>

## DFS가 쓰이는 예
### 2. 두 정점이 서로 연결되어 있는가 확인하기

* 어떤 정점 u에 대해 dfs(u)를 수행하면, u에서부터 간선들을 통해 갈 수 있는 모든 정점을 다 방문하게 된다. 따라서 dfs(u)를 실행하고 visited[]를 참조하면 u로 부터 각 정점에 갈 수 있는지를 쉽게 확인 할 수 있다.

<br/>

### 3. 연결된 부분집합의 개수 세기

* dfsAll()에서 visited[]를 check하면서 dfs()가 호출되는 횟수를 세면, 그래프가 몇 개의 컴포넌트로 나뉘어 있는지 쉽게 확인할 수 있다.

<br/>

### 4. Topological Sort (위상 정렬)

* 각 작업을 정점으로 표현하고, 작업 간의 의존 관계를 간선으로 표현한 방향 그래프를 의존성 그래프(dependency graph)라고 한다. 의존성 그래프의 가장 큰 특징은 그래프에 사이클이 없다는 점이다. 따라서 이 그래프는 사이클 없는 방향 그래프, 즉 DAG(Directed Acyclic Graph)가 된다.
DAG의 정점을 배열하는 문제를 위상 정렬(Topological Sort)이라고 하는데, 가장 직관적인 방법은 들어오는 간선이 하나도 없는 정점들을 하나씩 찾아서 정렬 결과의 뒤에 붙이고, 그래프에서 이 정점을 지우는 과정을 반복하는 것이다.
DFS를 사용하면 간단하게 이 문제를 해결할 수 있는데, dfsAll()을 수행하며 dfs()가 종료할 때마다 현재 정점의 번호를 기록하는 것이다. dfsAll()이 종료한 뒤 기록된 순서를 뒤집으면 위상 정렬 결과를 얻을 수 있다.
* picture
   * 그림을 보면,

```
vector<int> visited, order;
void dfs(int here)
{
   visited[here] = 1;
   for(int there = 0; there < adj.size(); ++there)
   {
      if(adj[here][there] && !visited[there])
         dfs(there);
   }
   order.push_back(here);
}
vector<>
```
* Example Problem 1. [DICTIONARY](https://algospot.com/judge/problem/read/DICTIONARY)

<br/>

### 5. Eulerian Circuit
    * Eulerian Trail

<br/>

### 6. 이론적 배경과 응용
