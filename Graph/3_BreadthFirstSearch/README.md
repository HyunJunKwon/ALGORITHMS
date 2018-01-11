# 3. Breadth First Search

<br/>

![bfs](https://github.com/HyunJunKwon/ALGORITHMS/blob/master/PictureMaterials/Graph_BFS_BFS.jpg?raw=true)

<br/>

```
// 그래프의 너비 우선 탐색
vector<vector<int> > adj;
vector<int> bfs(int start)
{
	// 각 정점의 방문 여부
	vector<bool> discovered(adj.size(), false);
	// 방문할 정점 목록을 유지하는 큐
	queue<int> q;
	// 정점의 방문 순서
	vector<int> order;
	discoverd[start] = true;
	q.push(start);
	while(!q.empty())
	{
		int here = q.front();
		q.pop();
		// here를 방문한다.
		order.push_back(here);
		// 모든 인접한 정점을 검사한다.
		for(int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i];
			// 처음 보는 정점이면 방문 목록에 집어넣는다.
			if(!discovered[there])
			{
				q.push(there);
				discovered[there] = true;
			}
		}
	}
	return order;
}
```

  * 깊이 우선 탐색에서처럼, 너비 우선 탐색에서 새 정점을 발견하는 데 사용했던 간선들만을 모은 트리를 너비 우선 탐색 스패닝 트리(BFS Spanning Tree)라고 부른다.

  * BFS의 시간 복잡도
    * 인접 리스트로 구현된 경우: O(|V| + |E|)
    * 인접 행렬로 구현된 경우: O(|V|^2)

  * BFS와 최단 거리
    * 그래프의 구조에 관련된 다양한 문제를 푸는 데 사용되는 깊이 우선 탐색과 달리, 너비 우선 탐색은 대개 딱 하나의 용도로 사용된다. 바로 그래프에서의 최단 경로 문제를 푸는 것이다. 
    * BFS 알고리즘을 간단하게 변경해 모든 정점에 대해 시작점으로부터 거리 distance[]를 계산하도록 할 수 있다.
    * BFS 과정에서 간선 (u, v)를 통해 정점 v를 처음 발견해 큐에 넣었다고 하자, 이때 시작점으로부터 v까지의 최단거리 distance[v]는 시작점으로부터 u까지의 최단 거리 distance[u]에 1을 더한 것이다.
    * 이 속성의 또 다른 중요한 의미는 시작점으로부터 다른 모든 정점까지의 최단 경로를 BFS 스패닝 트리 위에서 찾을 수 있다는 것이다. 각 정점으로부터 트리의 루트인 시작점으로 가는 경로가 실제 그래프 상에서의 최단 경로임을 알 수 있다.

```
// 최단 경로를 계산하는 BFS
// start에서 시작해 그래프를 BFS로 탐색하고 시작점부터 각 정점까지의
// 최단 거리와 BFS 스패닝 트리를 계산한다.
// distance[i] = start부터 i까지의 최단거리
// parent[i] = BFS 스패닝 트리에서 i의 부모의 번호. 루트인 경우 자신의 번호
void bfs2(int start, vector<int>& distance, vector<int>& parent)
{
	distance = vector<int>(adj.size(), -1);
	parent = vector<int>(adj.size(), -1);
	// 방문할 정점 목록을 유지하는 큐
	queue<int> q;
	distance[start] = 0;
	q.push(start);
	while(!q.empty())
	{
		int here = q.front();
		q.pop();
		for(int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i];
			// 처음 보는 정점이면 방문 목록에 집어넣는다.
			if(distance[there] == -1)
			{
				q.push(there);
				distance[there] = distance[here] + 1;
				parent[there] = here;
			}
		}
	}
}
```

  * 모든 점의 발견
    * 그래프 전체의 구조에 관한 정보를 얻기 위해 사용되는 DFS와 달리, BFS는 대개 시작점으로부터 다른 정점들까지의 거리를 구하기 위해 사용된다. 따라서 DFS에서처럼 모든 정점을 검사하면서 탐색을 수행하는 작업은 잘 하지 않는다.

  * [Sorting Game](https://algospot.com/judge/problem/read/SORTGAME)

  * [CHILDRENDAY](https://algospot.com/judge/problem/read/CHILDRENDAY)

  * 최단 경로 전략
    * BFS는 최단 경로 문제를 푸는 가장 직관적이고 유명한 방법이지만, 모든 최단 경로 문제를 BFS만으로 풀 수 있는 것은 아니다. 문제에 따라서는 BFS보다 다른 탐색 알고리즘이 더 강력한 경우가 있다.

<br/>

 ![puzzle](https://github.com/HyunJunKwon/ALGORITHMS/blob/master/PictureMaterials/Graph_BFS_Puzzle.JPG?raw=true)

<br/>

* 15-퍼즐(빈 칸에 상하좌우로 인접한 타일 중 하나를 빈 칸으로 움직이기를 반복해, 주어진 상태를 오른쪽에 주어진 종료 상태로 바꾸는 것)
    * 이 문제를 풀기 위한 첫 번째 단계는 게임판의 상태를 정점으로 표현한 그래프를 만드는 것이다. 이와 같은 그래프를 상태 공간(state space)이라고 부른다. 게임판에는 빈 칸까지 포함해 열여섯 개의 타일이 있으므로, 상태 공간은 16!개의 정점을 갖게 된다. 한번의 움직임으로 한 생태를 다른 상태로 바꿀 수 있을 때 두 정점을 간선으로 연결한다. 따라서 각 정점에는 최대 네 개의 이웃 정점이 있다. 밑의 그림은 상태 공간의 일부를 보여준다. 빈 칸이 어느쪽으로 옮겨가느냐에 따라 네 정점 중 하나로 움직임을 알 수 있다. 이와 같이 생태 공간을 만들고 나면 15-퍼즐 문제는 그래프 상에서의 최단 경로 문제가 된다.

![puzzlestate](https://github.com/HyunJunKwon/ALGORITHMS/blob/master/PictureMaterials/Graph_BFS_Puzzle_state.JPG?raw=true)


  * BFS를 이용한 풀이
```
// 게임판의 상태를 표현한다
class State
{
	// 인접한 상태들의 목록을 반환한다.
	vector<State> getAdjacent() const;
	// map에 State를 넣기 위한 비교 연산자
	bool operator < (const State& rhs) const;
	// 종료 상태와 비교하기 위한 연산자
	bool operator == (const State& rhs) const; 
};
typedef map<State, int> StateMap;
// start에서 finish까지 가는 최단 경로의 길이를 반환한다.
int bfs(State start, State finish)
{
	// 예외: start == finish인 경우
	if(start == finish) return 0;
	// 각 정점까지의 최단 경로의 길이를 저장한다
	StateMap c;
	// 앞으로 방문할 정점들을 저장한다.
	queue<State> q;
	q.push(start);
	c[start] = 0;
	// 너비 우선 탐색
	while(!q.empty())
	{
		State here = q.front();
		q.pop();
		int cost = c[here];
		// 인접한 정점들의 번호를 얻어낸다.
		vector<State> adjacent = here.getAdjacent();
		for(int i = 0; i < adjacent.size(); i++)
		{
			if(c.count(adjacent[i]) == 0)
			{
				// 답을 찾았나?
				if(adjacent[i] == finish) return cost + 1;
				c[dajacent[i]] = cost + 1;
				q.push(adjacent[i]);
			}
		}
	}
	// 답을 찾지 못한 경우
	return -1;
}
```

  * 위 BFS의 시간 복잡도는 물론 O(|V| + |E|)지만, 이 문제에서는 상태 공간 전체를 탐색하지 않고, 답을 찾는 대로 BFS를 종료하기 때문에 시간 복잡도를 다르게 계산해야 한다.

  * 양방향 탐색
    * 이렇게 두 정점 사이의 최단 경로를 찾을 때 사용할 수 있는 굉장히 간단하면서도 유용한 테크닉 중 하나로 양방향 탐색(bidirectional search)이 있다. 
```
class State;
// x의 부호를 반환한다
int sgn(int x) {if(!x) return 0; return x > 0 ? 1 : -1;}
// x의 절대값을 1 증가시킨다
int incr(int x) {if(x < 0) return x - 1; return x + 1;}
// start에서 finish까지 가는 최단 경로의 길이를 반환한다.
int bidirectional(State start, State finish)
{
	// 각 정점까지의 최단 경로의 길이를 저장한다.
	map<State, int> c;
	// 앞으로 방문할 정점들을 저장한다.
	queue<State> q;
	// 시작 상태와 목표 상태가 같은 경우는 예외로 처리해야 한다.
	if(start == finish) return 0;
	q.push(start); c[start] = 1;
	q.push(finish); c[finish] = -1;
	while(!q.empty())
	{
		State here = q.front();
		q.pop();
		// 인접한 정점들의 번호를 얻어낸다.
		vector<State> adjacent = here.getAdjacent();
		for(int i = 0; i < adjacent.size(); i++)
		{
			map<State, int>::iterator it = c.find(adjacent[i]);
			if(it == c.end())
			{
				c[adjacent[i]] = incr(c[here]);
				q.push(adjacent[i]);
			}
			// 가운데서 만난 경우
			else if(sgn(it->second) != sgn(c[here]))
				return abs(it->second) + abs(c[here]) - 1;
		}
	
	}
	// 답을 찾지 못한 경우
	return -1;
}

```

