// 문제풀이
/*
해밀토니안 경로와 오일러 트레일
이 문제를 그래프로 표현하는 가장 직관적인 방법은 입력에 주어진 각 단어를 정점으로 하는 
방향 그래프를 만드는 것이다. (그림_WORDCHAIN_FIGURE1 참조) 이렇게 그래프의 모든 정점을 
정확히 한 번씩 지나는 경로를 해밀토니안 경로(Hamiltonian Path)라고 부른다.해밀토니안 
경로의 개념은 이해하기 쉽고 직관적이지만, 큰 그래프에 대해 해밀토니안 경로를 빠르게 
찾는 방법은 아직 고안되지 않았다. 따라서 최악의 경우 n!개의 후보를 만들어봐야해 시간초과가 
날 수 있다.
이 문제를 시간 안에 해결하는 방법은 입력에 주어진 각 단어를 정점이 아니라 간선으로 갖는 
방향 그래프를 만드는 것이다. (그림_WORDCHAIN_FIGURE1 참조) 이 그래프의 정점들은 알파벳의 
각 글자를 표현하며, 각 단어는 첫 글자에서 마지막 글자로 가는 간선이 된다.이 그래프의 
오일러 트레일 혹은 서킷을 찾으면 원래 문제의 답이 됨을 쉽게 알 수 있다.
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
// 그래프의 인접 행렬 표현. adj[i][j] = i와 j사이의 간선의 수
vector<vector<int> > adj;
// graph[i][j] = i로 시작해서 j로 끝나는 단어의 목록
vector<string> graph[26][26];
// indegree[i] = i로 시작하는 단어의 수
// outdegree[i] = i로 끝나는 단어의 수
vector<int> indegree, outdegree;
void makeGraph(const vector<string>& words)
{
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			graph[i][j].clear();
	adj = vector<vector<int> >(26, vector<int>(26, 0));
	indegree = outdegree = vector<int>(26, 0);
	// 각 단어를 그래프에 추가한다.
	for (int i = 0; i < words.size(); i++)
	{
		int a = words[i][0] - 'a';
		int b = words[i][words[i].size() - 1] - 'a';
		graph[a][b].push_back(words[i]);
		adj[a][b]++;
		outdegree[a]++;
		indegree[b]++;
	}
}
// 방향 그래프에서의 오일러 서킷
//이 문제에서 오일러 서킷을 찾을 그래프는 방향 그래프이다.
// 방향 그래프에서 각 간선은 둘 중 한 방향으로만 쓸 수 있기 때문에,
// 각 정점에 들어오는 간선의 수와 나가는 간선의 수가 같아야만 합니다.
// 이 외의 조건은 무향 그래프와 같습니다.
void getEulerCircuit(int here, vector<int>& circuit)
{
	for (int there = 0; there < adj.size(); there++)
	{
		while (adj[here][there] > 0)
		{
			adj[here][there]--;
			getEulerCircuit(there, circuit);
		}
	}
	circuit.push_back(here);
}
vector<int> getEulerOrCircuit()
{
	vector<int> circuit;
	// 우선 트레일을 찾아본다: 시작점이 존재하는 경우
	for (int i = 0; i < 26; i++)
	{
		if (outdegree[i] == indegree[i] + 1)
		{
			getEulerCircuit(i, circuit);
			return circuit;
		}
	}
	// 아니면 서킷이니, 간선에 인접한 아무 정점에서나 시작한다.
	for (int i = 0; i < 26; i++)
	{
		if (outdegree[i])
		{
			getEulerCircuit(i, circuit);
			return circuit;
		}
	}
	// 모두 실패한 경우 빈 배열 반환
	return circuit;
}
// 현재 그래프의 오일러 서킷/트레일 존재 여부를 확인한다.
bool checkEuler()
{
	// 예비 시작점과 끝점의 수
	int plus1 = 0, minus1 = 0;
	for (int i = 0; i < 26; i++)
	{
		int delta = outdegree[i] - indegree[i];
		// 모든 정점의 차수는 -1, 1 또는 0이어야 한다.
		if (delta < -1 || 1 < delta) return false;
		if (delta == 1) plus1++;
		if (delta == -1) minus1++;
	}
	// 시작점과 끝점은 각 하나씩 있거나 하나도 없어야 한다.
	return (plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0);
}
string solve(const vector<string>& words)
{
	makeGraph(words);
	// 차수가 맞지 않으면 실패!
	if (!checkEuler()) return "IMPOSSIBLE";
	// 오일러 서킷이나 경로를 찾아낸다
	vector<int> circuit = getEulerOrCircuit();
	// 모든 간선을 방문하지 못했으면 실패!
	if (circuit.size() != words.size() + 1) return "IMPOSSIBLE";

	// 아닌 경우 방문 순서를 뒤집은 뒤 간선들을 모아 문자열로 만들어 반환한다.
	reverse(circuit.begin(), circuit.end());
	string ret;
	for (int i = 1; i < circuit.size(); i++)
	{
		int a = circuit[i - 1], b = circuit[i];
		if (ret.size()) ret += " ";
		ret += graph[a][b].back();
		graph[a][b].pop_back();
	}
	return ret;
}
int T; vector<string> words;
int main(void)
{
	scanf("%d", &T);
	while (T--)
	{
		int N = 0;
		scanf("%d", &N);
		words.clear();
		//words.assign(N, 0);
		//words = vector<string>(N);
		for (int i = 0; i < N; i++)
		{
			string str;
			cin >> str; words.push_back(str);
		}
		cout << solve(words) << endl;				
	}
	return 0;
}
