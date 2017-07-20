#include <iostream>
#include <fstream>
using namespace std;
int arr[2][10010];
int N;
int counts;
int Counts()
{
	for (int i = 1; i <= (N - 2); i++)
	{
		//cases for right turn... upright, rightdown, downleft, leftup
		if (arr[0][i] == arr[0][i + 1] && (arr[1][i] + 1) == arr[1][i + 1] && (arr[0][i] + 1) == arr[0][i + 2] && (arr[1][i] + 1) == arr[1][i + 2])
			counts++;
		if ((arr[0][i] + 1) == arr[0][i + 1] && (arr[1][i]) == arr[1][i + 1] && (arr[0][i] + 1) == arr[0][i + 2] && (arr[1][i] - 1) == arr[1][i + 2])
			counts++;
		if (arr[0][i] == arr[0][i + 1] && (arr[1][i] - 1) == arr[1][i + 1] && (arr[0][i] - 1) == arr[0][i + 2] && (arr[1][i] - 1) == arr[1][i + 2])
			counts++;
		if ((arr[0][i] - 1) == arr[0][i + 1] && (arr[1][i]) == arr[1][i + 1] && (arr[0][i] - 1) == arr[0][i + 2] && (arr[1][i] + 1) == arr[1][i + 2])
			counts++;
	}
	return counts;
}
int main(void)
{
	fstream filein;
	filein.open("robot.inp.txt");
	filein >> N;
	for (int i = 1; i <= N; i++)
	{
		filein >> arr[0][i] >> arr[1][i];
	}
	ofstream fileout;
	fileout.open("robot.out.txt", ios_base::out);
	fileout << Counts() << endl;
	return 0;
}