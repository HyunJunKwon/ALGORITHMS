#include <cstdio>
#include <vector>
using namespace std;
int disLimit; int shopNum; int result; int time; int totalDis;
vector<int> shop;
vector<int> dis;
void DFS(int num)
{
	int temp;
	if (num >= shopNum + 1)
		return;

	if()
}
int main(void)
{
	scanf("%d", &disLimit);
	scanf("%d", &shopNum);
	shop.assign((shopNum + 2), 0);
	dis.assign((shopNum + 1), 0);
	DFS(0);

	return 0;
}