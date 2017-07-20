#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int N;
vector<int> sequence;
vector<int> check;
int MAX;
int cur;
void Counts()
{
	for (int i = 1; i <= N; i++)
	{
		cur = sequence[i];
		for (int j = 2; j <= N; j++)
		{
			if (sequence[j] > cur)
			{
				check[i]++;
				cur = sequence[j];
			}
			else
				continue;
		}
	}
}
int main(void)
{
	fstream filein;
	filein.open("monosequence.inp.txt");
	filein >> N;
	sequence.assign(N + 1, 0);
	check.assign(N + 1, 1);
	check[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		filein >> sequence[i];
	}
	Counts();
	sort(check.begin(), check.end(), greater<int>());
	MAX = check[0];
	ofstream fileout;
	fileout.open("monosequence.out.txt", ios_base::out);
	fileout << MAX << endl;
	return 0;
}