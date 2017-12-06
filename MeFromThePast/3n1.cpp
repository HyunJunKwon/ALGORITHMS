#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int K;
unsigned long long min, max;
void dfs(int cnt, unsigned long long tmp) 
{
	if (cnt == K) 
	{
		if (tmp < min) 
		{
			min = tmp;
		}
		if (tmp > max) 
		{
			max = tmp;
		}
		return;
	}
	dfs(cnt + 1, tmp * 2);
	if (tmp % 2 == 0 && (tmp - 1) % 3 == 0 && (tmp - 1) / 3 != 1) 
	{
		dfs(cnt + 1, (tmp - 1) / 3);
	}
}
int main(void)
{
	fstream filein;
	filein.open("3n1.inp.txt");
	filein >> K;
	min = (unsigned long long)pow(2.0, 63.0), max = 0;
	dfs(0, 1);
	ofstream fileout;
	fileout.open("3n1.out.txt", ios_base::out);
	fileout << min << " " << max << endl;
	return 0;
}