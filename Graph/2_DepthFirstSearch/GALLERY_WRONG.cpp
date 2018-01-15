// 내가 생각한 방법, 노드의 갯수가 많아 짐에 따라 시간이 무한,,, 
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int C; int G; int H;
vector<vector<int> > map; vector<int> visited;
//queue<int> q;
int main(void)
{
	scanf("%d", &C);
	while (C--)
	{
		scanf("%d %d", &G, &H);
		int cameraCount = 0x7fffffff;
		map = vector<vector<int> >(G, vector<int>(G, 0));
		// make graph
		for (int i = 0; i < H; i++)
		{
			int a = 0, b = 0;
			scanf("%d %d", &a, &b);
			map[a][b] = 1; map[b][a] = 1; // bi-direction
		}
		// for all BFS
		int tempCamera;
		for (int here = 0; here < G; here++) // 각 점에서 시작
		{
			tempCamera = 0;
			visited = vector<int>(G, 0);
			visited[here] = 1; 
			queue<int> q;
			q.push(here);
			goto CHECK;
		CHECK:
			{
				while (!q.empty())
				{
					int now = q.front(); q.pop();
					bool flag = false;
					for (int there = 0; there < G; there++)
					{
						if (map[now][there] == 1 && visited[there] != 1)
						{
							visited[there] = 1;
							q.push(there);
							flag = true;
						}
					}
					if (flag == true) tempCamera++;
				}	
			}
			int i; bool flag2 = false;
			for (i = 0; i < G; i++)
			{
				if (visited[i] == 0)
				{
					flag2 = true;
					break;
				}
			}
			if (flag2)
			{
				visited[i] = 1;
				q.push(i);
				goto CHECK;
			}
			if (tempCamera < cameraCount) cameraCount = tempCamera;
		}
		printf("%d\n", cameraCount);
	}
	return 0;
}
