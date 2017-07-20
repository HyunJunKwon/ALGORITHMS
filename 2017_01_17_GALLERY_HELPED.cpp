#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<bool> VISITED;
vector<vector<int> > GRAPH;
int G, H;
int ans;

int dfs(int galleryNo) {
    int status[3] = { 0, 0, 0 }; // [0]: �� ���������� ���� [1]: ��ġ ���� [2] �������� ����
    
    VISITED[galleryNo] = true;
    for (int i=0; i<GRAPH[galleryNo].size(); i++) {
        int next = GRAPH[galleryNo][i];
        if (!VISITED[next]) {
            status[dfs(next)]++;
        }
    }
    
    if (status[0]) { // �ڽ��� �Ⱥ�������?
        ans++;
        return 1; // ��ġ�� ������ ����
    } else if (status[1]) { // Ȥ�� �ڽ��� ��ġ�߳�?
        return 2; // �������� ������ ���� (�̰� ���� ������ �ϴ°���?????)
    } else {
        return 0; // �װ� �ƴϸ� �� �������� ���·� ����
    }
}

void visitAllGallery() {
    for (int u=0;u<G; u++) {
        if(!VISITED[u] && dfs(u) == 0)
            ans++;
    }
}

int main(void) {
    int C;
    scanf("%d", &C);
    
    while(C--) {
        
        scanf("%d %d", &G, &H);
        
        VISITED.clear();
        VISITED.assign(G, false);
        
        GRAPH.clear();
        GRAPH.assign(G, vector<int>());
        
        while(H--) {
            int inGallery, outGallery;
            scanf("%d %d", &outGallery, &inGallery);
            
            GRAPH[outGallery].push_back(inGallery);
            GRAPH[inGallery].push_back(outGallery);
        }
        ans = 0;
        visitAllGallery();
        printf("%d\n", ans);
    }
    return 0;
}