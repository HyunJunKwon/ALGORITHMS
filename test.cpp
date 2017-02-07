#include <iostream>

using namespace std;
	int arr[1000][1000];
int main (void)
{
//	int arr[1000][1000];
	
	for(int i = 0; i < 1000; i++)
	{
		for(int j = 0; j < 1000; j++)
		{
			arr[i][j] = 0;
		}
		
	}
	
		for(int i = 0; i < 1000; i++)
	{
		for(int j = 0; j < 1000; j++)
		{
			//cout << arr[i][j];
		}
		cout << endl;
		
	}
	return 0;
}
