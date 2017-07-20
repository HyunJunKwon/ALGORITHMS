#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;
int map[1010][1010];
int N, M, V;
queue<int> QUEUE;
stack<int> STACK;
int visit[10010];
void DFS(int V)
{
	visit[V] = 1;
	STACK.push(V);
	cout << STACK.top() << " ";
	for (int i = 1; i <= N; i++)
	{
		if (map[V][i] == 1 && !visit[i])
		{
			DFS(i);
		}
	}

}
void BFS(int v) {
	visit[v] = 1;
	QUEUE.push(v);
	while (!QUEUE.empty()) {
		cout << QUEUE.front() << " ";
		v = QUEUE.front();
		QUEUE.pop();
		for (int i = 1; i <= N; i++) 
		{
			if (map[v][i] == 1 && !visit[i]) 
			{
				visit[i] = 1;
				QUEUE.push(i);
			}
		}
	}
}
int main() {
	int v1, v2 = 0;
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) 
	{
		cin >> v1 >> v2;
		map[v1][v2] = map[v2][v1] = 1;
	}
	DFS(V);
	cout << endl;
	memset(visit, 0, 10010);
	BFS(V);
	cout << endl;
	return 0;
}
