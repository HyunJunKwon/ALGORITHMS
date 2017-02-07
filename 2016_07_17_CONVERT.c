// Header files inclusion
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

// Define constants
#define KILOTOPOUNDS 2.2046
#define POUNDSTOKILO 0.4536
#define LITTERTOGALLON 0.2642
#define GALLONTOLITTER 3.7854

// Function declare
void CONVERSIONUNIT(char * string, double n, int key, double * arr, char ** str);

int main(void)
{
	// Local variables declare
	char * string = NULL;
	double * arr = NULL;
	int key;
	int i;
	double n;
	char ** str = NULL;// keyø° ¥Î«— pointer str

	// Statements
	scanf_s("%d", &key);
	str = (char **)malloc(sizeof(char *) * key);
	arr = (double *)malloc(sizeof(double) * key);
	getchar();

	for (i = 0; i < key; i++)
	{
		string = (char *)malloc(sizeof(char) * 3);
		scanf_s("%lf ", &n);
		gets(string);
		CONVERSIONUNIT(string, n, i, arr, str);
	}
	for (i = 0; i < key; i++)
	{
		printf("%d %.4lf %s\n", (i + 1), *(arr + i), *(str + i));
	}

	free(string);
	free(str);

	return 0;
}
// Function definition
void CONVERSIONUNIT(char * string, double n, int key, double * arr, char ** str)
{
	// Local variables declare
	int i = 0;
	int j = 0;
	int len;

	// Statements
	if (*(string + i) == 'k')
	{
		*(str + key) = "lb";
		*(arr + key) = n * KILOTOPOUNDS;
	}
	else if (*(string + i) == 'g')
	{
		*(str + key) = "l";
		*(arr + key) = n * GALLONTOLITTER;
	}
	else
	{
		++i;
		if (*(string + i) != '\0')
		{
			*(str + key) = "kg";
			*(arr + key) = n * POUNDSTOKILO;
		}
		else
		{
			*(str + key) = "g";
			*(arr + key) = n * LITTERTOGALLON;
		}
	}
}

