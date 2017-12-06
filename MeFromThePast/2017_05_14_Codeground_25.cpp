#include <cstdio>
#include <cstdlib> // for abort
using namespace std;
int T; 
int counts;
int results;
long double MIN = 0x7fffffff; long double MAX = 1;
void dfs_min(int root, int c) // for MIN
{
		if (counts == c)
		{
			//if (root > MAX) MAX = root;
			if (root < MIN) MIN = root;
			return;
		}
		if ((root - 1) / 3 != 0 && (root - 1) / 3 != 1 && (root - 1) % 3 == 0)
		{
			int temp = (root - 1) / 3; int tempC = c;
			if(MIN == 0x7fffffff)
				dfs_min(temp, ++tempC);
		}
		if (root * 2 != 0)
		{
			int temp = root * 2;
			if(MIN == 0x7fffffff)
				dfs_min(temp, ++c);
		}
}
int main(void)
{
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		scanf("%d", &counts);
		for (int j = 0; j < counts; j++)
			MAX = MAX * 2;
		dfs_min(1, 0);
		printf("Case #%d\n", i);
		printf("%.0lf %.0lf\n", MIN, MAX);
		MAX = 1; MIN = 0x7fffffff;
	}
	return 0;
}