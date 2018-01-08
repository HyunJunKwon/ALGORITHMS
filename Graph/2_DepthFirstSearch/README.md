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

<br/>

![Topological Sort](https://github.com/HyunJunKwon/ALGORITHMS/blob/master/PictureMaterials/Graph_DFS_TopologicalSort.jpg?raw=true)
   
* 그림을 보면, dfs가 종료될 때 정점을 기록하면, (5,4,3,2,1,7,8,9,6,10) 순으로 이를 역순으로 정렬하면 위상 정렬의 순서가 된다. 알고리즘 상에서 adj에는 인접 간선이 0으로 표현되어 있어도 각 정점은 존재하니, 굳이 표현하지 않아도 된다. 또한 책과 순서가 다른 이유는 여러가지 위상 정렬이 있기 때문.

* DFS를 이용한 위상 정렬
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
// adj에 주어진 그래프를 위상 정렬한 결과를 반환한다.
vector<int> topologicalSort()
{
   int n = adj.size();
   visited = vector<int>(n , 0);
   order.clear();
   for(int i = 0; i < n; i++)
      if(!visited[i])
         dfs(i);
   reverse(order.begin(), order.end());
   // 만약 그래프가 DAG가 아니라면 정렬 결과에 역방향 간선이 있다.
   // 그래프가 DAG가 아니라면 빈 벡터를 반환한다.hgf
   for(int i = 0; i < n; i++)
      for(int j = i + 1; j < n; j++)
         if(adj[order[j]][order[i]])
            return vector<int>();
   // 없는 경우라면 깊이 우선 탐색에서 얻은 순서를 반환한다.
   return order;
}
```
* Example Problem 1. [DICTIONARY](https://algospot.com/judge/problem/read/DICTIONARY)

<br/>

### 5. Eulerian Circuit

* 그래프의 모든 간선을 정확히 한 번씩 지나서 시작점으로 돌아오는 경로를 찾는 문제. 한붓 그리기 문제로도 알려져있다.
* 그래프의 간선들이 두 개 이상의 컴포넌트에 나뉘어 있는 경우는 당연히 오일러 서킷이 존재할 수 없을 것이다.

* 경로의 시작점을 u, 끝점을 v라고 할 때,
   
   1. u != v인 경우, 항상 v는 홀수 개의 간선과 인접해 있을 겁니다. v를 지나가기 위해서는 v로 들어가는 데 하나, 나가는 데 하나의 간선이 필요하고, 때문에 v로 들어가서 더이상 나올 수 없다는 말은 인접한 간선의 수가 홀수라는 의미이기 때문이다.
   
   2. u = v인 경우, v에 인접한 간선의 수는 항상 짝수입니다. u에서 나가는 것으로 시작했으니, 들어온 뒤 다시 나갈 수 없다면 지금까지 사용한 간선의 수는 항상 짝수여야하기 때문이다. 따라서 그래프의 모든 정점들이 짝수점이어야만 오일러 서킷이 존재할 수 있다는 결론!

* 오일러 서킷을 찾아내는 알고리즘 ```findRandomCircuit()```

![EulerCircuit](https://github.com/HyunJunKwon/ALGORITHMS/blob/master/PictureMaterials/Graph_DFS_EulerianCircuit.jpg?raw=true)

   * 그래프의 모든 정점은 짝수점이므로, 시작점 외의 다른 정점에서 종료하는 것은 불가능하다. 따라서 항상 시작점에서 끝나고 찾아낸 경로는 항상 서킷이 된다. 만약 이 서킷이 모든 간선을 지나친 서킷이 아니라면, 서킷의 각 정점들을 하나하나 돌아보며 아직 따라가지 않은 간선과 인접해 있는 정점들을 찾도록 한다. 이 점 v에서 다시 ```findRandomCircuit()```을 수행하면 새로운 서킷을 얻게된다. 처음에 찾았던 서킷을 v에서 찾은 서킷과 합치면 하나의 큰 서킷을 쉽게 만들 수 있다. 이와 같이 서킷이 모든 간선을 다 포함할 때까지 반복하면 오일러 서킷을 쉽게 찾을 수 있다.

```
// DFS를 이용한 오일러 서킷 찾기
// 그래프의 인접 행렬 표현, adj[i][j] = i와 j사이의 간선의 수
vector<vector<int> > adj;
// 무향 그래프의 인접 행렬 adj가 주어질 때 오일러 서킷을 계산한다.
// 결과로 얻어지는 circuit을 뒤집으면 오일러 서킷이 된다.
void gerEulerCircuit(int here, vector<int>& circuit)
{
	for(int there = 0; there < adj.size(); there++)
	{
		while(adj[here][there] > 0)
		{
			// 양쪽 간선을 모두 지운다.
			adj[here][there]--;
			adj[there][here]--;
			getEulerCircuit(there, circuit);
		}
	}
	circuit.push_back(here);
}
```

* 오일러 트레일(Eulerian Trail)
   
   * 오일러 서킷처럼 그래프의 모든 간선을 정확히 한 번씩 지나지만, 시작점과 끝점이 다른 경로를 말한다.
   
   * 점 a에서 시작해서 b에서 끝나는 오일러 트레일을 찾고 싶다면, a와 b 사이에 간선 (b, a)를 추가한 뒤 오일러 서킷을 찾는다. 그리고 (b, a)간선을 지워서 서킷을 끊으면 우리가 원하는 오일러 트레일을 얻을 수 있다.


<br/>

### 6. 이론적 배경과 응용
