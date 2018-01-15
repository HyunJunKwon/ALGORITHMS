/*
��������, �� �� ������ �������� �ٽ� ������ ���ؼ��� ���� ���� ������
�ݵ�� ������ �մϴ� -> ����Ŭ�� �������� �ʴ´�.
����Ŭ�� �������� �ʴ� �׷����� ��� ���� ���� ���谡 ���� ������
Ʈ���� ���� ���¸� ������ �ִ�. �̿� ���� �׷������� ��Ʈ ���� Ʈ����� �θ���.
����: 1. ��Ȯ�� V-1���� ����, 2. ����Ŭ�� �������� �ʴ´�, 3. �� ���� ���̸� �����ϴ� �ܼ� ��ΰ� ��Ȯ�� �ϳ� �ִ�.

��Ʈ ���� Ʈ���� �ٷ�� ���� ������ ����� ������ ���������κ��� dfs ����. ��������� ����
Ž�� ���д� Ʈ���� ���� �׷����� ������ �״�� ���� �����鼭 �θ� �ڽ� ���踦 ���� �Ϲ����� Ʈ���� �ȴ�.

Ʈ���� ���� ���� ã��
Ʈ���� �ּ� ���� ������ ã�� ���� ������ ����� Ʈ���� �� �Ʒ��������� �����ؼ� ���� �ö���� ��.
Ʈ���� ��Ʈ�� �����ؾ� ���� ���ƾ� ������ �̸� �˱� ���� ���� �ݸ�, Ʈ���� �� ��带 �������� ������ ���ϱ�� ����.
1. �� ���� �������� �ʽ��ϴ�.
2. �� ���� ��忡 ����, Ʈ���� �� �ؿ������� �ö���鼭 ������ ���� ���� ���θ� �����մϴ�.
	a) �ڱ� �ڼ� �� ���� ��������� ���� ��尡 �ϳ��� �ִٸ� ���� ��带 �����դ���.
	b) �� ���� ��� ���� ��带 �������� �ʽ��ϴ�.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<bool> visited; vector<vector<int> > adj;
int G, H; int installed;
const int UNWATCHED = 0; const int WATCHED = 1; const int INSTALLED = 2;
/*
�̹� dfs�� Ư¡: return ���� int�̴�.
leaf node���� �İ��� �� node���� ���¸� Ȯ���Ѵ� UNWATCHED��ȯ
�׸��� �� ���� node������ UNWATCHED�� ++�Ǿ� �Ⱥ��̴°� �ϳ� �ִٴ� �� �˰Եȴ�.

*/
int dfs(int here) 
{
	// �� ��忡���� �ڽ� ����� ����
	int children[3] = { 0, 0, 0 }; // UNWATCHED, WATCHED, INSTALLED
	visited[here] = true;
	for (int i = 0; i < adj[here].size(); i++) 
	{
		int next = adj[here][i];
		if (!visited[next]) 
			children[dfs(next)]++;
	}
	/*
	������ dfs �����ϰ�
	���������� ��ȯ�� ���ǵ� �ؿ� �ɾ��ش�.
	��ȯ�ϴ� ��: ���ϴ°�. (ī�޶��� ����)
	*/
	// �ڼ� ��� �� ���õ��� �ʴ� ��尡 ���� ��� ī�޶� ��ġ 
	// �Ⱥ��̴°� �ִ°� ���̴°� �ִ°ź��� �켱��
	if (children[UNWATCHED]) 
	{ // �ڽ��� �Ⱥ�������?
		installed++;
		return INSTALLED;
	}
	// �ڼ� ��� �� ī�޶� ��ġ�� ��尡 ���� ��� ��ġ�� �ʿ� ����
	if (children[INSTALLED]) 
		return WATCHED;
	return UNWATCHED;
}
void installCamera() 
{
	installed = 0;
	visited = vector<bool>(G, false);
	for (int i = 0; i < G; i++) // ��� ������ dfs�� �ƴ� �и��� componentã�� ������
	{
		// visited�� 0�̸� ������ dfs���� 1�̸� 
		if (!visited[i] && dfs(i) == UNWATCHED) // visited�� 1�̸� �ٷ� ���� 0�̸� dfs�� ����
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
		adj.assign(G, vector<int>()); // G������ �Ҵ��س���
		while (H--) 
		{
			int inGallery, outGallery;
			scanf("%d %d", &outGallery, &inGallery);
			adj[outGallery].push_back(inGallery);
			adj[inGallery].push_back(outGallery); // ��������Ʈ!!!!
			// �̰� adj = vector<vector<int> >(26, vector<int>(26, 0)); �̷��� �ϸ� ���
		}
		installCamera();
		printf("%d\n", installed);
	}
	return 0;
}
