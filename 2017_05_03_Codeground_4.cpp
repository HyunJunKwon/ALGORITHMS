#include <cstdio>
#include <cmath>
using namespace std;
#define PI 3.141592
int T;
int N;
double result;
int DisInfo[7]; // for distance info
double XY[10010][2]; // for location of x,y
double temp[10010]; // for results
void GetProportion()
{
	for (int i = 1; i <= N; i++)
	{
		if (DisInfo[1] > temp[i])
			temp[i] = 50;
		else if (DisInfo[2] < temp[i] && DisInfo[3] > temp[i])
			temp[i] = 3;
		else if (DisInfo[4] < temp[i] && DisInfo[5] > temp[i])
			temp[i] = 2;
		else if (20000 < temp[i])
			temp[i] = 0;
		else
			temp[i] = 1;
	}
}
void GetDegreeResult()
{
	for (int i = 1; i <= N; i++)
	{
		if (temp[i] == 50)
			continue;
		double tempdeg = (atan(XY[i][1] / XY[i][0]) * (180.0 / PI));// / 9.0;
		if (XY[i][0] < 0 && XY[i][1] > 0) tempdeg = 180 + tempdeg;// 2»çºÐ¸é
		else if (XY[i][0] < 0 && XY[i][1] < 0) tempdeg = 180 + tempdeg; // 3
		else if (XY[i][0] > 0 && XY[i][1] < 0) tempdeg = 360 + tempdeg;
		tempdeg /= 9.0;
		if (tempdeg < 1 && XY[i][0] > 0) temp[i] = temp[i] * 6;
		else if(tempdeg < 1 && XY[i][0] < 0) temp[i] = temp[i] * 11;
		else if (tempdeg > 1 && tempdeg < 3) temp[i] = temp[i] * 13;
		else if (tempdeg > 3 && tempdeg < 5) temp[i] = temp[i] * 4;
		else if (tempdeg > 5 && tempdeg < 7) temp[i] = temp[i] * 18;
		else if (tempdeg > 7 && tempdeg < 9) temp[i] = temp[i] * 1;
		else if (tempdeg > 9 && tempdeg < 11) temp[i] = temp[i] * 20;
		else if (tempdeg > 11 && tempdeg < 13) temp[i] = temp[i] * 5;
		else if (tempdeg > 13 && tempdeg < 15) temp[i] = temp[i] * 12;
		else if (tempdeg > 15 && tempdeg < 17) temp[i] = temp[i] * 9;
		else if (tempdeg > 17 && tempdeg < 19) temp[i] = temp[i] * 14;
		else if (tempdeg > 19 && tempdeg < 21) temp[i] = temp[i] * 11;
		else if (tempdeg > 21 && tempdeg < 23) temp[i] = temp[i] * 8;
		else if (tempdeg > 23 && tempdeg < 25) temp[i] = temp[i] * 16;
		else if (tempdeg > 25 && tempdeg < 27) temp[i] = temp[i] * 7;
		else if (tempdeg > 27 && tempdeg < 29) temp[i] = temp[i] * 19;
		else if (tempdeg > 29 && tempdeg < 31) temp[i] = temp[i] * 3;
		else if (tempdeg > 31 && tempdeg < 33) temp[i] = temp[i] * 17;
		else if (tempdeg > 33 && tempdeg < 35) temp[i] = temp[i] * 2;
		else if (tempdeg > 35 && tempdeg < 37) temp[i] = temp[i] * 15;
		else if (tempdeg > 37 && tempdeg < 39) temp[i] = temp[i] * 10;
		else if (tempdeg > 39 && tempdeg < 41) temp[i] = temp[i] * 6;
		
	}
	for (int i = 1; i <= N; i++)
	{
		result += temp[i];
	}
}
int main(void)
{	
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		scanf("%d %d %d %d %d", &DisInfo[1], &DisInfo[2], &DisInfo[3], &DisInfo[4], &DisInfo[5]);
		scanf("%d", &N);
		for (int k = 1; k <= N; k++)
		{
			scanf("%lf %lf", &XY[k][0], &XY[k][1]);
			temp[k] = sqrt(pow(XY[k][0], 2.0) + pow(XY[k][1], 2.0));
		}
		GetProportion();
		GetDegreeResult();
		printf("Case #%d\n", i);
		printf("%.0f\n", result);
	}
	
	return 0;
}