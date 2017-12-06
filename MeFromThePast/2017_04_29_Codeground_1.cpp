/*
XOR 연산은 ^ 문제를 풀 때 왜? 를 생각하는 계기.
*/
#include <cstdio>

int T;
int N;
int result;
int num;
int main(void)
{
	scanf("%d", &T);
	for(int i = 1; i <= T; i++)
	{
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &num);
			result = result ^ num;
		}
		printf("Case #%d\n", i);
		printf("%d\n", result);
		result = 0;
	}
	return 0;
}