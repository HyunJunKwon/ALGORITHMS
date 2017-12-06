#include <iostream>
#include <fstream>
using namespace std;
int N;
int arr[300010];
int MAX;
int temp;
int Counts()
{
	for (int i = 3; i <= N; (i += 3))
	{
		int k = 1;
		while (k <= N - (i - 1))
		{
			int temp_k = k;
			for (int j = temp_k; j <= (temp_k + i - 1); j++)
			{
				temp += arr[j];
			}
			if (MAX < temp) MAX = temp;
			temp = 0;
			k++;
		}
	}
	return MAX;
}
int main(void)
{
	fstream filein;
	filein.open("sequence.inp.txt");
	filein >> N;
	for (int i = 1; i <= N; i++)
	{
		filein >> arr[i];
	}
	ofstream fileout;
	fileout.open("sequence.out.txt", ios_base::out);
	fileout << Counts() << endl;
	return 0;
}