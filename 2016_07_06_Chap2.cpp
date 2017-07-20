// Chapter 2

// Header files inclusion
#include <iostream>

using namespace std;

// 02-1
// 巩力 1
/*int func1(int &ref1);
int func2(int &ref2);

int main(void)
{
	int num = 10;
	cout << func1(num) << endl;
	cout << func2(num) << endl;
	return 0;
}
int func1(int &ref1)
{
	return (++ref1);
}
int func2(int &ref2)
{
	return (-ref2);
}*/

// 巩力3

/*void SwapPointer(int * (&pref1), int * (&pref2))
{
	int * ptr = pref1;
	pref1 = pref2;
	pref2 = ptr;
}*/

// 巩力 02-2
/*
int main(void)
{
	const int num = 12;
	const int * ptr = &num;
	const int * (&pref) = ptr;
	
	cout << num << endl;
	cout << *ptr << endl;
	cout << *pref << endl;

	return 0;
}*/

/*#include <cstring>

char * MakeStrAdr(int len)
{
	// char * str = (char*)malloc(sizeof(char)*len);
	char * str = new char[len];
	return str;
}
int main(void)
{
	char * str = MakeStrAdr(20);
	strcpy(str, "I am so happy!");
	cout << str << endl;
	//free(str);
	delete[]str;
	return 0;
	return 0;
}*/

// 巩力 02-3
/*
// Struct definition
typedef struct __Point
{
	int xpos;
	int ypos;
}Point;

// Function declare
Point& PntAdder(const Point &p1, const Point &p2);

int main(void)
{
	// Statements
	Point * pptr1 = new Point;
	pptr1->xpos = 3;
	pptr1->ypos = 30;

	Point * pptr2 = new Point;
	pptr2->xpos = 7;
	pptr2->ypos = 70;

	Point &pref = PntAdder(*pptr1, *pptr2);
	cout << "[" << pref.xpos << ", " << pref.ypos << "]" << endl;

	delete pptr1;
	delete pptr2;
	delete &pref;
	return 0;
}
// Functions definition
Point& PntAdder(const Point &p1, const Point &p2)
{
	// Local variables declare
	Point * pptr = new Point;

	// Statements
	pptr->xpos = p1.xpos + p2.xpos;
	pptr->ypos = p1.ypos + p2.ypos;
	return *pptr;
}*/

// 巩力 02-4
// 巩力2
/*
// Header files inclusion
#include <ctime>
#include <cstdlib>

int main(void)
{
	// Local variables declare

	// Statements
	srand(time(NULL));

	for (int i = 0; i < 5; i++)
	{
		cout << rand() % 100 << endl;
	}
	return 0;
}*/