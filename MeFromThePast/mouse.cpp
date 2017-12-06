#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int arr[110][110];
int temp[110][110];
int N; int M;
int MAX;
int dp(int row, int col)
{
	int next_row;
	int next_col;
	if (temp[row][col] != 0)
	{
		return temp[row][col];
	}
	if (col == M)
	{
		temp[row][col] = arr[row][col];
		return temp[row][col];
	}
	else
	{
		next_row = row - 1; next_col = col + 1; // for up-right direction
		if (next_row > 0 && next_row <= N && next_col > 0 && next_col <= M)
		{
			temp[row][col] = max(temp[row][col], (dp(next_row, next_col) + arr[row][col]));
		}
		next_row = row; next_col = col + 1; // for right direction
		if (next_row > 0 && next_row <= N && next_col > 0 && next_col <= M)
		{
			temp[row][col] = max(temp[row][col], (dp(next_row, next_col) + arr[row][col]));
		}
		next_row = row + 1; next_col = col + 1; // for down-right direction
		if (next_row > 0 && next_row <= N && next_col > 0 && next_col <= M)
		{
			temp[row][col] = max(temp[row][col], (dp(next_row, next_col) + arr[row][col]));
		}
	}
	return temp[row][col];

}
int main(void)
{
	fstream filein;
	filein.open("mouse.inp.txt");
	filein >> N;
	filein >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			filein >> arr[i][j];
		}
	}
	memset(temp, 0, 110 * 110);
	for (int i = 1; i <= N; i++)
	{
		int t = dp(i, 1);
		if (MAX < t) MAX = t;
	}
	ofstream fileout;
	fileout.open("mouse.out.txt", ios_base::out);
	fileout << MAX << endl;
	return 0;
}