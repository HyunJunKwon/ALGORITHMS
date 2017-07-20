#include <cstdio>
using namespace std;
int T;
int N;
int trees;
int result;
int arr[200010];
int laser[200010];
void cal()
{
	//for (register int i = 1; i <= N; i++)
	//{
	//	for (register int j = 1; j <= N; j++)
	//	{
	//		if (arr[j] > laser[i])
	//		{
	//			result += arr[j] - laser[i];
	//			arr[j] = laser[i];
	//		}
	//		arr[j] += 1; // 자라는것
	//	}

	//}
	int i = 1; int j = 1; int counts = 1;
	while (j <= N)
	{
		if (counts > N)
		{
			if (j == N) break;
			j++; i = 1; counts = 1;
		}
		if (arr[i] > laser[j])
		{
			result += arr[i] - laser[j];
			arr[i] = laser[j] + 1;
		}
		else
			arr[i] += 1;
		counts++; i++;
	}
	
}
int main(void)
{
	scanf("%d", &T);
	for (register int i = 1; i <= T; i++)
	{
		scanf("%d", &N); //trees = N;
		for (register int j = 1; j <= N; j++)
		{
			scanf("%d", &arr[j]);
		}
		for(register int k = 1; k <= N; k++)
			scanf("%d", &laser[k]);
		cal();
		printf("Case #%d\n", i);
		printf("%d\n", result);
		result = 0;

	}
	return 0;
}