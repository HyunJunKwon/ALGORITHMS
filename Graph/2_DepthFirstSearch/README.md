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

* Example Problem 1. [WORDCHAIN](https://algospot.com/judge/problem/read/WORDCHAIN)
<br/>

### 6. 이론적 배경과 응용
<br/>

![DFS Spanning Tree](https://github.com/HyunJunKwon/ALGORITHMS/blob/master/PictureMaterials/Graph_DFS_SpanningTree.jpg?raw=true) 

* 깊이 우선 탐색과 간선의 분류
	* 간선들을 무시하지 않고 이들에 대한 정보를 수집하면 그래프의 구조에 대해 많은 것을 알 수 있다.
	* 어떤 그래프를 DFS했을 때, 탐색이 따라가는 간선들만을 모아 보면 트리 형태를 띠게 된다. (위 그림 (a)참조) 이런 트리를 주어진 그래프의 깊이 우선 탐샘 스패닝 트리 혹은 DFS Spanning Tree라고 부른다. 그래프의 DFS 스패닝 트리를 생성하고 나면 그래프의 모든 간선을 다음과 같이 네 가지 중 하나로 분류할 수 있다.
    		* 트리 간선(tree edge)은 스패닝 트리에 포함된 간선을 의미한다. 위의 그림의 (b)에서 굵은 선으로 표시된 간선들이 모두 트리 간선이다.
		* 순방향 간선(forward edge)은 스패닝 트리의 선조에서 자손으로 연결되지만 트리 간선이 아닌 간선을 의미한다. (b)의 (0,6) 간선이 순방향 간선의 예이다.
		* 역방향 간선(back edge)은 스패닝 트리의 자손에서 선조로 연결되는 간선이다. (b)의 (2,0)이 예이다.
	이 세 가지 분류를 제외한 나머지 간선들은 교차 간선(cross edge)라고 부른다. 교차 간선은 트리에서 선조와 자손 관계가 아닌 정점들 간에 연결된 간선들을 의미한다.(6,3)과 같은 간선이 예이다.
		* 이 그래프의 간선을 항상 이렇게 분류해야 하는 것은 아니다. DFS가 어느 순서대로 정점을 방문하느냐에 따라 서로 다른 트리가 생성될 수 있고, 그에 따라 각 간선의 구분이 서로 달라질 수 있다.


* 무향 그래프의 간선의 분류

	* 무향 그래프의 모든 간선은 양방향으로 통행 가능하므로, 무향 그래프에는 교차 간선이 있을 수 없다.
	
	* 사이클의 존재 여부 확인하기
		* 간선의 분류를 이용하면 이 문제를 간단하게 풀 수 있다.
		* 사이클의 존재 여부는 역방향 간선의 존재 여부와 동치이다.

* 간선을 구분하는 방법
	* 정점을 방문할 때 이 정점이 방문되었다는 사실 뿐만 아니라, 이 정점이 몇 번째로 발견되었는지도 동시에 기록한다. 이 정보를 이용해서 순방향과 역방향 그리고 교차 간선을 구분해낼 수 있다.
		* (u, v)가 순방향 간선이라면 v는 u의 자손이어야 한다. 따라서 v는 u보다 더 늦게 발견되어야 한다.
		* (u, v)가 역방향 간선이려면 v는 u의 선조여야 한다. 따라서 v는 u보다 일찍 발견되었어야 한다.
		* (u, v)가 교차 간선이려면 dfs(v)가 종료한 후 dfs(u)가 호출되어야 한다. 따라서 v는 u보다 일찍 발견되었어야 한다.
이처럼 발견 순서 정보를 이용하면 해당 간선이 순방향 간선인지를 알아낼 수 있다.

```
// 간선을 구분하는 DFS 구현
vector<vector<int> > adj;
// discovered[i]= i번 정점의 발견 순서
// finished[i] = dfs(i)가 종료했으면 1, 아니면 0
vector<int> discovered, finished;
// 지금까지 발견한 정점의 수
int counter;
void dfs2(int here)
{
	discovered[here] = counter++;
	// 모든 인접 정점을 순회하면서
	for(int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		cout << "(" << here << "," << there << ") is a ";
		// 아직 방문한 적 없다면 방문한다.
		if(discovered[there] == -1)
		{
			cout << "tree edge" << endl;
			dfs2(there);
		}
		// 만약 there가 here보다 늦게 발견됐으면 there는 here의 후손이다.
		else if(discovered[here] < discovered[there])
			cout << "forward edge" << endl;
		// 만약 dfs2(there)가 아직 종료하지 않았으면 there는 here의 선조다.
		else if(finished[there] == 0)
			cout << "back edge" << endl;
		// 이 외의 경우는 모두 교차 간선
		else
			cout << "cross edge" << endl;  
	}
	finished[here] = 1;
}
```
![절단점](https://github.com/HyunJunKwon/ALGORITHMS/blob/master/PictureMaterials/Graph_DFS_CutVertex.jpg?raw=true)

* 절단점 찾기 알고리즘
	* 어떤 무향 그래프의 절단점이란 이 점과 인접한 간선들을 모두 지웠을 때 해당 컴포넌트가 두 개 이상으로 나뉘어지는 정점을 말한다.
어떤 정점이 절단점인지 확인하는 간단한 방법은 해당 정점을 그래프에서 삭제한 뒤, 컴포넌트의 개수가 이전보다 늘어났는지를 확인하는 것이다. 그러나 탐색 과정에서 얻는 정보를 잘 이용하면 한 번의 DFS만으로 그래프의 모든 절단점을 찾아낼 수 있다.
	* u의 자손들을 루트로 하는 서브트리들은 서로 연결되어 있지 않다. 이들을 연결하는 간선이 있다면 교차 간선일 텐데, 무향 그래프에는 교차 간선이 있을 수 없기 때문이다. 따라서 u가 지워졌을 때 그래프가 쪼개지지 않는 유일한 경우는 그림에 그려진 것처럼 u의 선조와 자손들이 전부 역방향 간선으로 연결되어 있을 때 뿐이다. 이것을 확인하는 간단한 방법은 DFS를 수행하는 함수 dfs2()가 각 정점을 루트로 하는 서브트리에서 역방향 간선을 통해 갈 수 있는 정점의 최소 깊이를 반환하도록 하는 것이다. 만약 u의 자손들이 모두 역방향 간선을 통해 u의 선조로 올라갈 수 있다면 u는 절단점이 아니다. 실제로 이 알고리즘을 구현할 때는 각 정점의 깊이를 비교하는 대신, 각 정점의 발견 순서를 비교하는 형태로 코드를 작성해 구현을 간단하게 할 수 있다.

```
// 무향 그래프에서 절단점을 찾는 알고리즘
vector<vector<int> > adj;
vector<int> discovered;
vector<bool> isCutVertex;
int counter = 0;
// here를 루트로 하는 서브트리에 있는 절단점들을 찾는다.
// 반환값은 해당 서브트리에서 역방향 간선으로 갈 수 있는 정점 중
// 가장 일찍 발견된 정점의 발견 시점. 처음 호출할 때는 isRoot = true로 둔다.
int findCutVertex(int here, bool isRoot)
{
	// 발견 순서를 기록한다
	discovered[here] = counter++;
	int ret = discovered[here];
	// 루트인 경우의 절단점 판정을 위해 자손 서브트리의 개수를 센다.
	int children = 0;
	for(int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if(discovered[there] == -1)
		{
			++children;
			// 이 서브트리에서 갈 수 있는 가장 높은 정점의 번호
			int subtree = findCutVertex(there, false);
			// 그 노드가 자기 자신 이하에 있다면 현재 위치는 절단점
			if(!isRoot && subtree >= discovered[here])
				isCutVertex[here] = true;
			ret = min(ret, subtree);
		}
		else
			ret = min(ret, discovered[there]);
	}
	// 루트인 경우 절단점 판정은 서브트리의 개수로 한다.
	if(isRoot) isCutVertex[here] = (children >= 2);
	return ret;
}
```

* 다리 찾기
	* 어떤 간선을 삭제했을 때 이 간선을 포함하던 컴포넌트가 두 개의 컴포넌트로 쪼개질 경우 이 간선을 다리(bridge)라고 한다.
	* 그래프에서 다리를 찾는 문제는 절단점을 찾는 알고리즘을 간단히 변형해서 풀 수 있다.
	* 가장 먼저 깨달아야 할 점은 다리는 항상 트리 간선일 수 밖에 없다는 점이다.
	* 어떤 간선 (u, v)가 순방향 간선이나 역방향 간선이라면 u와 v를 잇는 또 다른 경로가 있다는 것인데, 그러면 (u, v)는 결코 다리가 될 수 없다. 따라서 트리 간선들에 대해서만 이 간선이 다리인지를 판정하면 된다.
	* DFS 스패닝 트리 상에서 u가 v의 부모일 때, 트리 간선 (u, v)가 다리가 되기 위해서는 v를 루트로 하는 서브트리와 이 외의 점들을 연결하는 유일한 간선이 (u, v)여야 합니다. 따라서 역방향 간선 중 자신의 부모로 가는 간선을 무시하도록 한 뒤, v와 그 자손들에게서 역방향 간선으로 닿을 수 있는 정점의 최소 발견 순서가 u 후라면 (u, v)가 다리라고 판정할 수 있다. 


![강결합컴포넌트](https://github.com/HyunJunKwon/ALGORITHMS/blob/master/PictureMaterials/Graph_DFS_SCC1.jpg?raw=true)

* 강결합 컴포넌트 분리
	* 이중 결합 컴포넌트의 개념은 무향 그래프에서만 정의된다.

	* 이중 결합 컴포넌트와 비슷하지만 방향 그래프에서 정의되는 개념으로 강결합 컴포넌트(SCC: Strongly Connected Components)가 있다. 방향 그래프 상에서 두 정점 u와 v에 대해 양 방향으로 가는 경로가 모두 있을 때 두 정점은 같은 SCC에 속해 있다고 한다. 

	* SCC의 재미있는 점은 방향 그래프에서 각 SCC 사이를 연결하는 간선들을 모으면 SCC들을 정점으로 하는 DAG를 만들 수 있다는 것이다. (그래프의 압축(condensation))

	* SCC는 사이클과도 밀접하게 연관되어 있다. 한 사이클에 포함된 정점들은 항상 같은 SCC에 속해 있게 된다. 반대로 한 SCC에 속한 두 정점 사이를 잇는 양방향 경로를 합치면 두 정점을 포함하는 사이클이 된다.


* 강결합 컴포넌트 분리를 위한 타잔의 알고리즘
	* 주어진 그래프를 SCC로 분할하는 간단한 방법은 모든 정점에서 한 번씩 DFS를 수행하는 것이다. 하지만 이런 방법은 O(|V|X|E|)시간을 필요...
강결합 컴포넌트 분리를 위한 타잔(Tarjan)의 알고리즘은 한 번의 DFS로 각 정점을 SCC별로 분리한다. 위 그림에서 처럼 주어진 그래프의 스패닝 트리를 적절히 자르기만 해도 정점들을 SCC로 분리할 수 있다는 점이다.
정점 x를 처음 방문했다고 하자, 한 SCC에 속한 두 정점 간에는 항상 경로가 있기 때문에, 깊이 우선 탐색은 dfs(x)가 종료하기 전에 같은 SCC에 속한 정점을 전부 방문하게 될 것이다. 따라서 이 SCC에 속한 정점들은 모두 x를 루트로 하는 서브트리에 포함된다. 이때 스패닝 트리를 잘라서 SCC를 분리할 수 없는 유일한 경우는 x와 같은 SCC에 속한 정점 y사이에 다른 정점 z가 끼어 있는 경우뿐이다. 그러나 이 경우 z에서 y로 가는 경로와 y에서 x로 가는 경로를 합치면 z에서 x로 가는 경로를 만들 수 있다. 따라서 z와 x는 같은 SCC에 속해야 하고, 원래의 가정이 모순이 됨을 알 수 있다.

```
// 그래프의 인접 리스트 표현
vector<vector<int> > adj;
// 각 정점의 컴포넌트 번호. 컴포넌트 번호는 0 부터 시작하며, 
// 같은 강결합 컴포넌트에 속한 정점들의 컴포넌트 번호가 같다.
vector<int> sccId;
// 각 정점의 발견 순서와 scc() 종료 여부
vector<int> discovered, finished;
// 정점의 번호를 담는 스택
stack<int> st;
int sccCounter, vertexCounter;
// here 를 루트로 하는 서브트리에서 역방향 간선으로 닿을 수 있는 최소의 발견 순서를
// 반환한다.
int scc(int here) {
  int ret = discovered[here] = vertexCounter++;
  // 스택에 here 를 넣는다. here 의 후손들은 모두 스택에서 here 후에 들어간다.
  st.push(here);  
  for(int i = 0; i < adj[here].size(); ++i) {
    int there = adj[here][i];
    // (here,there) 가 트리 간선
    if(discovered[there] == -1) 
      ret = min(ret, scc(there));
    // (here,there) 가 역방향이나 교차 간선
    else if(discovered[there] < discovered[here] && sccId[there] == -1) 
      ret = min(ret, discovered[there]);
  }  
  // here 가 강결합 컴포넌트의 루트인가 확인한다
  if(ret == discovered[here]) {
    // here 를 루트로 하는 서브트리에 남아 있는 정점들을 전부 하나의 컴포넌트로 묶는다
    while(true) {
      int t = st.top();
      st.pop();
      sccId[t] = sccCounter;
      if(t == here) break;
    }
    ++sccCounter;
  }
  finished[here] = 1;
  return ret;
}
// tarjan 의 SCC 알고리즘
vector<int> tarjanSCC() {
  // 배열들을 전부 초기화
  sccId = discovered = vector<int>(adj.size(), -1);
  finished = vector<int>(adj.size(), 0);
  // 카운터 초기화
  sccCounter = vertexCounter = 0;
  // 모든 정점에 대해 scc() 호출
  for(int i = 0; i < adj.size(); i++) if(discovered[i] == -1) scc(i);
  return sccId;
}
```
[GALLERY](https://algospot.com/judge/problem/read/GALLERY) <br/>
[MEETINGROOM](https://algospot.com/judge/problem/read/MEETINGROOM)
