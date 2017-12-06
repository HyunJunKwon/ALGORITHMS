#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int P; int M;
vector<int> N;
vector<int> S;
void Counts()
{
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= P; j++)
		{
			if (S[i] > N[j])
				continue;
			else if (S[i] <= N[j])
			{
				S[i] = j;
				break;
			}
		}
	}
}
int main(void)
{
	fstream filein;
	filein.open("ball.inp.txt");
	filein >> P;
	N.assign(P + 1, 0);
	for (int i = 1; i <= P; i++)
	{
		filein >> N[i];
		N[i] = N[i - 1] + N[i];
	}
	filein >> M;
	S.assign(M + 1, 0);
	for (int i = 1; i <= M; i++)
	{
		filein >> S[i];
	}
	Counts();
	ofstream fileout;
	fileout.open("ball.out.txt", ios_base::out);
	for (int i = 1; i <= M; i++)
	{
		fileout << S[i] << endl;
	}
	return 0;
}