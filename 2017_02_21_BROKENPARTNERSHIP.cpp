#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

const int CHANG_GYU = 0;
const int UI_JONG = 1;
const double NOT_THINK_YET = -1.0;

double m, d;
char suggest[100 + 5];

double maxProfitForC() {
	// �ڿ������� üũ
	// �ڿ� ���� ���ڸ� ���� Ȯ���Ѵ�.
	// ������ Ž���ذ��� �� ���ڰ� �ٸ����ڷ� �ٲ�� ���� ��ġ�� ã�´�.
	// �� ��ġ���� ������ �󸶷� ���������� ����Ѵ�.
	// �� ���� �� ����(â�� or ����)�� �� ���� ���ӵ� ���ڿ����� �ּ��� ��������� �ϴ� �ݾ��̴�.
	// �� �� ������ ���� �ٸ� ���ڴ� ������ ��, �� ���� �����ϰ� �������� ������ �޾Ƶ����� ���� ���̴�.

	// �� ������� ó�� ��ġ���� �ݺ��Ѵ�.


	// ������ ������� �ּ��� ����ް� ���� �ݾ�
	double min[2] = { NOT_THINK_YET, NOT_THINK_YET };
	double invert_d = 1 - d * 0.01;

	int i = strlen(suggest) - 1; // ������ ��ġ
	int curChar;
	while (i >= 0) {
		curChar = suggest[i];
		// ���� ���ڰ� ���´ٸ� ��� �ݺ�, �Ǿտ� �������� �� ����
		if (i > 0 && curChar == suggest[i - 1]) {
			i--;
			continue;
		}
		switch (curChar) {
		case 'C':
			min[CHANG_GYU] = m * pow(invert_d, i);

			if (min[UI_JONG] != NOT_THINK_YET) {

				min[CHANG_GYU] -= min[UI_JONG];

			}
			break;

		case 'U':
			min[UI_JONG] = m * pow(invert_d, i);

			if (min[CHANG_GYU] != NOT_THINK_YET) {

				min[UI_JONG] -= min[CHANG_GYU];

			}
			break;

		default:
			printf("str input error\n");
			exit(-1);
		}
		i--;
	}
	return (min[CHANG_GYU] == NOT_THINK_YET) ? 0.0 : min[CHANG_GYU];
}



int main(void) {
	int testcase;
	scanf("%d", &testcase);

	while (testcase--) {
		scanf("%lf %lf", &m, &d);
		scanf("%s", suggest);
		//1kg �� ����
		m *= 10000.0;

		// �� ��° �ڸ����� �ݿø��Ͽ� ���
		printf("%.1lf\n", maxProfitForC());
	}

	return 0;
}