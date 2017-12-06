#include <iostream>

using namespace std;

long long temp[100];

long long fib(int num)
{
	if(num == 1 || num == 0)
		return temp[num] = 1;
	if(temp[num] != 0)
		return temp[num];
	else
	{
	  	temp[num] = (fib(num-1) + fib(num-2));
		return temp[num];
	}
	
}

int main (void)
{
	//int num = 0;
	
	cout << fib(50);
	
	return 0;
}
