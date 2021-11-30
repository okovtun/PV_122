//AbstractBaseClass
#include<iostream>
using namespace std;

class Vehicle
{
	int speed;
public:
	virtual void move() const = 0;//Чисто виртуальный метод (pure virtual function),
	//именно этот метод и делает класс абстрактным
	//virtual type name(parameters) = 0;
};

class GroundVehicle :public Vehicle
{
	//Абстрактный класс
};

class WaterVehicle :public Vehicle
{
	//Абстрактный класс
};

class AirVehicle :public Vehicle
{
	int height;//Абстрактный класс
};

class Bike :public GroundVehicle
{
public:
	//Конкретный класс, поскольку он ОПРЕДЕЛЯЕТ чисто виртуальный метод move()
	void move() const
	{
		cout << "Мотоцикл едит на двух колосах" << endl;
	}
};

class Car :public GroundVehicle
{
public:
	void move()const
	{
		cout << "Машина едет на четырех колесах" << endl;
	}
};

class Boat :public WaterVehicle
{
public:
	void move()const
	{
		cout << "Лодка плывет" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Vehicle v;	//Невозможно создать экземпляр абстрактного класса
	//GroundVehicle gv;//Этот класс так же является абстрактным, 
	//поскольку он не определяет метод move
	Bike HD;
	HD.move();
	Car bmw;
	bmw.move();
	Boat boat;
	boat.move();
}