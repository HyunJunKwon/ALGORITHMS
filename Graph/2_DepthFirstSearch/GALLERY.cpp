/*
문제에서, 한 번 지나간 갤러리를 다시 지나기 위해서는 전에 지난 복도를
반드시 지나야 합니다 -> 사이클이 존재하지 않는다.
사이클이 존재하지 않는 그래프는 노드 간의 상하 관계가 없을 뿐이지
트리와 같은 형태를 가지고 있다. 이와 같은 그래프들을 루트 없는 트리라고 부른다.
조건: 1. 정확히 V-1개의 간선, 2. 사이클이 존재하지 않는다, 3. 두 정점 사이를 연결하는 단순 경로가 정확히 하나 있다.

루트 없는 트리를 다루는 가장 간단한 방법은 임의의 시작점으로부터 dfs 실행. 결과적으로 얻은
탐색 스패닝 트리는 원래 그래프의 구조를 그대로 갖고 있으면서 부모 자식 관계를 갖는 일반적인 트리가 된다.

트리의 지배 집합 찾기
트리의 최소 지배 집합을 찾는 가장 간단한 방법은 트리의 맨 아래에서부터 시작해서 위로 올라오는 것.
트리의 루트를 선택해야 할지 말아야 할지는 미리 알기 쉽지 않은 반면, 트리의 잎 노드를 선택할지 말지를 정하기란 쉽다.
1. 잎 노드는 선택하지 않습니다.
2. 이 외의 노드에 대해, 트리의 맨 밑에서부터 올라오면서 다음과 같이 선택 여부를 결정합니다.
	a) 자기 자손 중 아직 지배당하지 않은 노드가 하나라도 있다면 현재 노드를 선택합ㄴ디ㅏ.
	b) 이 외의 경우 현재 노드를 선택하지 않습니다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<bool> visited; vector<vector<int> > adj;
int G, H; int installed;
const int UNWATCHED = 0; const int WATCHED = 1; const int INSTALLED = 2;
/*
이번 dfs의 특징: return 형이 int이다.
leaf node까지 파고들어 그 node에서 상태를 확인한다 UNWATCHED반환
그리고 그 위에 node에서는 UNWATCHED가 ++되어 안보이는게 하나 있다는 걸 알게된다.

*/
int dfs(int here) 
{
	// 각 노드에서의 자식 노드의 상태
	int children[3] = { 0, 0, 0 }; // UNWATCHED, WATCHED, INSTALLED
	visited[here] = true;
	for (int i = 0; i < adj[here].size(); i++) 
	{
		int next = adj[here][i];
		if (!visited[next]) 
			children[dfs(next)]++;
	}
	/*
	위에서 dfs 진행하고
	빠져나가면 반환할 조건들 밑에 걸어준다.
	반환하는 것: 원하는것. (카메라의 갯수)
	*/
	// 자손 노드 중 감시되지 않는 노드가 있을 경우 카메라 설치 
	// 안보이는게 있는게 보이는게 있는거보다 우선임
	if (children[UNWATCHED]) 
	{ // 자식이 안보여지냐?
		installed++;
		return INSTALLED;
	}
	// 자손 노드 중 카메라가 설치된 노드가 있을 경우 설치할 필요 없다
	if (children[INSTALLED]) 
		return WATCHED;
	return UNWATCHED;
}
void installCamera() 
{
	installed = 0;
	visited = vector<bool>(G, false);
	for (int i = 0; i < G; i++) // 모든 점에서 dfs가 아닌 분리된 component찾기 위함임
	{
		// visited가 0이면 무조건 dfs들어가고 1이면 
		if (!visited[i] && dfs(i) == UNWATCHED) // visited가 1이면 바로 진행 0이면 dfs로 진행
			++installed;
	}
}
int main(void) 
{
	int C;
	scanf("%d", &C);
	while (C--) 
	{
		scanf("%d %d", &G, &H);
		adj.clear();
		adj.assign(G, vector<int>()); // G갯수만 할당해놓고
		while (H--) 
		{
			int inGallery, outGallery;
			scanf("%d %d", &outGallery, &inGallery);
			adj[outGallery].push_back(inGallery);
			adj[inGallery].push_back(outGallery); // 인접리스트!!!!
			// 이걸 adj = vector<vector<int> >(26, vector<int>(26, 0)); 이렇게 하면 행렬
		}
		installCamera();
		printf("%d\n", installed);
	}
	return 0;
}
