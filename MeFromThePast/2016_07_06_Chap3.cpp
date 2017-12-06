//Chapter 3.

// Header files inclusion
#include "Car.h"

/*
namespace CAR_CONST
{
	enum
	{
		ID_LEN  = 20,
		MAX_SPD  = 200,
		FUEL_STEP  = 2,
		ACC_STEP  = 10,
		BRK_STEP  = 10
	};
}

struct Car
{

	char gammerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;


	inline void ShowCarState();
	inline void Accel();
	inline void Break();
	
};
void Car::ShowCarState()
{
	cout << "소유자ID: " << gammerID << endl;
	cout << "연료량: " << fuelGauge << endl;
	cout << "현재속도: " << curSpeed << "KM/S" << endl << endl;
}
void Car::Accel()
{
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge = CAR_CONST::FUEL_STEP;

	if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
	{
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}

	curSpeed += CAR_CONST::ACC_STEP;
}
void Car::Break()
{
	if (curSpeed < CAR_CONST::BRK_STEP)
	{
		curSpeed = 0;
		return;
	}

	curSpeed = CAR_CONST::BRK_STEP;
}
int main(void)
{
	Car run99 = { "run 99", 100, 0 };
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();

	Car sped77 = { "sped77", 100, 0 };
	sped77.Accel();
	sped77.Break();
	sped77.ShowCarState();
	return 0;
}*/

//문제 03-1
/*struct Point
{
	int xpos;
	int ypos;

	void MovePos (int x, int y)
	{
		xpos += x;
		ypos += y;
	}
	void AddPoint(const Point &pos)
	{
		xpos += pos.xpos;
		ypos += pos.ypos;
	}
	void ShowPosition()
	{
		cout << "[ " << xpos << " , " << ypos << " ]" << endl;
	}
};

int main(void)
{
	Point pos1 = { 12, 4 };
	Point pos2 = { 20 , 30 };

	pos1.MovePos(-7, 10);
	pos1.ShowPosition();

	pos1.AddPoint(pos2);
	pos1.ShowPosition();
	return 0;
}*/


/*
namespace CAR_CONST
{
	enum
	{
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}

class Car
{
private:
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;
public:
	void InitMembers(char * ID, int fuel);
	void ShowCarState();
	void Accel();
	void Break();
};
int main(void)
{
	Car run99;
	run99.InitMembers("run99", 100);
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();

	return 0;
}
*/

/*#include "Cal.h"

int main(void)
{
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;

	cal.ShowOpCount();
	return 0;
}*/

