// Header files inclusion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declare
void Sort(char * string, int key, char ** str);

int main(void)
{
	// Local variables declare
	char * string = NULL;
	int key;
	int i;
	char ** str = NULL;// keyø° ¥Î«— pointer str
	
	// Statements
	scanf_s("%d", &key);
	str = (char **)malloc(sizeof(char *) * key);
	getchar();

	for (i = 0; i < key; i++)
	{
		string = (char *)malloc(sizeof(char) * 1001);
		gets(string);
		Sort(string, i, str);
	}
	for (i = 0; i < key; i++)
	{
		printf("%s\n", *(str + i));
	}

	free(string);
	free(str);
	return 0;
}
// Function definition
void Sort(char * string, int key, char ** str)
{
	// Local variables declare
	int i;
	int j;
	int len;
	char temp;

	// Statements
	len = strlen(string);
	for (i = 0; i < len; i += 2)
	{
		if ((i + 2) >= len)
			break;
		for (j = 0; j < (len - 1); j += 2)
		{
			if ((j + 2) >= len)
				break;
			if (*(string + j) > *(string + (j + 2)))
			{
				temp = *(string + (j + 2));
				*(string + (j + 2)) = *(string + j);
				*(string + j) = temp;
				temp = *(string + (j + 3));
				*(string + (j + 3)) = *(string + (j + 1));
				*(string + (j + 1)) = temp;
			}
			else if (*(string + j) == *(string + (j + 2)))
			{
				if (*(string + (j + 1)) > *(string + (j + 3)))
				{
					temp = *(string + (j + 2));
					*(string + (j + 2)) = *(string + j);
					*(string + j) = temp;
					temp = *(string + (j + 3));
					*(string + (j + 3)) = *(string + (j + 1));
					*(string + (j + 1)) = temp;
				}
			}
			else
				continue;
		}
	}
	*(str + key) = string;
}

