// Header files inclusion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declare
void MISPELL(char * string, int n, int key, char ** str);

int main(void)
{
	// Local variables declare
	char * string = NULL;
	int key;
	int i;
	int n;
	char ** str = NULL;// keyø° ¥Î«— pointer str

	// Statements
	scanf_s("%d", &key);
	str = (char **)malloc(sizeof(char *) * key);
	getchar();

	for (i = 0; i < key; i++)
	{
		string = (char *)malloc(sizeof(char) * 81);
		scanf_s("%d ", &n);
		gets(string);
		MISPELL(string, n, i, str);
	}
	for (i = 0; i < key; i++)
	{
		printf("%d %s\n", (i + 1), *(str + i));
	}

	free(string);
	free(str);

	return 0;
}
// Function definition
void MISPELL(char * string, int n, int key, char ** str)
{
	// Local variables declare
	int i = 0;
	int j = 0;
	int len;

	// Statements
	j = n - 1;
	len = strlen(string);

	for (j; j < (len - 1); j++)
	{	
		*(string + j) = *(string + (j + 1));
	}
	*(string + (len - 1)) = NULL;

	*(str + key) = string;
}

