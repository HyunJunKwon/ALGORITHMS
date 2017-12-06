// 1002, 터렛
// Header file inclusion
#include <stdio.h>

// Function declare
int determine(int a, int b, int r1, int c, int d, int r2);

int main(void)
{
	// Local variables declare
	int T = 0;
	int i = 0;
	int a;
	int b;
	int r1;
	int c; 
	int d;
	int r2;
	int result[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };

	// Statements
	scanf_s("%d", &T);
	
	while (i < T)
	{
		scanf_s("%d %d %d %d %d %d", &a, &b, &r1, &c, &d, &r2);
		result[i] = determine(a, b, r1, c, d, r2);
		i++;
	}

	i = 0;
	while (result[i] != -1)
	{
		printf("%d\n", result[i]);
		i++;
	}
	return 0;
}
// Function definition
int determine(int a, int b, int r1, int c, int d, int r2)
{
	// Local variables declare
	int coefficient_x1 = 0;
	int coefficient_x2 = 0;
	int coefficient_y1 = 0;
	int coefficient_y2 = 0;
	int coefficient_r1 = 0;
	int coefficient_r2 = 0;
	int roots = 0;
	int A;
	int B;
	int R;

	// Statements 
	coefficient_x1 = 2 * a;
	coefficient_y1 = 2 * b;
	coefficient_r1 = ((a * a) + (b * b)) - (r1 * r1);
	coefficient_x2 = 2 * c;
	coefficient_y2 = 2 * d;
	coefficient_r2 = ((c * c) + (d * d)) - (r2 * r2);
	// 연립 이차방정식을 연립 일차로 줄여 계수 비교한다.

	A = coefficient_x1 - coefficient_x2;
	B = coefficient_y1 - coefficient_y2;
	R = coefficient_r1 - coefficient_r2;

	if (A == 0 && B  == 0 && R == 0)
		return -1;
	else if (((A  == 0) || (B == 0)) && (R != 0))
		return 2;
	else if (((A != 0) && (B != 0)) && (R != 0))
		return 1;
	else if (((A == 0) && (B == 0)) && (R != 0))
		return 0;

}