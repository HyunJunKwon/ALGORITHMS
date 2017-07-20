#include <iostream>

using namespace std;

//����04-1
/*
class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	void InitMembers(int price, int num, int money)
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	int SaleApples(int money)
	{
		if (money < 0)
		{
			cout << "�߸��� ������ ���޵Ǿ� �ǸŸ� ����մϴ�." << endl;
			return 0;
		}
		int num = money / APPLE_PRICE; // �� �� �ִ� ����
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult() const
	{
		cout << "���� ���: " << numOfApples << endl;
		cout << "�Ǹ� ����: " << myMoney << endl << endl;
	}
};
class FruitBuyer
{
	int myMoney;
	int numOfApples;
public:
	void InitMembers(int money)
	{
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller &seller, int money) 
	{
		if (money < 0)
		{
			cout << "�߸��� ������ ���޵Ǿ� �ǸŸ� ����մϴ�." << endl;
			return;
		}
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult() const
	{
		cout << "���� �ܾ�: " << myMoney << endl;
		cout << "��� ����: " << numOfApples << endl << endl;
	}
};

int main(void)
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();

	return 0;
}*/

//Encaps1.cpp
/*class SinivelCap
{
public:
	void Take() const
	{
		cout << "�๰�� ��~ ���ϴ�." << endl;
	}
};
class SneezeCap
{
public:
	void Take() const
	{
		cout << "��ä�Ⱑ �ܽ��ϴ�." << endl;
	}
};
class SnuffleCap
{
public:
	void Take() const
	{
		cout << "�ڰ� �� �ո��ϴ�." << endl;
	}
};

class ColdPatient
{
public:
	void TakeSinivelCap(const SinivelCap &cap) const
	{
		cap.Take();
	}
	void TakeSneezeCap(const SneezeCap &cap) const
	{
		cap.Take();
	}
	void TakeSnuffleCap(const SnuffleCap &cap) const
	{
		cap.Take();
	}
};

int main(void)
{
	SinivelCap scap;
	SneezeCap zcap;
	SnuffleCap ncap;

	ColdPatient sufferer;
	sufferer.TakeSinivelCap(scap);
	sufferer.TakeSneezeCap(zcap);
	sufferer.TakeSnuffleCap(ncap);
	return 0;
}*/

//Encaps2.cpp
/*class SinivelCap
{
public:
	void Take() const
	{
		cout << "�๰�� ��~ ���ϴ�." << endl;
	}
};
class SneezeCap
{
public:
	void Take() const
	{
		cout << "��ä�Ⱑ �ܽ��ϴ�." << endl;
	}
};
class SnuffleCap
{
public:
	void Take() const
	{
		cout << "�ڰ� �� �ո��ϴ�." << endl;
	}
};

class CONTAC600
{
private:
	SinivelCap sin;
	SneezeCap sne;
	SnuffleCap snu;
public:
	void Take() const
	{
		sin.Take();
		sne.Take();
		snu.Take();
	}
};
class ColdPatient
{
public:
	void TakeCONTAC600(const CONTAC600 &cap) const
	{
		cap.Take();
	}
};

int main(void)
{
	CONTAC600 cap;
	ColdPatient sufferer;

	sufferer.TakeCONTAC600(cap);
	return 0;
}*/

//����04-2
/*class Point
{
private:
	int xpos;
	int ypos;
public:
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};
class Circle
{
private:
	int xpos;
	int ypos;
	int radius;
public: 
};
class Ring
{
private:
public:
	void Init(int x)
};

int main(void)
{
	Ring ring;
	return 0;
}
*/

//Constructor1.cpp
/*class SimpleClass
{
private:
	int num1;
	int num2;
public:
	SimpleClass()
	{
		num1 = 0;
		num2 = 0;
	}
	SimpleClass(int n)
	{
		num1 = n;
		num2 = 0;
	}
	SimpleClass(int n1, int n2)
	{
		num1 = n1;
		num2 = n2;
	}
	void ShowData() const
	{
		cout << num1 << ' ' << num2 << endl;
	}
};
int main(void)
{
	SimpleClass sc1;
	sc1.ShowData();

	SimpleClass sc2(100);
	sc2.ShowData();

	SimpleClass sc3(100, 200);
	sc3.ShowData();
	return 0;
}*/

//FruitSaleSim2.cpp
/*class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	FruitSeller(int price, int num, int money)
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult() const
	{
		cout << "���� ���: " << numOfApples << endl;
		cout << "�Ǹ� ����: " << myMoney << endl << endl;
	}
};
class FruitBuyer
{
private:
	int myMoney;
	int numOfApples;
public:
	FruitBuyer(int money)
	{
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller &seller, int money)
	{
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult() const
	{
		cout << "���� �ܾ�: " << myMoney << endl;
		cout << "��� ����: " << numOfApples << endl << endl;
	}
};

int main(void)
{
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000);

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();
	return 0;
}*/

//