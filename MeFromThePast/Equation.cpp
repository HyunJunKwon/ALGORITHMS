#include <iostream>
#include <fstream>
using namespace std;
int arr[4];
int counts;
int Counts()
{
	for (int i = 1; i <= 2; i++)
	{
		if (arr[i] != arr[i + 1])
			counts++;
	}
	if (arr[1] != arr[3])
		counts++;
	return counts;

}
int main(void)
{
	fstream filein;
	filein.open("equation.inp.txt");
	for (int i = 1; i < 4; i++)
	{
		filein >> arr[i];
	}
	ofstream fileout;
	fileout.open("equation.out.txt", ios_base::out);
	fileout << Counts() << endl;
	return 0;
}