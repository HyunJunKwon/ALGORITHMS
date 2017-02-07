// Header files inclusion
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declare
void Find(int x1, int x2, int x3, int y1, int y2, int y3, int i, int * arr_x, int * arr_y);

int main(void)
{
	// Local variables declare
	int x1, x2, x3, y1, y2, y3;
	int * arr_x;
	int * arr_y;
	int key;
	int i;

	// Statements
	scanf_s("%d", &key);
	arr_x = (int *)malloc(sizeof(int) * key);
	arr_y = (int *)malloc(sizeof(int) * key);

	for (i = 0; i < key; i++)
	{
		scanf_s("%d %d", &x1, &y1);
		scanf_s("%d %d", &x2, &y2);
		scanf_s("%d %d", &x3, &y3);
		Find(x1, x2, x3, y1, y2, y3, i, arr_x, arr_y);
	}
	
	for (i = 0; i < key; i++)
	{
		printf("%d %d\n", *(arr_x + i), *(arr_y + i));
	}
	return 0;
}
// Function definition
void Find(int x1, int x2, int x3, int y1, int y2, int y3, int i, int * arr_x, int * arr_y)
{
	// Local variables declare
	double A;
	double B;
	double C;

	// Statements
	A = pow((double)(x1 - x2), 2.0) + pow((double)(y1 - y2), 2.0);
	B = pow((double)(x1 - x3), 2.0) + pow((double)(y1 - y3), 2.0);
	C = pow((double)(x2 - x3), 2.0) + pow((double)(y2 - y3), 2.0);

	if (A > B)
	{
		if ((A + B) == C)
		{
			*(arr_x + i) = x2 + x3 - x1;
			*(arr_y + i) = y2 + y3 - y1;
		}
		else
		{
			*(arr_x + i) = x1 + x2 - x3;
			*(arr_y + i) = y1 + y2 - y3;
		}
	}
	else if (A < B)
	{
		if ((A + B) == C)
		{
			*(arr_x + i) = x2 + x3 - x1;
			*(arr_y + i) = y2 + y3 - y1;
		}
		else
		{
			*(arr_x + i) = x1 + x3 - x2;
			*(arr_y + i) = y1 + y3 - y2;
		}
	}
	else if (A == B)
	{
		*(arr_x + i) = x2 + x3 - x1;
		*(arr_y + i) = y2 + y3 - y1;
	}
}