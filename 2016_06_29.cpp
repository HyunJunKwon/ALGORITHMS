// chapter 1. 
#include <iostream>

/*int main(void)
{
	int num = 20;

	std::cout << "HELLO WORLD!" << std::endl;
	std::cout << "HELLO " << "WORLD!" << std::endl;
	std::cout << num << ' ' << 'A';
	std::cout << ' ' << 3.14 << std::endl;
	return 0;
}*/
/*
int main(void)
{
	int val1;
	std::cout << "ù ��° �����Է�: ";
	std::cin >> val1;

	int val2;
	std::cout << "�� ��° �����Է�: ";
	std::cin >> val2;

	int result = val1 + val2;
	std::cout << "�������: " << result << std::endl;

	return 0;
}
*/
/*
int main(void)
{
	int val1, val2;
	int result = 0;
	std::cout << "�� ���� �����Է�: ";
	std::cin >> val1 >> val2;

	if (val1 < val2)
	{
		for (int i = val1 + 1; i < val2; i++)
			result += i;
	}
	else
	{
		for (int i = val2 + 1; i < val1; i++)
			result += i;
	}

	std::cout << "�� �� ������ ���� ��: " << result << std::endl;
	return 0;
}
*/

/*int main(void)
{
	char name[100];
	char lang[200];

	std::cout << "�̸��� �����Դϱ�? ";
	std::cin >> name;

	std::cout << "�����ϴ� ���α׷��� ���� �����ΰ���? ";
	std::cin >> lang;

	std::cout << "�� �̸��� " << name << "�Դϴ�.\n";
	std::cout << "���� �����ϴ� ���� " << lang << "�Դϴ�." << std::endl;
	return 0;
}*/

// ���� 01-1
//1
/*int main(void)
{
	int num1, num2, num3, num4, num5;
	int result = 0;

	std::cout << "1��° ���� �Է�: ";
	std::cin >> num1;
	std::cout << "2��° ���� �Է�: ";
	std::cin >> num2;
	std::cout << "3��° ���� �Է�: ";
	std::cin >> num3;
	std::cout << "4��° ���� �Է�: ";
	std::cin >> num4;
	std::cout << "5��° ���� �Է�: ";
	std::cin >> num5;

	result = num1 + num2 + num3 + num4 + num5;

	std::cout << "�հ�: " << result << std::endl;
	return 0;
}*/

// 2
/*int main(void)
{
	char name[10];
	char phonenum[15];

	std::cout << "�̸� �Է�: ";
	std::cin >> name;
	std::cout << "��ȭ��ȣ �Է�: ";
	std::cin >> phonenum;

	std::cout << "�̸�: " << name << std::endl;
	std::cout << "��ȭ��ȣ: " << phonenum << std::endl;

	return 0;
}*/

// 3
/*int main(void)
{
	int num;

	std::cout << "���ڸ� �Է� �� �ּ���: ";
	std::cin >> num;

	for (int i = 1; i < 10; i++)
	{
		std::cout << num << " X " << i << " = " << (num * i) << std::endl;
	}
	return 0;
}*/

// 4
/*int main(void)
{
	double money = 1;
	double totalmoney;

	while (money)
	{
		std::cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
		std::cin >> money;
		
		if (money == -1)
		{
			std::cout << "���α׷��� �����մϴ�.\n";
			break;
		}
		totalmoney = 50 + (money * 0.12);
		std::cout << "�̹� �� �޿�: " << totalmoney << std::endl;

	}
	return 0;
}*/


/*void MyFunc(void)
{
	std::cout << "MyFunc(void) called" << std::endl;
}
void MyFunc(char c)
{
	std::cout << "MyFunc(char c) called" << std::endl;
}
void MyFunc(int a, int b)
{
	std::cout << "MyFunc(int a, int b) called" << std::endl;
}

int main(void)
{
	MyFunc();
	MyFunc('A');
	MyFunc(12 ,13);
	return 0;
}*/

// ���� 01-2
/*void swap(int * num1, int * num2);
void swap(char * ch1, char * ch2);
void swap(double * db1, double * db2);

int main(void)
{
	int num1 = 20, num2 = 30;
	swap(&num1, &num2);
	std::cout << num1 << ' ' << num2 << std::endl;

	char ch1 = 'A', ch2 = 'Z';
	swap(&ch1, &ch2);
	std::cout << ch1 << ' ' << ch2 << std::endl;

	double db1 = 1.111, db2 = 5.555;
	swap(&db1, &db2);
	std::cout << db1 << ' ' << db2 << std::endl;

	return 0;
}
void swap(int * num1, int * num2)
{
	int  temp;
	temp = *num2;
	*num2 = *num1;
	*num1 = temp;
}
void swap(char * ch1, char * ch2)
{
	char  temp;
	temp = *ch2;
	*ch2 = *ch1;
	*ch1 = temp;
}
void swap(double * db1, double * db2)
{
	double  temp;
	temp = *db2;
	*db2 = *db1;
	*db1 = temp;
}*/
using namespace std;
int main(void)
{
	int a;
	int &b = a;

	a = 10;

	cout << a << "\n" << b << endl;


	return 0;
}