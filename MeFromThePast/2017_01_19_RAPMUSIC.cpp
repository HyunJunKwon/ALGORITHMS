#include <iostream>
#include <stdio.h>

using namespace std;

char * lyrics;
int N;
int result;

bool RAPMUSIC()
{
	
}
int main(void)
{
	int T = 0;
	
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);
		lyrics = new char[N];
		scanf("%s", lyrics);

		printf("Case #%d\n", T);
		if (RAPMUSIC() == true)
		{

			printf("%d", result);
		}
		else
		{
			printf("%d", 0);
		}

	}
	return 0;
}