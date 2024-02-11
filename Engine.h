#pragma once
#include <string>
#include <iostream>

enum Fuel {PETROL,DIESEL};

class Engine
{
protected:
	int horsePower = 0;
	int torque = 0;
	int noCylinders = 0;
	float capacity = 0.0f;
	bool isHybrid = false;
	std::string series = "unknown";
	Fuel fuel = PETROL;
public:

	static const int MIN_NO_CYLINDERS = 3;

	//default constructor
	Engine();

	//constructor
	Engine(int horsePowerint, int torque, int noCylinders, float capacity, bool isHybrid, std::string series, Fuel fuel);

	//operator=
	Engine& operator=(const Engine& e);

	//getters
	int getHorsePower();

	int getTorque();

	int getNoCylinders();

	float getCapacity();

	bool getIsHybrid();

	std::string getSeries();

	Fuel getFuel();

	//setters
	void setHorsePower(int newHorsePower);

	void setTorque(int newTorque);

	//operator+= 
	void operator+=(int value);

	//operator cast
	operator int();

	//operator function
	float operator()();

	//operator==
	bool operator==(const Engine& e);

	//operator<<
	friend void operator<<(std::ostream& out,const Engine& e);

};

