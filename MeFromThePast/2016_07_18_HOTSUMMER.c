// Header files inclusion
#include <stdio.h>
#include <stdlib.h>

// Function declare
void CHECKTOTALUSAGE(int goal_usage, int key, int * arr, char ** str);

int main(void)
{
	// Local variables declare
	int * arr = NULL;
	int key = 0;
	int i = 0;
	int goal_usage = 0;
	char ** str = NULL;// key에 대한 pointer str

	// Statements
	scanf_s("%d", &key);
	str = (char **)malloc(sizeof(char *) * key);
	getchar();

	for (i = 0; i < key; i++)
	{
		arr = (int *)malloc(sizeof(int) * 9);
		scanf_s("%d", &goal_usage);
		scanf_s("%d %d %d %d %d %d %d %d %d", (arr), (arr + 1), (arr + 2), (arr + 3), (arr + 4), (arr + 5), (arr + 6), (arr + 7), (arr + 8));
		// 숫자 배열에 숫자 받기 (건물에서 각각 사용량)
		CHECKTOTALUSAGE(goal_usage, i, arr, str);	
	}
	for (i = 0; i < key; i++)
	{
		printf("%s\n", *(str + i));
	}

	
	free(str);
	free(arr);

	return 0;
}
// Function definition
void CHECKTOTALUSAGE(int goal_usage, int key, int * arr, char ** str)
{
	// Local variables declare
	int i = 0;
	int j = 0;
	int total = 0;

	// Statements
	for (i = 0; i < 9; i++)
	{
		total += *(arr + i);
	}
	if (total > goal_usage)
		*(str + key) = "NO";
	else
		*(str + key) = "YES";
}

