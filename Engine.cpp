#include "Engine.h"

Engine::Engine()
{
}

Engine::Engine(int horsePower, int torque, int noCylinders, float capacity, bool isHybrid, std::string series, Fuel fuel):noCylinders(noCylinders),capacity(capacity),isHybrid(isHybrid), series(series)
{
	setHorsePower(horsePower);
	setTorque(torque);
	this->fuel = fuel;
}

Engine& Engine::operator=(const Engine& e)
{
	if (this != &e) {
		this->horsePower = e.horsePower;
		this->torque = e.torque;
		this->noCylinders = e.noCylinders;
		this->capacity = e.capacity;
		this->isHybrid = e.isHybrid;
		this->series = e.series;
		this->fuel = e.fuel;
	}
	return *this;
}

int Engine::getHorsePower()
{
	return this->horsePower;
}

int Engine::getTorque()
{
	return this->torque;
}

int Engine::getNoCylinders()
{
	return this->noCylinders;
}

float Engine::getCapacity()
{
	return this->capacity;
}

bool Engine::getIsHybrid()
{
	return this->isHybrid;
}

std::string Engine::getSeries()
{
	return this->series;
}

Fuel Engine::getFuel()
{
	return this->fuel;
}

void Engine::setHorsePower(int newHorsePower)
{
	if (newHorsePower > 50) {
		this->horsePower = newHorsePower;
	}
	else {
		throw std::exception("Cannot set this value for horse power");
	}
}

void Engine::setTorque(int newTorque)
{
	if (newTorque < 100) {
		throw std::exception("Cannot set this value for torque");
	}
	else {
		this->torque = newTorque;
	}
}

void Engine::operator+=(int value)
{
	if (value > 0) {
		this->horsePower += value;
	}
	else {
		throw std::exception("Cannot add a negative value for power");
	}
}

Engine::operator int()
{
	return this->horsePower;
}

float Engine::operator()() {
	return float(horsePower) / capacity;
}

bool Engine::operator==(const Engine& e) {
	return this->torque == e.torque;
}

void operator<<(std::ostream& out,const Engine& e)
{
	out << std::endl << "Engine puts out: " << e.horsePower << "hp and " << e.torque << "nM of torque";
	out << std::endl << "It has: " << e.noCylinders << " cylinders";
	out << std::endl << "Capacity is: " << e.capacity << "L";
	if (e.isHybrid == true) {
		out << std::endl << "Hybrid: Yes";
	}
	else {
		out << std::endl << "Hybrid: No";
	}
	out << std::endl << "Engine series: " << e.series;
	out << std::endl << "It's running using: ";
	e.fuel == 0 ? out << "petrol fuel" : out << "diesel fuel";
}


