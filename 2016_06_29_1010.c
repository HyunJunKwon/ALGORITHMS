// 1010번 문제 , 다리놓기

// Header files inclusion
#include <stdio.h>

// Function declare
long double combination(int siteA, int siteB);

int main(void)
{
	// Local variables declare
	int testcase;
	int siteA;
	int siteB;
	int i = 0;
	unsigned int result[100] = { 0,};
	
	// Statements
	scanf_s("%d", &testcase);
	
	while (i < testcase)
	{
		scanf_s("%d %d", &siteA, &siteB);
		result[i++] = combination(siteA, siteB);
	}

	i = 0;
	while (result[i] != 0)
	{
		printf("%d\n", result[i++]);
	}
	return 0;
}
// Function definition
long double combination(int siteA, int siteB)
{
	// Local variables declare
	long double result = 1;

	// Statements
	// 조합계산
	while (siteA > 0)
	{
		result *= (siteB--);
		result /= (siteA--);
	}
	
	return result;
}
